
package UAVModels;

import inet.networklayer.IManetRouting;
import inet.applications.IPingApp;
import inet.util.PcapRecorder;
import inet.networklayer.ipv4.RoutingTable;
import inet.networklayer.common.InterfaceTable;
import inet.mobility.contract.IMobility;
import inet.linklayer.IWirelessNic;
import inet.base.NotificationBoard;


module AdvUAVHost
{
    parameters:
        @display("i=device/UAV");
        @node;  						   // @labels(node,ethernet-node,wireless-node);
        int numRadios = default(1);        // the number of radios in the UAV.
        int numPcapRecorders = default(0); // no of PcapRecorders.
        string mobilityType = default("LinearMobility");
        string routingFile = default("");
        bool IPForward = default(true);
        bool forwardMulticast = default(false);
        wlan[*].mgmtType = default("Ieee80211MgmtAdhoc");  // use adhoc management
        string routingProtocol @enum("AODVUU","DYMOUM","DYMO","DSRUU","OLSR","OLSR_ETX","DSDV_2","Batman") = default("");
        										// used mobile routing protocol. see: inet.networklayer.manetrouting
        int numPingApps = default(1);  			// no of PING apps. Specify the app types in INI file with pingApp[0..1].typename="PingApp" syntax
        int numPingTestApps = default(0);
        networkLayer.proxyARP = default(false);

    gates:
        input radioIn[numRadios] @directIn;
        //output out;

    submodules:
        DataAcq: DataAcq {
            @display("p=246,357");
        }
        AltHeadRefSys: AltHeadRefSys {
            @display("p=45,262");
        }
        NAV: NAV {
            @display("p=45,357");
        }
        Telemetry: Telemetry {
            @display("p=151,396");
        }
        UAVControl: UAVControl {
            @display("p=246,262");
        }
        DataLog: DataLog {
            @display("p=151,178");
        }
        manetrouting: <routingProtocol> like IManetRouting if routingProtocol != "" {
            @display("p=490,357");
        }
        notificationBoard: NotificationBoard {
            parameters:
                @display("p=45,105");
        }

        // optional mobility module. Required only if wireless cards are present
        mobility: <mobilityType> like IMobility if mobilityType != "" && numRadios > 0 {
            parameters:
                @display("p=45,28");
        }

        // network layer
        networkLayer: NetworkLayer {
            parameters:
                @display("p=356,284;q=queue");
        }

        routingTable: RoutingTable {
            parameters:
                @display("p=45,178");
                IPForward = IPForward;
                forwardMulticast = forwardMulticast;
                routingFile = routingFile;
        }

        // linklayer
        interfaceTable: InterfaceTable {
            parameters:
                @display("p=424,59");
        }

        pcapRecorder[numPcapRecorders]: PcapRecorder {
            @display("p=215,59");
        }

        wlan[numRadios]: <default("Ieee80211Nic")> like IWirelessNic {
            parameters:
                @display("p=356,396;q=queue");
        }

        pingApp[numPingApps]: <default("PingApp")> like IPingApp {
            parameters:
                @display("p=490,262");

        }
        pingTestApp[numPingTestApps]: <default("PingTestApp")> like IPingApp {
            parameters:
                @display("p=356,178");

        }

    connections allowunconnected:
        //connections within the Model
        DataAcq.out --> {  delay = 0.0001ms; } --> AltHeadRefSys.in;
        AltHeadRefSys.out[0] --> {  delay = 0.0001ms; } --> NAV.in;
        AltHeadRefSys.out[1] --> {  delay = 0.0001ms; } --> UAVControl.in[0];
        NAV.out --> {  delay = 0.0001ms; } --> UAVControl.in[1];
        Telemetry.out --> {  delay = 0.0001ms; } --> UAVControl.in[2];
        DataAcq.DataLog --> {  delay = 0.0001ms; } --> DataLog.in[0];
        AltHeadRefSys.DataLog --> {  delay = 0.0001ms; } --> DataLog.in[1];
        NAV.DataLog --> {  delay = 0.0001ms; } --> DataLog.in[2];
        Telemetry.DataLog --> {  delay = 0.0001ms; } --> DataLog.in[3];
        UAVControl.DataLog --> {  delay = 0.0001ms; } --> DataLog.in[4];


        // connections to network outside
        for i=0..sizeof(radioIn)-1 {
            radioIn[i] --> DataAcq.in[i];
            //radioIn[i] --> wlan[i].radioIn;
            UAVControl.out[i] --> wlan[i].radioIn;
            wlan[i].upperLayerOut --> networkLayer.ifIn++;
            wlan[i].upperLayerIn <-- networkLayer.ifOut++;
        }

        for i=0..numPingApps-1 {
            networkLayer.pingOut++ --> pingApp[i].pingIn;
            networkLayer.pingIn++ <-- pingApp[i].pingOut;

        }
        for i=0..numPingTestApps-1 {
            networkLayer.pingOut++ --> pingTestApp[i].pingIn;
            networkLayer.pingIn++ <-- pingTestApp[i].pingOut;

        }
        networkLayer.transportOut++ --> manetrouting.from_ip if routingProtocol != "";
        networkLayer.transportIn++ <-- manetrouting.to_ip if routingProtocol != "";

}
