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

class master2 : public cSimpleModule {

    cMessage *msg;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(master2);

void master2::initialize() {

    EV <<"master2 initialize" <<"\n";

    msg=new cMessage("ack");

    scheduleAt(simTime() +dblrand(),msg->dup());
    EV <<"client initialize complete" <<"\n";

}


void master2::handleMessage(cMessage *msg)
{
    EV <<"master2 handle message initialize" <<"\n";

    cModule *target;
    msg = new cMessage("ack");
    target = getParentModule()->getSubmodule("master1");
    sendDirect(msg,target,"radioIn");
    scheduleAt(simTime() + dblrand(),msg->dup());
}
