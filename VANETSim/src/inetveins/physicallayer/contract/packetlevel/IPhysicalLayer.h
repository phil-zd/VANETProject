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

#ifndef __INETVEINS_IPHYSICALLAYER_H
#define __INETVEINS_IPHYSICALLAYER_H

#include "inetveins/physicallayer/base/packetlevel/PhysicalLayerDefs.h"

namespace inetveins {

/**
 * This purely virtual interface provides an abstraction for different physical layers.
 */
class INETVEINS_API IPhysicalLayer
{
  public:
    virtual ~IPhysicalLayer() {}
};

} // namespace inetveins

#endif // ifndef __INETVEINS_IPHYSICALLAYER_H
