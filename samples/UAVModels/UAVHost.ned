
package UAVModels;

import inet.networklayer.IManetRouting;
import inet.applications.IUDPApp;
import inet.transport.IUDP;
import GPSApp.IGPSApp;
import inet.nodes.inet.*;

module UAVHost extends WirelessHost
{
    parameters:
        @display("i=device/UAV");
        wlan[*].mgmtType = default("Ieee80211MgmtAdhoc");  // use adhoc management
        string routingProtocol @enum("AODVUU","DYMOUM","DYMO","DSRUU","OLSR","OLSR_ETX","DSDV_2","Batman") = default("");  // used mobile routing protocol. see: inet.networklayer.manetrouting
        IPForward = default(true); 
        int numgpsApps = default(0);
		//hasUdp = default(numgpsApps>0);        
        //string udpType = default(firstAvailable("UDP","UDP_None"));
        numRadios = default(1);
    submodules:
        manetrouting: <routingProtocol> like IManetRouting if routingProtocol != "" {
            //@display("p=522,307");
        }
        gpsApp[numgpsApps]: <default("GPSApp")> like IGPSApp {  //default("UdpApp")
            parameters:
                @display("p=237,163,row,60");
        }
        //udp: <udpType> like IUDP if hasUdp {
         //   parameters:
        //        @display("p=329,141");
        //}
    connections:
    
    for i=0..numgpsApps-1 {
           gpsApp[i].gpsOut --> udp.appIn++;
           gpsApp[i].gpsIn <-- udp.appOut++;
       }
        
       //udp.ipOut--> networkLayer.transportIn++ if hasUdp;
       //udp.ipIn <-- networkLayer.transportOut++ if hasUdp;
        
        networkLayer.transportOut++ --> manetrouting.from_ip if routingProtocol != "";
        networkLayer.transportIn++ <-- manetrouting.to_ip if routingProtocol != "";
}
 
    