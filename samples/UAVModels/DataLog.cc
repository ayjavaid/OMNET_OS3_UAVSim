/*
 * DataLog.cpp
 *
 *  Created on: Aug 19, 2013
 *      Author: ahmad
 */

#include <iostream>
#include <string>
#include <omnetpp.h>

class DataLog : public cSimpleModule
{
protected:
    virtual void handleMessage(cMessage *msg);
};

Define_Module(DataLog);

void DataLog::handleMessage(cMessage *msg)
{
    cGate *arrivalGate = msg->getArrivalGate();

    // process arriving message
    if (!strcmp(arrivalGate->getName(), "in"))
    {
        EV << "Processing Incoming message in DataAcq.\n";
        delete msg;
        return;
    }
    // Error
    else
        error("Unknown message type received in DataAcq Module.\n");
}
