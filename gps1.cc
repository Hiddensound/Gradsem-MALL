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

class gps1 : public cSimpleModule {

    cMessage *msg;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(gps1);

void gps1::initialize() {

    EV <<"gps1 initialize" <<"\n";

    msg=new cMessage("pingback1");

    scheduleAt(simTime() +dblrand(),msg->dup());
    EV <<"gps1 initialize complete" <<"\n";

}


void gps1::handleMessage(cMessage *msg)
{
    EV <<"gps1 handle message initialize" <<"\n";

    cModule *target;
    msg = new cMessage("pingback1");
    target = getParentModule()->getSubmodule("nogps2");
    sendDirect(msg,target,"radioIn");
    scheduleAt(simTime() + dblrand(),msg->dup());
}
