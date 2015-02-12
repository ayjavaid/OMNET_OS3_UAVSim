
package UAVModels;

import inet.transport.IUDP;
import GPSApp.IGPSApp;
import GPSAttackApp.IGPSAttackApp;
import inet.nodes.inet.*;


module UAVHost2 extends WirelessHost
{
    parameters:
        @display("i=device/UAV");
      
        int numGpsApps = default(1);
        int numGpsAttackApps = default(0);
		hasUdp = default(numGpsApps>0 || numGpsAttackApps>0);        
            
    submodules:
     
       gpsApp[numGpsApps]: <default("GPSApp")> like IGPSApp {  //default("UdpApp")
            parameters:
                @display("p=237,163,row,60");
        }
       gpsAttackApp[numGpsAttackApps]: <default("GPSAttackApp")> like IGPSAttackApp {  //default("UdpApp")
            parameters:
                @display("p=252,185,row,70");
        }
      
    connections:
    
    for i=0..numGpsApps-1 {
           gpsApp[i].gpsOut --> udp.appIn++;
           gpsApp[i].gpsIn <-- udp.appOut++;
       }
       for i=0..numGpsAttackApps-1 {
           gpsAttackApp[i].gpsOut --> udp.appIn++;
           gpsAttackApp[i].gpsIn <-- udp.appOut++;
       }
        
           
       
}
 
    