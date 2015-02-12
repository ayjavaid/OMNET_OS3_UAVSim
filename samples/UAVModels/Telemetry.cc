/*
 * Telemetry.cpp
 *
 *  Created on: Aug 23, 2013
 *      Author: ahmad
 */

#include <iostream>
#include <omnetpp.h>

class Telemetry : public cSimpleModule{
protected:

    virtual void handleMessage(cMessage *msg);
};

Define_Module(Telemetry);

void Telemetry::handleMessage(cMessage *msg)
{
    cGate *arrivalGate = msg->getArrivalGate();

    // process arriving message
    if (!strcmp(arrivalGate->getName(), "in"))
    {
        EV << "Processing Incoming message inside the UAV.\n";
        cMessage *pkt = new cMessage("Data");
        send(pkt,"out");
        return;
    }

    // Error
    else
        error("Unknown message type received.\n");
}
