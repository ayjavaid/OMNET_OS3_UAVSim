package GPSApp;

//
// Template for GPS applications. It shows what gates a GPS app
// needs, to be able to be used in ~StandardHost etc.
//
moduleinterface IGPSApp
{
    parameters:
        @display("i=block/app");
    gates:
        input gpsIn @labels(GPSControlInfo/up);
        output gpsOut @labels(GPSControlInfo/down);
}

