// Author: Joanne Skiles
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//

#ifndef __INET_POSITIONTABLE_H
#define __INET_POSITIONTABLE_H

#include <vector>
#include <map>
#include "inet/common/INETMath.h"
#include "inet/common/INETDefs.h"
#include "inet/networklayer/common/L3Address.h"
#include "inet/common/geometry/common/Coord.h"
#include "inet/common/geometry/common/EulerAngles.h"
#include "inet/common/INETMath.h"

namespace inet {

/**
 * This class provides a mapping between node addresses and their positions.
 */
class INET_API GPSRWRPositionTable
{
  private:
    typedef std::pair<simtime_t, Coord> AddressToPositionMapValue;
    typedef std::map<L3Address, AddressToPositionMapValue> AddressToPositionMap;
    AddressToPositionMap addressToPositionMap;

    typedef std::pair<simtime_t, Coord> AddressToSpeedMapValue;
    typedef std::map<L3Address, AddressToSpeedMapValue> AddressToSpeedMap;
    AddressToSpeedMap addressToSpeedMap;

    typedef std::pair<simtime_t, Coord> AddressToAccelerationMapValue;
    typedef std::map<L3Address, AddressToAccelerationMapValue> AddressToAccelerationMap;
    AddressToAccelerationMap addressToAccelerationMap;

    typedef std::pair<simtime_t, EulerAngles> AddressToDirectionMapValue;
    typedef std::map<L3Address, AddressToDirectionMapValue> AddressToDirectionMap;
    AddressToDirectionMap addressToDirectionMap;

  public:
    GPSRWRPositionTable() {}

    std::vector<L3Address> getAddresses() const;

    bool hasPosition(const L3Address& address) const;
    Coord getPosition(const L3Address& address) const;
    void setPosition(const L3Address& address, const Coord& coord);

    void removePosition(const L3Address& address);
    void removeOldPositions(simtime_t timestamp);

    bool hasSpeed(const L3Address& address) const;
    Coord getSpeed(const L3Address& address) const;
    void setSpeed(const L3Address& address, const Coord& coord);

    void removeSpeed(const L3Address& address);
    void removeOldSpeeds(simtime_t timestamp);

    bool hasAcceleration(const L3Address& address) const;
    Coord getAcceleration(const L3Address& address) const;
    void setAcceleration(const L3Address& address, const Coord& coord);

    void removeAcceleration(const L3Address& address);
    void removeOldAccelerations(simtime_t timestamp);

    bool hasDirection(const L3Address& address) const;
    EulerAngles getDirection(const L3Address& address) const;
    void setDirection(const L3Address& address, const EulerAngles& eulerAngles);

    void removeDirection(const L3Address& address);
    void removeOldDirections(simtime_t timestamp);

    void clear();

    simtime_t getOldestPosition() const;

    friend std::ostream& operator << (std::ostream& o, const GPSRWRPositionTable& t);
};

} // namespace inet

#endif // ifndef __INET_POSITIONTABLE_H

