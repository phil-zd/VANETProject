//
// Copyright 2007 Irene Ruengeler
//
// This library is free software, you can redistribute it and/or modify
// it under  the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation;
// either version 2 of the License, or any later version.
// The library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU Lesser General Public License for more details.
//

#ifndef __SCTPSERVER_H_
#define __SCTPSERVER_H_

#include <omnetpp.h>
#include "SCTPAssociation.h"
#include "SCTPCommand_m.h"
#include "SCTPSocket.h"


/**
 * Accepts any number of incoming connections, and sends back whatever
 * arrives on them.
 */

typedef struct natInfo {
    bool multi;
    uint32 peer1;
    IPvXAddress peer1Address1;
    IPvXAddress peer1Address2;
    uint32 peer1Assoc;
    uint32 peer1Port;
    int32 peer1Gate;
    uint32 peer2;
    IPvXAddress peer2Address1;
    IPvXAddress peer2Address2;
    uint32 peer2Assoc;
    uint32 peer2Port;
    int32 peer2Gate;
} NatInfo;
typedef std::vector<NatInfo*> NatVector;

class INET_API SCTPNatServer : public cSimpleModule
{
  protected:
    int32 notifications;
    uint32 assocId;
    SCTPSocket *socket;
    bool shutdownReceived;
    int64 bytesSent;
    int32 packetsSent;
    int32 packetsRcvd;
    int32 numSessions;
    int32 numRequestsToSend; // requests to send in this session
    bool ordered;
    int32 outboundStreams;
    int32 inboundStreams;
    int32 lastStream;

    static NatVector natVector;

    int32 ssn;
  public:
    struct pathStatus {
        bool active;
        bool primaryPath;
        IPvXAddress  pid;
    };

    void initialize();
    void handleMessage(cMessage *msg);
    void finish();
    void handleTimer(cMessage *msg);
    void generateAndSend();
    void sendInfo(NatInfo* info);
    void printNatVector();
};

#endif


