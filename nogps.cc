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


class nogps : public cSimpleModule {

    cMessage *msg;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(nogps);

void nogps::initialize() {

}


void nogps::handleMessage(cMessage *msg)
{
    msg = new cMessage("ping");
    cModule *target=getParentModule()->getSubmodule("gps");
    sendDirect(msg,target,"radioIn");
}

