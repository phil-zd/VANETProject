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

cplusplus {{
#include "inet/common/INETMath.h"
#include "inet/common/geometry/common/Coord.h"
#include "inet/common/TLVOption.h"
#include "inet/networklayer/common/L3Address.h"
#include "vanetsim/routing/geoadv/GEOADVDefs.h"
}}

namespace inet;

class noncobject L3Address;

class noncobject Coord;

class noncobject GEOADVForwardingMode;

class noncobject TLVOptionBase;

//
// The GEOADV beacon packet is sent periodically by all GEOADV routers to notify
// the neighbors about the router's address and position.
//
packet GEOADVBeacon {
    L3Address address;
    Coord position;
}

//
// The GEOADVOption is used to add extra routing information for network datagrams.
//
// For more information, see the GEOADV paper
// http://www.eecs.harvard.edu/~htk/publication/2000-mobi-karp-kung.pdf
//
class GEOADVOption extends TLVOptionBase {
    GEOADVForwardingMode routingMode = (GEOADVForwardingMode)-1;
    Coord destinationPosition;               // D
    Coord twrRoutingStartPosition;     // Lp
    Coord twrRoutingForwardPosition;   // Lf
    L3Address currentFaceFirstSenderAddress;   // e0
    L3Address currentFaceFirstReceiverAddress; // e0
    L3Address senderAddress; // TODO: this field is not strictly needed by GEOADV (should be eliminated)
}

