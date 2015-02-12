//
// Copyright (C) 2000 Institut fuer Telematik, Universitaet Karlsruhe
// Copyright (C) 2007 Universidad de Málaga
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


#include "GPSAttackApp.h"

#include "InterfaceEntry.h"
#include "IInterfaceTable.h"
#include "UDPControlInfo_m.h"
#include "IPvXAddressResolver.h"
#include "GPSPacket_m.h"
#include  "math.h"
#include "stdlib.h"


#ifdef WITH_IPv4
#include "IRoutingTable.h"
#include "RoutingTableAccess.h"
#include "IPv4InterfaceData.h"
#endif

#ifdef WITH_IPv6
#include "RoutingTable6.h"
#include "RoutingTable6Access.h"
#include "IPv4InterfaceData.h"
#endif
using std::cout;


EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("ChooseDestAddrMode");
    if (!e) enums.getInstance()->add(e = new cEnum("ChooseDestAddrMode"));
    e->insert(GPSAttackApp::ONCE, "once");
    e->insert(GPSAttackApp::PER_BURST, "perBurst");
    e->insert(GPSAttackApp::PER_SEND, "perSend");
);

Define_Module(GPSAttackApp);

int GPSAttackApp::counter;

simsignal_t GPSAttackApp::sentPkSignal = registerSignal("sentPk");
simsignal_t GPSAttackApp::rcvdPkSignal = registerSignal("rcvdPk");
simsignal_t GPSAttackApp::outOfOrderPkSignal = registerSignal("outOfOrderPk");
simsignal_t GPSAttackApp::dropPkSignal = registerSignal("dropPk");

GPSAttackApp::GPSAttackApp()
{
    messageLengthPar = NULL;
    burstDurationPar = NULL;
    sleepDurationPar = NULL;
    sendIntervalPar = NULL;
    timerNext = NULL;
}

GPSAttackApp::~GPSAttackApp()
{
    cancelAndDelete(timerNext);
}

void GPSAttackApp::initialize(int stage)
{
    ApplicationBase::initialize(stage);

    if (stage == 0)
    {
        k=0;
        s=10.0;
        nearest=1000000000.0;
        index=0;
        countNearest=0;
        count=0;
        counter = 0;
        numSent = 0;
        numReceived = 0;
        numDeleted = 0;
        numDuplicated = 0;
        countSat[4]={0};
        X[4]= {0.0};
        Y[4]={0.0};
        latitude[4]={0.0};
        longitude[4]={0.0};
        altitude[4]={0.0};
        Z[4]={0.0};
        elevation[4]={0.0};
        azimuth[4]={0.0};
        distance[4]={0.0};
        G[2][2] = {0.0};
        delayLimit = par("delayLimit");
        startTime = par("startTime");
        stopTime = par("stopTime");
        if (stopTime >= SIMTIME_ZERO && stopTime <= startTime)
            error("Invalid startTime/stopTime parameters");

        messageLengthPar = &par("messageLength");
        burstDurationPar = &par("burstDuration");
        sleepDurationPar = &par("sleepDuration");
        sendIntervalPar = &par("sendInterval");
        nextSleep = startTime;
        nextBurst = startTime;
        nextPkt = startTime;
        //cout<<"Initialized";

        destAddrRNG = par("destAddrRNG");
        //cout<< "Dest address range" << destAddrRNG<<endl;
        const char *addrModeStr = par("chooseDestAddrMode").stringValue();
        int addrMode = cEnum::get("ChooseDestAddrMode")->lookup(addrModeStr);
        if (addrMode == -1)
            throw cRuntimeError("Invalid chooseDestAddrMode: '%s'", addrModeStr);
        chooseDestAddrMode = (ChooseDestAddrMode)addrMode;

        WATCH(numSent);
        WATCH(numReceived);
        WATCH(numDeleted);
        WATCH(numDuplicated);

        localPort = par("localPort");
        destPort = par("destPort");
        //noradModule = check_and_cast< Norad* >(this->getParentModule()->getSubmodule("NoradModule"));

        timerNext = new cMessage("GPSAttackAppTimer");

    }
}

IPvXAddress GPSAttackApp::chooseDestAddr()
{

    if (destAddresses.size() == 1)
        return destAddresses[0];

    int k = genk_intrand(destAddrRNG, destAddresses.size());
    //cout<< "Dest adress size: "<<destAddresses.size()<<endl;
    return destAddresses[k];
}

GPSPacket *GPSAttackApp::createPacket()
{
    char msgName[32];
    IPvXAddress dest;
    sprintf(msgName, "GPSAttackAppData-%d", counter++);
    long msgByteLength = messageLengthPar->longValue();
    GPSPacket *payload = new GPSPacket(msgName);
    payload->setByteLength(msgByteLength);
    payload->addPar("sourceId") = getId();
    payload->addPar("msgId") = numSent;
    //GPSPacket *payloadG=new GPSPacket(msgName);
    //cout<<"source ID: "<<getId()<<endl;
    payload->setDistanceArraySize(100);

    AttackHost=dynamic_cast<LinearMobility*>(this->getParentModule()->getSubmodule("mobility", 0));
    //cout<<"Attack host packet: "<<this->getParentModule()->getIndex()<<", X coord: "<<AttackHost->getCurrentPosition().x<<endl;

        payload->addPar("satId")=(100+(this->getParentModule()->getIndex()));

        payload->addPar("Xcoord")= (AttackHost->getCurrentPosition().x);//Sat->getPositionX();
        payload->addPar("Ycoord")= (AttackHost->getCurrentPosition().y);

        payload->addPar("Attack")=65;

    int z=0;
    double dist=0.0;
    nearest=1000000000.0;

    #if OMNETPP_VERSION < 0x500
        for (int i=0; i<=simulation.getLastModuleId(); i++)
        #else
            for (int i=0; i<=simulation.getLastComponentId(); i++)
        #endif
            {
                if((simulation.getModule(i))==(this->getParentModule()->getParentModule()->getSubmodule("host", z)))
                {
                    Host = dynamic_cast<LinearMobility*>(this->getParentModule()->getParentModule()->getSubmodule("host", z)->getSubmodule("mobility", 0));
                        //cout<< "Host :" << Host;
                    if (Host == NULL)
                    {
                        error("Error in Observer::initialize(): Could not find host module.");
                    }
                    // cout<<"Host's current position 1: "<<Host->getCurrentPosition()<<endl;
                    if(Sat == NULL && AttackHost!=NULL)
                    {
                        dist=Host->getCurrentPosition().distance(AttackHost->getCurrentPosition());

                            if(dist<nearest)
                            {
                                nearest=dist;
                                //AttackHost->get//->getSubmodule("mobility", 0);
                                Nhost= Host->getParentModule()->getFullName();
                                index=Host->getParentModule()->getIndex();
                                dest=destAddresses[index];
                                //int xPos=AttackHost->getCurrentPosition().Coord();
                                //cout<<"Attack host"<<AttackHost->getParentModule()->getFullName()<<endl;
                                //cout<<"Nearest host "<<Nhost<<endl;
                             }

                                //cout<<"nearest counter"<<countNearest;
                                //countNearest++;

                     }
                    // if(z==index)
                    // {
                     //    payload->setDistance(index, nearest);


                    // }
                   //  else
                     {
                         payload->setDistance(z, (dist));

                     }
                     z++;


                }

            }
        //if(k=10)
                    s=s+1;
              //  k++;
             //cout<<"payload :"<< payload;  */
        //destAddr=dest;
    return payload;
}


void GPSAttackApp::processStart()
{
    socket.setOutputGate(gate("gpsOut"));
    socket.bind(localPort);

    const char *destAddrs = par("destAddresses");
    //cout<<"Destination Address"<<destAddrs;
    cStringTokenizer tokenizer(destAddrs);
    const char *token;
    bool excludeLocalDestAddresses = par("excludeLocalDestAddresses").boolValue();

#ifdef WITH_IPv4
    IRoutingTable *rt = RoutingTableAccess().getIfExists();
#endif
#ifdef WITH_IPv6
    RoutingTable6 *rt6 = RoutingTable6Access().getIfExists();
#endif

    while ((token = tokenizer.nextToken()) != NULL)
    {
        if (strstr(token, "Broadcast") != NULL)
            destAddresses.push_back(IPv4Address::ALLONES_ADDRESS);
        else
        {
            IPvXAddress addr = IPvXAddressResolver().resolve(token);
#ifdef WITH_IPv4
            if (excludeLocalDestAddresses && rt && rt->isLocalAddress(addr.get4()))
                continue;
#endif
#ifdef WITH_IPv6
            if (excludeLocalDestAddresses && rt6 && rt6->isLocalAddress(addr.get6()))
                continue;
#endif
            destAddresses.push_back(addr);
        }
    }

    nextSleep = simTime();
    nextBurst = simTime();
    nextPkt = simTime();
    activeBurst = false;

    isSource = !destAddresses.empty();

    if (isSource)
    {
        if (chooseDestAddrMode == ONCE)
            destAddr = chooseDestAddr();

        activeBurst = true;
    }
    timerNext->setKind(SEND);
    processSend();
}


void GPSAttackApp::processSend()
{
    if (stopTime < SIMTIME_ZERO || simTime() < stopTime)
    {
        // send and reschedule next sending
        if (isSource) // if the node is a sink, don't generate messages
            generateBurst();
    }
}

void GPSAttackApp::processStop()
{
    socket.close();
}

void GPSAttackApp::handleMessageWhenUp(cMessage *msg)
{

    if (msg->isSelfMessage())
    {
        switch (msg->getKind()) {
            case START: processStart(); break;
            case SEND:  processSend(); break;
            case STOP:  processStop(); break;
            default: throw cRuntimeError("Invalid kind %d in self message", (int)msg->getKind());
        }
    }

    else if (msg->getKind() == UDP_I_DATA)
    {
        // process incoming packet
        //processPacket(PK(msg));
        processPacket(check_and_cast<GPSPacket *>(msg));                         //modified by Farha 8.24.2014
    }
    else if (msg->getKind() == UDP_I_ERROR)
    {
        EV << "Ignoring UDP error report\n";
        delete msg;
    }
    else
    {
        error("Unrecognized message (%s)%s", msg->getClassName(), msg->getName());
    }

    if (ev.isGUI())
    {
        char buf[40];
        sprintf(buf, "rcvd: %d pks\nsent: %d pks", numReceived, numSent);
        getDisplayString().setTagArg("t", 0, buf);
    }
}

void GPSAttackApp::processPacket(GPSPacket *pk)
{
    /*#if OMNETPP_VERSION < 0x500
    for (int i=0; i<=simulation.getLastModuleId(); i++)
    #else
        for (int i=0; i<=simulation.getLastComponentId(); i++)
    #endif
        {
    cout<< "Host :" <<simulation.getModule(i)<<"     parent module"<<this->getParentModule()->getSubmodule("mobility", 0)<<"    "<<endl;             //->getIndex();
        }*/


    Host = dynamic_cast<LinearMobility*>(this->getParentModule()->getSubmodule("mobility", 0));
    int index=this->getParentModule()->getIndex();
    //if (Host == NULL) {
    //   error("Error in Observer::initialize(): Could not find host module.");
    //}

    if (pk->getKind() == UDP_I_ERROR)
    {
        EV << "UDP error received\n";
        delete pk;
        return;
    }
     //cout<<"source ID host: "<<(int)pk->par("sourceId")<<" and msgId "<<(int)pk->par("msgId")<<endl;
    if (pk->hasPar("sourceId") && pk->hasPar("msgId"))
    {
        // duplicate control
        //char a = (int)pk->par("Attack");
       // cout<<"Type of packet: "<<a;
        int moduleId = (int)pk->par("sourceId");
        int msgId = (int)pk->par("msgId");
        int satId=(int)pk->par("satId");
        for(int i=0;i<5;i++)
        {
            //cout<<"distance for each host "<<pk->getDistance(i)<<endl;
           // if(*(dis+i)==0.0)
               // break;
        }
        if(count<=3)
            {
                countSat[count] = satId;
                X[count]= (double)pk->par("Xcoord");
                Y[count] = (double)pk->par("Ycoord");
                distance[count] = pk->getDistance(index);
                for(int i=0; i<=count;i++)
                    {
                        if((countSat[count]==countSat[i]) && count!=i)
                        {
                            countSat[count]=0;
                            X[count]= 0;
                            Y[count] = 0;
                            distance[count]=0;
                            count--;
                            break;
                        }

                    }
                    //cout<<countSat[count]<<", ";
                   //cout<<"Satellite Id Index["<<count<<"]: "<< countSat[count]<<endl;
                    //cout<<"Satellite Id X["<<count<<"]: "<< X[count]<<endl;
                    //cout<<"Satellite Id Y["<<count<<"]: "<< Y[count]<<endl;
                    // cout<<"Satellite Id latitude["<<count<<"]: "<< latitude[count]<<endl;
                   // cout<<"Satellite Id longitude["<<count<<"]: "<< longitude[count]<<endl;
                    //cout<<"Satellite Id Z["<<count<<"]: "<< Z[count]<<endl;
                    //cout<<"Satellite Id elevation["<<count<<"]: "<< elevation[count]<<endl;
                    //cout<<"Satellite Id azimuth["<<count<<"]: "<< azimuth[count]<<endl;
                    //cout<<"Satellite Id distance["<<count<<"]: "<< distance[count]<<endl;
                    cout<<"Host index: "<<index<<endl;

                    count++;


                    if(count==3)
                    {
                        double a =(pow(distance[0],2)-pow(distance[1],2))-(pow(X[0],2)-pow(X[1],2))-(pow(Y[0],2)-pow(Y[1],2));
                        double b =(pow(distance[0],2)-pow(distance[2],2))-(pow(X[0],2)-pow(X[2],2))-(pow(Y[0],2)-pow(Y[2],2));
                        G[0][0]=a;
                        G[0][1]=2*(Y[1]-Y[0]);
                        G[1][0]=b;
                        G[1][1]=2*(Y[2]-Y[0]);
                        double y[2][2];
                        y[0][0]=2*(X[1]-X[0]);
                        y[0][1]=a;
                        y[1][0]=2*(X[2]-X[0]);
                        y[1][1]=b;

                        double den[2][2];
                        den[0][0]=2*(X[1]-X[0]);
                        den[0][1]=2*(Y[1]-Y[0]);
                        den[1][0]=2*(X[2]-X[0]);
                        den[1][1]=2*(Y[2]-Y[0]);
                        double x_deter = determinant(G, 2);
                        double y_deter = determinant(y, 2);
                        double den_deter= determinant(den, 2);

                        //cout<<"Determinant :"<< x_deter<<" , "<<den_deter<<endl;

                        cout<<(x_deter/den_deter)<<", "<<(y_deter/den_deter)<<", "<<Host->getCurrentPosition()<<endl;
                        //cout<<"y: "<<(y_deter/den_deter)<<endl;
                        //cout<<"host current position "<<Host->getCurrentPosition()<<endl;
                        count=0;

                    }
                }

        //cout<<"Satellite Id"<<moduleId;
        //cout<<"Latitude" <<lat<<endl;
        //cout<< "longitude"<<longi<<endl;
        SourceSequence::iterator it = sourceSequence.find(moduleId);
        //cout<<"find module it: "<< sourceSequence.find(moduleId) <<"and source end: "<< sourceSequence.end();
        if (it != sourceSequence.end())
        {
            if (it->second >= msgId)
            {
                EV << "Out of order packet: " << UDPSocket::getReceivedPacketInfo(pk) << endl;
                //cout<< "Out of order packet: " << UDPSocket::getReceivedPacketInfo(pk) << endl;
                emit(outOfOrderPkSignal, pk);
                delete pk;
                numDuplicated++;
                return;
            }
            else
                it->second = msgId;
        }
        else
            sourceSequence[moduleId] = msgId;
    }

    if (delayLimit > 0)
    {
        if (simTime() - pk->getTimestamp() > delayLimit)
        {
            EV << "Old packet: " << UDPSocket::getReceivedPacketInfo(pk) << endl;
            emit(dropPkSignal, pk);
            delete pk;
            numDeleted++;
            return;
        }
    }

    EV << "Received packet: " << UDPSocket::getReceivedPacketInfo(pk) << endl;
    emit(rcvdPkSignal, pk);
    numReceived++;
    delete pk;
}
double GPSAttackApp::determinant(double a[][2], int n)
{
   int i,j,j1,j2;
   double det = 0;
   double m[2][2];       // = {{0.0},{0.0},{0.0}};

   if (n < 1) { /* Error */

   } else if (n == 1) { /* Shouldn't get used */
      det = a[0][0];
   } else if (n == 2) {
      det = a[0][0] * a[1][1] - a[1][0] * a[0][1];
   } else {
      det = 0;
      for (j1=0;j1<n;j1++) {
         for (i=0;i<n-1;i++)
         for (i=1;i<n;i++) {
            j2 = 0;
            for (j=0;j<n;j++) {
               if (j == j1)
                  continue;
               m[i-1][j2] = a[i][j];
               j2++;
            }
         }

      }
   }
   return(det);
}
/*
   Find the cofactor matrix of a square matrix
*/
void GPSAttackApp::CoFactor(double a[][2],int n,double b[][2])
{
   int i,j,ii,jj,i1,j1;
   double det;
   double c[2][2];

   for (i=0;i<n-1;i++)


   for (j=0;j<n;j++) {
      for (i=0;i<n;i++) {

         /* Form the adjoint a_ij */
         i1 = 0;
         for (ii=0;ii<n;ii++) {
            if (ii == i)
               continue;
            j1 = 0;
            for (jj=0;jj<n;jj++) {
               if (jj == j)
                  continue;
               c[i1][j1] = a[ii][jj];
               j1++;
            }
            i1++;
         }

         /* Calculate the determinate */
         det = determinant(c,n-1);

         /* Fill in the elements of the cofactor */
         b[i][j] = pow(-1.0,i+j+2.0) * det;
      }
   }
   }
/*
   Transpose of a square matrix, do it in place
*/
void GPSAttackApp::Transpose(double a[][2],int n)
{
   int i,j;
   double tmp;

   for (i=1;i<n;i++) {
      for (j=0;j<i;j++) {
         tmp = a[i][j];
         a[i][j] = a[j][i];
         a[j][i] = tmp;
      }
   }
}


void GPSAttackApp::generateBurst()
{
    simtime_t now = simTime();

    if (nextPkt < now)
        nextPkt = now;

    double sendInterval = sendIntervalPar->doubleValue();
    if (sendInterval <= 0.0)
        throw cRuntimeError("The sendInterval parameter must be bigger than 0");
    nextPkt += sendInterval;

    if (activeBurst && nextBurst <= now) // new burst
    {
        double burstDuration = burstDurationPar->doubleValue();
        if (burstDuration < 0.0)
            throw cRuntimeError("The burstDuration parameter mustn't be smaller than 0");
        double sleepDuration = sleepDurationPar->doubleValue();

        if (burstDuration == 0.0)
            activeBurst = false;
        else
        {
            if (sleepDuration < 0.0)
                throw cRuntimeError("The sleepDuration parameter mustn't be smaller than 0");
            nextSleep = now + burstDuration;
            nextBurst = nextSleep + sleepDuration;
        }

        if (chooseDestAddrMode == PER_BURST)
            destAddr = chooseDestAddr();
    }

    if (chooseDestAddrMode == PER_SEND)
        destAddr = chooseDestAddr();

    cPacket *payload = createPacket();
    payload->setTimestamp();
    emit(sentPkSignal, payload);
    socket.sendTo(payload, destAddr, destPort);
    numSent++;

    // Next timer
    if (activeBurst && nextPkt >= nextSleep)
        nextPkt = nextBurst;

    if (stopTime >= SIMTIME_ZERO && nextPkt >= stopTime)
    {
        timerNext->setKind(STOP);
        nextPkt = stopTime;
    }
    scheduleAt(nextPkt, timerNext);
}

void GPSAttackApp::finish()
{

    recordScalar("Total sent", numSent);
    recordScalar("Total received", numReceived);
    recordScalar("Total deleted", numDeleted);
    recordScalar("Total duplicated", numDuplicated);

    cout<<"Total sent"<<  numSent<<endl;
    cout<<"Total received"<<  numReceived<<endl;
    cout<<"Total deleted"<<  numDeleted<<endl;
    cout<<"Total duplicated"<<  numDuplicated<<endl;

    ApplicationBase::finish();
}

bool GPSAttackApp::handleNodeStart(IDoneCallback *doneCallback)
{
    simtime_t start = std::max(startTime, simTime());

    if ((stopTime < SIMTIME_ZERO) || (start < stopTime) || (start == stopTime && startTime == stopTime))
    {
        timerNext->setKind(START);
        scheduleAt(start, timerNext);
    }

    return true;
}

bool GPSAttackApp::handleNodeShutdown(IDoneCallback *doneCallback)
{
    if (timerNext)
        cancelEvent(timerNext);
    activeBurst = false;
    //TODO if(socket.isOpened()) socket.close();
    return true;
}

void GPSAttackApp::handleNodeCrash()
{
    if (timerNext)
        cancelEvent(timerNext);
    activeBurst = false;
}

