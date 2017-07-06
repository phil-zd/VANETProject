//
// (C) 2005 Vojtech Janota
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

#ifndef __INETVEINS_ICLASSIFIER_H
#define __INETVEINS_ICLASSIFIER_H

#include "inetveins/common/INETVEINSDefs.h"

#include "inetveins/networklayer/ipv4/IPv4Datagram.h"
#include "inetveins/networklayer/mpls/LIBTable.h"

namespace inetveins {

/**
 * This is an abstract interface for packet classifiers in MPLS ingress routers.
 * The MPLS module holds a pointer to an IClassifier object, and uses it to
 * classify IPv4 datagrams and find the right label-switched path for them.
 *
 * A known sub-interface is IRSVPClassifier.
 *
 * Known concrete classifier classes are the LDP module class and (via IRSVPClassifier)
 * RSVP_TE's SimpleClassifier module class.
 */
class INETVEINS_API IClassifier
{
  public:
    virtual ~IClassifier() {}

    /**
     * The ipdatagram argument is an input parameter, the rest (outLabel,
     * outInterface, color) are output parameters only.
     *
     * In subclasses, this function should be implemented to determine the forwarding
     * equivalence class for the IPv4 datagram passed, and map it to an outLabel
     * and outInterface.
     *
     * The color parameter (which can be set to an arbitrary value) will
     * only be used for the NAM trace if one will be recorded.
     */
    virtual bool lookupLabel(IPv4Datagram *ipdatagram, LabelOpVector& outLabel, std::string& outInterface, int& color) = 0;
};

} // namespace inetveins

#endif // ifndef __INETVEINS_ICLASSIFIER_H
