/*
 * server.cc
 *
 *  Created on: Nov 8, 2018
 *      Author: navde
 */



#include<stdio.h>
#include<string.h>
#include<omnetpp.h>

using namespace omnetpp;


class master1 : public cSimpleModule {

    cMessage *msg;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(master1);

void master1::initialize() {

}


void master1::handleMessage(cMessage *msg)
{
    msg = new cMessage("transfer");
    cModule *target=getParentModule()->getSubmodule("master2");
    sendDirect(msg,target,"radioIn");
}

