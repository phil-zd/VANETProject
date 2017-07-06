//
// (C) 2005 Vojtech Janota
// (C) 2003 Xuan Thang Nguyen
//
// This library is free software, you can redistribute it
// and/or modify
// it under  the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation;
// either version 2 of the License, or any later version.
// The library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU Lesser General Public License for more details.
//

#ifndef __INETVEINS_MPLS_H
#define __INETVEINS_MPLS_H

#include <vector>

#include "inetveins/common/INETVEINSDefs.h"

#include "inetveins/networklayer/mpls/MPLSPacket.h"
#include "inetveins/networklayer/ipv4/IPv4Datagram.h"
#include "inetveins/networklayer/mpls/ConstType.h"

#include "inetveins/networklayer/mpls/LIBTable.h"
#include "inetveins/networklayer/contract/IInterfaceTable.h"

#include "inetveins/networklayer/mpls/IClassifier.h"

namespace inetveins {

/**
 * Implements the MPLS protocol; see the NED file for more info.
 */
class INETVEINS_API MPLS : public cSimpleModule
{
  protected:
    simtime_t delay1;

    //no longer used, see comment in intialize
    //std::vector<bool> labelIf;

    LIBTable *lt;
    IInterfaceTable *ift;
    IClassifier *pct;

  protected:
    virtual void initialize(int stage) override;
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void handleMessage(cMessage *msg) override;

  protected:
    virtual void processPacketFromL3(cMessage *msg);
    virtual void processPacketFromL2(cMessage *msg);
    virtual void processMPLSPacketFromL2(MPLSPacket *mplsPacket);

    virtual bool tryLabelAndForwardIPv4Datagram(IPv4Datagram *ipdatagram);
    virtual void labelAndForwardIPv4Datagram(IPv4Datagram *ipdatagram);

    virtual void sendToL2(cMessage *msg, int gateIndex);
    virtual void doStackOps(MPLSPacket *mplsPacket, const LabelOpVector& outLabel);
};

} // namespace inetveins

#endif // ifndef __INETVEINS_MPLS_H
