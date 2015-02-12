/*
 * DataAcq.cpp
 *
 *  Created on: Aug 19, 2013
 *      Author: ahmad
 */


#include <iostream>
#include <string>

#include <omnetpp.h>

class DataAcq : public cSimpleModule
{
protected:
    virtual void handleMessage(cMessage *msg);

};

Define_Module(DataAcq);

void DataAcq::handleMessage(cMessage *msg)
{
    cGate *arrivalGate = msg->getArrivalGate();

    // process arriving message
    if (!strcmp(arrivalGate->getName(), "in"))
    {
        EV << "Processing Incoming message in DataAcq.\n";
        cMessage *pkt = new cMessage("Data");
        send(pkt,"out");
        return;
    }
    // Error
    else
        error("Unknown message type received in DataAcq Module.\n");
}
