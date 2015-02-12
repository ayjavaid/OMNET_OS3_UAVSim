//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package satellitemodel;

import inet.applications.IPingApp;
import GPSApp.IGPSApp;
import inet.applications.IUDPApp;
import inet.transport.IUDP;
import inet.networklayer.IManetRouting;
import inet.nodes.inet.NetworkLayer;
import inet.base.NotificationBoard;
import inet.battery.IBattery;
import inet.linklayer.IExternalNic;
import inet.linklayer.IWiredNic;
import inet.linklayer.IWirelessNic;
import inet.linklayer.loopback.LoopbackInterface;
import inet.mobility.contract.IMobility;
import inet.networklayer.common.InterfaceTable;
import inet.networklayer.ipv4.RoutingTable;
import inet.networklayer.ipv4.IPv4;
import inet.status.NodeStatus;
import inet.util.PcapRecorder;
import inet.nodes.inet.StandardHost;
import cni_os3.mobility.SatSGP4Mobility;
import cni_os3.base.Satellite;
//import UAVModels.IGPSWirelessNic;

//import GPSApp;

module StandardSatellite1 extends Satellite
{
    parameters:
        // @nodes();
        @node; //because of MobilityBase initialization
        @display("bgb=606,521");
        bool hasStatus = default(false);
        int numExtInterfaces = default(0);
        int numRadios = default(1);               // the number of radios in the router. by default no wireless
        int numPcapRecorders = default(0); // no of PcapRecorders.
        string routingFile = default("");
        bool forwardMulticast = default(false);
        //wlan[*].mgmtType = default("Ieee80211MgmtAdhoc");  // use adhoc management
        //string routingProtocol @enum("AODVUU","DYMOUM","DYMO","DSRUU","OLSR","OLSR_ETX","DSDV_2","Batman") = default("");
        int numPingApps = default(0);  			// no of PING apps. Specify the app types in INI file with pingApp[0..1].typename="PingApp" syntax
       // int numPingTestApps = default(0);
        int numUdpApps = default(0);
       // int numPingTestAppsSrc = default(1);		
        //bool proxyARP = default(true);       
        bool hasUdp = default(numUdpApps>0);        
        string udpType = default(firstAvailable("UDP","UDP_None"));
        bool IPForward = default(false);
        networkLayer.proxyARP = default(false);
    gates:
        input radioIn[numRadios] @directIn; // Added on 05/20/2014:6PM
        inout pppg[] @labels(PPPFrame-conn);
        inout ethg[] @labels(EtherFrame-conn);
    submodules:
        // optional mobility module. Required only if wireless cards are present

        interfaceTable: InterfaceTable {
            parameters:
                @display("p=407,69");
        }
        routingTable: RoutingTable {
            parameters:
                @display("p=45,178");
                IPForward = IPForward;
                forwardMulticast = forwardMulticast;
                routingFile = routingFile;
        }
        wlan[numRadios]: <default("Ieee80211Nic")> like IWirelessNic {
            parameters:
                @display("p=356,364;q=queue");
        }
        pcapRecorder[numPcapRecorders]: PcapRecorder {
            @display("p=78,321,r,10");
        }
        eth[sizeof(ethg)]: <default("EthernetInterface")> like IWiredNic {
            parameters:
                @display("p=429,389,row,60;q=txQueue");
        }
        ppp[sizeof(pppg)]: <default("PPPInterface")> like IWiredNic {
           parameters:
                @display("p=558,406,row,60;q=txQueue");
        }
        ext[numExtInterfaces]: <default("ExtInterface")> like IExternalNic {
            parameters:
                @display("p=217,421,row,10;q=txQueue;i=block/ifcard");
        }

        networkLayer: NetworkLayer {
            parameters:
                @display("p=356,284;q=queue");
        }
        lo0: LoopbackInterface {
            @display("p=78,406");
        }
        udpApp[numUdpApps]: <> like IUDPApp {  //default("UdpApp")
          parameters:
                @display("p=237,163,row,60");
        }
        udp: <udpType> like IUDP if hasUdp {
            parameters:
                @display("p=178,262");
        }
        pingApp[numPingApps]: <default("PingApp")> like IPingApp {
            parameters:
                @display("p=490,262");

        }
         
    connections allowunconnected:
        networkLayer.ifOut++ --> lo0.upperLayerIn;
        lo0.upperLayerOut --> networkLayer.ifIn++;
        for i=0..sizeof(radioIn)-1 {
            radioIn[i] --> { @display("m=s"); } --> wlan[i].radioIn;
            wlan[i].upperLayerOut --> networkLayer.ifIn++;
            wlan[i].upperLayerIn <-- networkLayer.ifOut++;
        }
      
        for i=0..sizeof(ethg)-1 {
            ethg[i] <--> { @display("m=s"); } <--> eth[i].phys;
            eth[i].upperLayerOut --> networkLayer.ifIn++;
            eth[i].upperLayerIn <-- networkLayer.ifOut++;
        }
       for i=0..sizeof(pppg)-1 {
           pppg[i] <--> { @display("m=s"); } <--> ppp[i].phys;
           ppp[i].upperLayerOut --> networkLayer.ifIn++;
            ppp[i].upperLayerIn <-- networkLayer.ifOut++;
        }
        for i=0..numExtInterfaces-1 {
            ext[i].upperLayerOut --> networkLayer.ifIn++;
            ext[i].upperLayerIn <-- networkLayer.ifOut++;
        }

       // for i=0..numgpsApps-1 {
         //   gpsApp[i].gpsOut --> udp.appIn++;
           // gpsApp[i].gpsIn <-- udp.appOut++;
       // }
        for i=0..numUdpApps-1 {
            udpApp[i].udpOut --> udp.appIn++;
            udpApp[i].udpIn <-- udp.appOut++;
        }
        udp.ipOut --> networkLayer.transportIn++ if hasUdp;
        udp.ipIn <-- networkLayer.transportOut++ if hasUdp;
        
        
            
      //  for i=0..numPingTestApps-1 {
       //     networkLayer.pingOut++ --> pingTestApp[i].pingIn;
       //     networkLayer.pingIn++ <-- pingTestApp[i].pingOut;
      //  }
        for i=0..numPingApps-1 {
            networkLayer.pingOut++ --> pingApp[i].pingIn;
            networkLayer.pingIn++ <-- pingApp[i].pingOut;
        }
       // for i=0..numPingTestAppsSrc-1 {
       //     networkLayer.pingOut++ --> pingTestAppSrc[i].pingIn;
        //    networkLayer.pingIn++ <-- pingTestAppSrc[i].pingOut;

       // }
       // networkLayer.transportOut++ --> manetrouting.from_ip if routingProtocol != "";
      //  networkLayer.transportIn++ <-- manetrouting.to_ip if routingProtocol != "";
}
