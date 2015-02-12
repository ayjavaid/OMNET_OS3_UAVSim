
package UAVModels;

import inet.networklayer.IManetRouting;
import inet.applications.IPingApp;
import inet.applications.ISCTPApp;
import inet.applications.ITCPApp;
import inet.applications.IUDPApp;
import inet.transport.ISCTP;
import inet.transport.ITCP;
import inet.transport.IUDP;
import inet.nodes.inet.WirelessHost;

module AttackHost extends WirelessHost
{
    parameters:
        @display("i=device/attacknode");
        wlan[*].mgmtType = default("Ieee80211MgmtAdhoc");  // use adhoc management
        string routingProtocol @enum("AODVUU","DYMOUM","DYMO","DSRUU","OLSR","OLSR_ETX","DSDV_2","Batman") = default("");  // used mobile routing protocol. see: inet.networklayer.manetrouting
        IPForward = default(true);
        int numPingTestApps = default(1); 

    submodules:
        manetrouting: <routingProtocol> like IManetRouting if routingProtocol != "" {
            //@display("p=522,307");
        }
        pingTestApp[numPingTestApps]: <default("PingTestApp")> like IPingApp {
            parameters:
                //@display("p=501,230");
                } 
    connections allowunconnected:
        for i=0..numPingTestApps-1 {
            networkLayer.pingOut++ --> pingTestApp[i].pingIn;
            networkLayer.pingIn++ <-- pingTestApp[i].pingOut;
            
        }
        networkLayer.transportOut++ --> manetrouting.from_ip if routingProtocol != "";
        networkLayer.transportIn++ <-- manetrouting.to_ip if routingProtocol != "";
        
}
    