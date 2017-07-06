//
// Copyright (C) 2013 OpenSim Ltd.
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

#ifndef __INETVEINS_SCALARTRANSMISSION_H
#define __INETVEINS_SCALARTRANSMISSION_H

#include "inetveins/physicallayer/base/packetlevel/FlatTransmissionBase.h"

namespace inetveins {

namespace physicallayer {

class INETVEINS_API ScalarTransmission : public FlatTransmissionBase, public virtual IScalarSignal
{
  protected:
    const W power;

  public:
    ScalarTransmission(const IRadio *transmitter, const cPacket *macFrame, const simtime_t startTime, const simtime_t endTime, const simtime_t preambleDuration, const simtime_t headerDuration, const simtime_t dataDuration, const Coord startPosition, const Coord endPosition, const EulerAngles startOrientation, const EulerAngles endOrientation, const IModulation *modulation, int headerBitLength, int payloadBitLength, Hz carrierFrequency, Hz bandwidth, bps bitrate, W power);

    virtual std::ostream& printToStream(std::ostream& stream, int level) const override;

    virtual W getPower() const override { return power; }
    virtual W computeMinPower(const simtime_t startTime, const simtime_t endTime) const override { return power; }
};

} // namespace physicallayer

} // namespace inetveins

#endif // ifndef __INETVEINS_SCALARTRANSMISSION_H
