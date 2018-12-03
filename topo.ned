//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

// Created: 2018-10-11 for project mall

import ned.DelayChannel;

module Non_Anchors
{
    parameters:
        @display("i=misc/node_vs");
    gates:
        inout Anchor;
    connections allowunconnected:
}

module Anchor
{
    parameters:
        @display("i=misc/node_vs");
    gates:
        inout NonAnchor[];
    connections allowunconnected:
}

//
// A generated network with star topology.
//
network Topo
{
    submodules:
        Anchor: Anchor {
            @display("p=200,200");
            gates:
                NonAnchor[5];
        }
        nonanchor5: Non_Anchors {
            @display("p=200,50");

        }
        nonanchor3: Non_Anchors {
            @display("p=342,154");

        }
        nonanchor2: Non_Anchors {
            @display("p=288,322");

        }
        nonanchor1: Non_Anchors {
            @display("p=111,322");

        }
        nonanchor4: Non_Anchors {
            @display("p=57,154");

        }
    connections:
        Anchor.NonAnchor[0] <--> DelayChannel <--> nonanchor5.Anchor;
        Anchor.NonAnchor[1] <--> DelayChannel <--> nonanchor3.Anchor;
        Anchor.NonAnchor[2] <--> DelayChannel <--> nonanchor2.Anchor;
        Anchor.NonAnchor[3] <--> DelayChannel <--> nonanchor1.Anchor;
        Anchor.NonAnchor[4] <--> DelayChannel <--> nonanchor4.Anchor;
}
