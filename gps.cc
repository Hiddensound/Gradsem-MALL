/*
 * client.cc
 *
 *  Created on: Nov 8, 2018
 *      Author: navde
 */
#include<stdio.h>
#include<string.h>
#include<omnetpp.h>

using namespace omnetpp;

class gps : public cSimpleModule {

    cMessage *msg;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(gps);

void gps::initialize() {

    EV <<"gps initialize" <<"\n";

    msg=new cMessage("pingback");

    scheduleAt(simTime() +dblrand(),msg->dup());
    EV <<"gps initialize complete" <<"\n";

}


void gps::handleMessage(cMessage *msg)
{
    EV <<"gps handle message initialize" <<"\n";

    cModule *target;
    msg = new cMessage("pingback");
    target = getParentModule()->getSubmodule("nogps");
    sendDirect(msg,target,"radioIn");
    scheduleAt(simTime() + dblrand(),msg->dup());
}
