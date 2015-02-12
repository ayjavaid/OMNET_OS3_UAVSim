/*
 * AltHeadRefSys.cc
 *
 *  Created on: Aug 19, 2013
 *      Author: ahmad
 */

#include <iostream>
#include <string>

#include <omnetpp.h>

class AltHeadRefSys : public cSimpleModule
{
protected:
    virtual void handleMessage(cMessage *msg);

};

Define_Module(AltHeadRefSys);

void AltHeadRefSys::handleMessage(cMessage *msg)
{
    cGate *arrivalGate = msg->getArrivalGate();

    // process arriving message
    if (!strcmp(arrivalGate->getName(), "in"))
    {
        EV << "Processing Incoming message.\n";
        cMessage *DataAcqIn = new cMessage("Data");
        send(DataAcqIn,"out");
        return;
    }

    // Error
    else
        error("Unknown message type received.\n");
}
