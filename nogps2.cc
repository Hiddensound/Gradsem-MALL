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


class nogps2 : public cSimpleModule {

    cMessage *msg;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(nogps2);

void nogps2::initialize() {

}


void nogps2::handleMessage(cMessage *msg)
{
    msg = new cMessage("ping2");
    cModule *target=getParentModule()->getSubmodule("gps1");
    sendDirect(msg,target,"radioIn");
}




