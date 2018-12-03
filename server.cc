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


class server : public cSimpleModule {

    cMessage *msg;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(server);

void server::initialize() {

}


void server::handleMessage(cMessage *msg)
{
    msg = new cMessage("CTS");
    cModule *target=getParentModule()->getSubmodule("client");
    sendDirect(msg,target,"radioIn");
}

