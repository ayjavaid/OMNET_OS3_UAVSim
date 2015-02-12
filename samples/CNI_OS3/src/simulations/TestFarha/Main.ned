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

package cni_os3.simulations.TestFarha;

import cni_os3.base.MissionControlCenter;
import cni_os3.base.Satellite;
import cni_os3.base.CNI_OS3;
import inet.world.radio.ChannelControl;

network Main
{
    parameters:
        @node;
        int numOfSats; // Number of satellites
        int numOfMCCs; // Number of Mission Control Centers
       
        
    submodules:
       	satellite[numOfSats]: Satellite {
            parameters:
                @display("i=device/pc3;p=178,62");         
        
        }
        
         MCC[numOfMCCs]: MissionControlCenter {
            parameters:
                @display("p=248,217;i=misc/building;r=10,,black");
        }
        
        cni_os3: CNI_OS3 {
            @display("p=80,70,i;i=old/bluebox");
        }
        channelControl: ChannelControl {
            parameters:
                 numChannels = 2;
                //@display("p=60,50");
        }

}

