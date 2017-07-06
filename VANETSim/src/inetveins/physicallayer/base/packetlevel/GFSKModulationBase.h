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

#ifndef __INETVEINS_GFSKMODULATIONBASE_H
#define __INETVEINS_GFSKMODULATIONBASE_H

#include "inetveins/physicallayer/contract/packetlevel/IModulation.h"

namespace inetveins {

namespace physicallayer {

class INETVEINS_API GFSKModulationBase : public IModulation
{
  protected:
    unsigned int constellationSize;

  public:
    GFSKModulationBase(unsigned int constellationSize);

    double calculateBER(double snir, Hz bandwidth, bps bitrate) const { throw cRuntimeError("Unimplemented!"); }
    double calculateSER(double snir, Hz bandwidth, bps bitrate) const { throw cRuntimeError("Unimplemented!"); }

    unsigned int getConstellationSize() const { return constellationSize; }
};

} // namespace physicallayer

} // namespace inetveins

#endif // ifndef __INETVEINS_GFSKMODULATIONBASE_H
