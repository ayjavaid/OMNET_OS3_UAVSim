
import inet.networklayer.autorouting.ipv4.IPv4NetworkConfigurator;
import UAVModels.AttackHost;
import UAVModels.UAVHost;
import inet.world.radio.ChannelControl;
import cni_os3.base.Satellite;
import cni_os3.base.MissionControlCenter;
import cni_os3.base.CNI_OS3;

network UAVNet
{
    parameters:
        int numAttackHosts;
        int numHosts;
        int numOfSats; // Number of satellites
        int numOfMCCs; // Number of Mission Control Centers

        @display("bgi=background_earth;bgb=2160,1080");

    submodules:
        host[numHosts]: UAVHost {
            parameters:
                //@display("r=,,#707070);//;p=250,58");
        }
        attackhost[numAttackHosts]: AttackHost {
            parameters:
        		//@display("r=,,#707070);//;p=250,58");
        }
        satellite[numOfSats]: Satellite {
            parameters:
                @display("p=80,150;r=10,,#707070;i=device/satellite_l");
        }
        MCC[numOfMCCs]: MissionControlCenter {
            parameters:
                @display("p=243,204;i=misc/building;r=10,,black");
        }
        channelControl: ChannelControl {
            parameters:
                numChannels = 2;
                @display("p=240,70;i=misc/sun");
        }
        configurator: IPv4NetworkConfigurator {
            config = xml("<config><interface hosts='*' address='192.168.x.x' netmask='255.255.0.0'/></config>");
            //@display("p=140,50");
        }
        cni_os3: CNI_OS3 {
            @display("p=80,70,i;i=old/bluebox");
        }
    connections allowunconnected:
}

