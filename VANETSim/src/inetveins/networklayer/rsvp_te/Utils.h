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

#ifndef __INETVEINS_UTILS_H
#define __INETVEINS_UTILS_H

#include <vector>

#include "inetveins/common/INETVEINSDefs.h"

#include "inetveins/networklayer/rsvp_te/IntServ.h"

namespace inetveins {

EroVector routeToEro(const IPAddressVector& rro);
std::string vectorToString(const IPAddressVector& vec);
std::string vectorToString(const IPAddressVector& vec, const char *delim);
std::string vectorToString(const EroVector& vec);
std::string vectorToString(const EroVector& vec, const char *delim);

/**
 * TODO documentation
 */
void removeDuplicates(std::vector<int>& vec);

/**
 * TODO documentation
 */
bool find(std::vector<int>& vec, int value);

/**
 * TODO documentation
 */
bool find(const IPAddressVector& vec, IPv4Address addr);    // use TEMPLATE

/**
 * TODO documentation
 */
void append(std::vector<int>& dest, const std::vector<int>& src);

/**
 * TODO documentation
 */
int find(const EroVector& ERO, IPv4Address node);

/**
 * XXX function appears to be unused
 */
cModule *getPayloadOwner(cPacket *msg);

//void prepend(EroVector& dest, const EroVector& src, bool reverse);

} // namespace inetveins

#endif // ifndef __INETVEINS_UTILS_H
