import inet.networklayer.autorouting.ipv4.IPv4NetworkConfigurator;
import UAVModels.UAVHost;
import UAVModels.AttackHost;
import inet.world.radio.ChannelControl;

network Net80211
{
    parameters:
        int numHosts;
        int numAttackHosts; 
    submodules:
        host[numHosts]: UAVHost {
            parameters:
                //@display("r=,,#707070);//;p=250,58");
        }
        attackhost[numAttackHosts]: AttackHost {
        	parameters:
        		//@display("r=,,#707070);//;p=250,58");
        }	
        channelControl: ChannelControl {
            parameters:
                //@display("p=60,50");
        }
        configurator: IPv4NetworkConfigurator {
            config=xml("<config><interface hosts='*' address='192.168.x.x' netmask='255.255.0.0'/></config>");
            //@display("p=140,50");
        }
}

