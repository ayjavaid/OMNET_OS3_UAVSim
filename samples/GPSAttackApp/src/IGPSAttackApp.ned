package GPSAttackApp;

//
// Template for UDP applications. It shows what gates a UDP app
// needs, to be able to be used in ~StandardHost etc.
//
moduleinterface IGPSAttackApp
{
    parameters:
        @display("i=block/app");
    gates:
        input gpsIn @labels(GPSControlInfo/up);
        output gpsOut @labels(GPSControlInfo/down);
}

