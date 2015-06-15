
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

module UAVHost extends WirelessHost
{
    parameters:
        @display("i=device/UAV");
        wlan[*].mgmtType = default("Ieee80211MgmtAdhoc");  // use adhoc management
        string routingProtocol @enum("AODVUU","DYMOUM","DYMO","DSRUU","OLSR","OLSR_ETX","DSDV_2","Batman") = default("");  // used mobile routing protocol. see: inet.networklayer.manetrouting
        IPForward = default(true); 

    submodules:
        manetrouting: <routingProtocol> like IManetRouting if routingProtocol != "" {
            //@display("p=522,307");
        }
    connections:
        networkLayer.manetOut --> manetrouting.from_ip if routingProtocol != "";
        networkLayer.manetIn <-- manetrouting.to_ip if routingProtocol != "";
        
}
