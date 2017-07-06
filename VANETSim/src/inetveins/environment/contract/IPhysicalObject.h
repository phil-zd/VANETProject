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

#ifndef __INETVEINS_IPHYSICALOBJECT_H
#define __INETVEINS_IPHYSICALOBJECT_H

#include "inetveins/common/geometry/common/EulerAngles.h"
#include "inetveins/common/geometry/base/ShapeBase.h"
#include "inetveins/environment/contract/IMaterial.h"

namespace inetveins {

namespace physicalenvironment {

class INETVEINS_API IPhysicalObject
{
  public:
    virtual const Coord& getPosition() const = 0;
    virtual const EulerAngles& getOrientation() const = 0;

    virtual const ShapeBase *getShape() const = 0;
    virtual const IMaterial *getMaterial() const = 0;

    virtual double getLineWidth() const = 0;
    virtual const cFigure::Color& getLineColor() const = 0;
    virtual const cFigure::Color& getFillColor() const = 0;
    virtual double getOpacity() const = 0;
    virtual const char *getTags() const = 0;
};

} // namespace physicalenvironment

} // namespace inetveins

#endif // ifndef __INETVEINS_IPHYSICALOBJECT_H
