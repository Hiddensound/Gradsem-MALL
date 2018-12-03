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

class client : public cSimpleModule {

    cMessage *msg;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(client);

void client::initialize() {

    EV <<"client initialize" <<"\n";

    msg=new cMessage("RTS");

    scheduleAt(simTime() +dblrand(),msg->dup());
    EV <<"client initialize complete" <<"\n";

}


void client::handleMessage(cMessage *msg)
{
    EV <<"client handle message initialize" <<"\n";

    cModule *target;
    msg = new cMessage("RTS");
    target = getParentModule()->getSubmodule("server");
    sendDirect(msg,target,"radioIn");
    scheduleAt(simTime() + dblrand(),msg->dup());
}
