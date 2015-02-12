//
// Copyright (C) 2004 Andras Varga
// Copyright (C) 2000 Institut fuer Telematik, Universitaet Karlsruhe
// Copyright (C) 2011 Zoltan Bojthe
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//


#ifndef __GPSAttackApp_H
#define __GPSAttackApp_H

#include <vector>
#include <map>

#include "INETDefs.h"
#include <omnetpp.h>
#include "ApplicationBase.h"
#include "UDPSocket.h"
#include <SatSGP4FisheyeMobility.h>
#include <LinearMobility.h>
#include <CircleMobility.h>
#include "MobilityBase.h"

class GPSPacket;


/**
 * GPS application. See NED for more info.
 */
class GPSAttackApp : public ApplicationBase
{
  public:
    enum ChooseDestAddrMode
    {
        ONCE = 1, PER_BURST, PER_SEND
    };

  protected:
    SatSGP4Mobility * Sat;
    LinearMobility * Host;
    LinearMobility * AttackHost;
    const char * Nhost;
    enum SelfMsgKinds { START = 1, SEND, STOP };
    UDPSocket socket;
    int localPort, destPort;
    ChooseDestAddrMode chooseDestAddrMode;
    std::vector<IPvXAddress> destAddresses;

    IPvXAddress destAddr;
    int destAddrRNG;

    typedef std::map<int,int> SourceSequence;
    SourceSequence sourceSequence;
    simtime_t delayLimit;
    cMessage *timerNext;
    simtime_t startTime;
    simtime_t stopTime;
    simtime_t nextPkt;
    simtime_t nextBurst;
    simtime_t nextSleep;

    bool activeBurst;
    bool isSource;
    bool haveSleepDuration;

    static int counter; // counter for generating a global number for each packet

    int numSent;
    int numReceived;
    int numDeleted;
    int numDuplicated;
    int countSat[4];
    double X[4];
    double Y[4];
    double latitude[4];
    double longitude[4];
    double altitude[4];
    double Z[4];
    double elevation[4];
    double azimuth[4];
    double distance[4];
    double G[2][2];
    int count;
    int countNearest;
    int index;
    double nearest;
    double s;
    int k;

    // volatile parameters:
    cPar *messageLengthPar;
    cPar *burstDurationPar;
    cPar *sleepDurationPar;
    cPar *sendIntervalPar;

    //statistics:
    static simsignal_t sentPkSignal;
    static simsignal_t rcvdPkSignal;
    static simsignal_t outOfOrderPkSignal;
    static simsignal_t dropPkSignal;

    // chooses random destination address
    virtual IPvXAddress chooseDestAddr();
    virtual GPSPacket *createPacket();
    virtual void processPacket(GPSPacket *msg);
    virtual void generateBurst();
    virtual double determinant(double a[][2], int n);
    virtual void CoFactor(double a[][2],int n,double b[][2]);
    virtual void Transpose(double a[][2],int n);

  protected:
    virtual int numInitStages() const { return 4; }
    virtual void initialize(int stage);
    virtual void handleMessageWhenUp(cMessage *msg);
    virtual void finish();

    virtual void processStart();
    virtual void processSend();
    virtual void processStop();

    virtual bool handleNodeStart(IDoneCallback *doneCallback);
    virtual bool handleNodeShutdown(IDoneCallback *doneCallback);
    virtual void handleNodeCrash();


  public:
    GPSAttackApp();
    ~GPSAttackApp();

};

#endif

