//
// Copyright (C) 2014 OpenSim Ltd.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//

#ifndef __INETVEINS_APSKPHYFRAMESERIALIZER_H
#define __INETVEINS_APSKPHYFRAMESERIALIZER_H

#include "inetveins/common/BitVector.h"
#include "inetveins/physicallayer/apskradio/bitlevel/APSKPhyFrame_m.h"

namespace inetveins {

namespace physicallayer {

#define APSK_PHY_FRAME_HEADER_BYTE_LENGTH    6

class INETVEINS_API APSKPhyFrameSerializer
{
  public:
    APSKPhyFrameSerializer();

    virtual BitVector *serialize(const APSKPhyFrame *phyFrame) const;
    virtual APSKPhyFrame *deserialize(const BitVector *bits) const;
};

} // namespace physicallayer

} // namespace inetveins

#endif // ifndef __INETVEINS_APSKPHYFRAMESERIALIZER_H
