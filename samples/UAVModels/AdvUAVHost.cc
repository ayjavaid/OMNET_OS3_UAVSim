/*
 * AdvUAVHost.cpp
 *
 *  Created on: Sep 8, 2013
 *      Author: ahmad
 */

#include <iostream>
#include <string>
#include <omnetpp.h>

class AdvUAVHost : public cSimpleModule {
protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(AdvUAVHost);

void AdvUAVHost::initialize()
{
    if (strcmp("in", getName()) == 0)
    {
        EV << "Sending initial message\n";
        cMessage *msg = new cMessage("Data");
        send(msg, "out");
    }
}

void AdvUAVHost::handleMessage(cMessage *msg)
{
    cGate *arrivalGate = msg->getArrivalGate();

    // process arriving message
    if (!strcmp(arrivalGate->getName(), "radioIn"))
    {
        ev << "Processing Incoming message inside the UAV.\n";
        cMessage *pkt = new cMessage("Video");
        send(pkt,"out");
        return;
    }

    // Error
    else
        error("Unknown message type received.\n");
}
