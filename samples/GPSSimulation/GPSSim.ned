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

// Copyright Andreas Lewandowski / Brian Niehoefer

package GPSSimulation;

import satellitemodel.GPSSatellite;
import cni_os3.base.MissionControlCenter;
import inet.world.radio.ChannelControl;
import cni_os3.base.CNI_OS3;
import inet.networklayer.autorouting.ipv4.IPv4NetworkConfigurator;
import UAVModels.UAVHost2;
import inet.nodes.wireless.AccessPoint;
//
// Network SatSGP4 enables satellite movement on worldmap
//

network GPSSim
{
    parameters:
        int numOfSats; // Number of satellites
        int numOfMCCs; // Number of Mission Control Centers
        int numOfHost;
        int numOfAttackHost;
        // int numOfAccesspoint;
        @display("bgi=background_earth;bgb=2160,1080");

    submodules:
        satellite[numOfSats]: GPSSatellite {
            parameters:
                @display("p=94,274;r=10,,#707070;i=device/satellite_l");
        }
        host[numOfHost]: UAVHost2 {
            parameters:
                @display("p=289,274;i=device/pc2");
        }
        attackhost[numOfAttackHost]: UAVHost2 {
            parameters:
                @display("p=201,267;i=device/pc2");
        }
        accessPoint1: AccessPoint {
            @display("p=561,452");
        }
        accessPoint2: AccessPoint {
            @display("p=1714,412");
        }
        MCC[numOfMCCs]: MissionControlCenter {
            parameters:
                @display("p=256,160;i=misc/building;r=10,,black");
        }
        channelControl: ChannelControl {
            parameters:
                //playgroundSizeX = playgroundSizeX;
                //playgroundSizeY = playgroundSizeY; note: https://groups.google.com/forum/#!msg/omnetpp/iofWt9w-o7A/bRuaO3KrMfcJ
                //numChannels = 2;
                @display("p=243,46;i=misc/sun");
        }
        cni_os3: CNI_OS3 {
            @display("p=80,70,i;i=old/bluebox");
        }
        configurator: IPv4NetworkConfigurator {
            parameters:
                @display("p=76,150");
        }
        accessPoint3: AccessPoint {
            @display("p=1730,741");
        }
        accessPoint4: AccessPoint {
            @display("p=569,741");
        }
    connections allowunconnected:
}


