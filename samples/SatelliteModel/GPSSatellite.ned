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

import inet.transport.IUDP;
import GPSApp.IGPSApp;
//import inet.nodes.inet.*;

module GPSSatellite extends StandardSatellite
{
    parameters:
        @display("i=device/UAV");

        int numGpsApps = default(1);
        hasUdp = default(numGpsApps>0);

    submodules:
        gpsApp[numGpsApps]: <default("GPSApp")> like IGPSApp {  //default("UdpApp")
            parameters:
                @display("p=100,284,row,60");
        }

    connections:
        for i=0..numGpsApps-1 {
            gpsApp[i].gpsOut --> udp.appIn++;
            gpsApp[i].gpsIn <-- udp.appOut++;
        }



}
