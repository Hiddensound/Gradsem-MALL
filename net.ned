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
//
// TODO documentation

import ned.IBidirectionalChannel;


//
simple server
{
    @display("i=device/wifilaptop;p=230,40");
    gates:
        input radioIn @directIn;

}


//
// TODO documentation
//
simple client
{
    @display("i=device/wifilaptop;p=230,40");
    gates:
        input radioIn @directIn;

}

//
// TODO documentation
//
simple gps
{
    @display("i=device/wifilaptop;p=230,40");
    gates:
        input radioIn @directIn;

}

//
// TODO documentation
//
simple master1
{
    @display("i=device/wifilaptop;p=230,40");
    gates:
        input radioIn @directIn;

}

//
// TODO documentation
//
simple master2
{
    @display("i=device/wifilaptop;p=230,40");
    gates:
        input radioIn @directIn;

}

//
// TODO documentation
//
network Network
{
    @display("bgb=326,135");
    submodules:
        server: server {
            @display("p=102,73");
        }
        client: client {
            @display("p=207,85");
        }
}

simple nogps
{
    @display("i=device/wifilaptop;p=230,40");
    gates:
        input radioIn @directIn;

}

//
// TODO documentation
//
network Network1
{
    @display("bgb=414,224");
    types:
    submodules:
        nogps: nogps {
            @display("p=52,104");
        }
        gps: gps {
            @display("p=187,122");
        }
}

//
// TODO documentation
//
network Network2
{
    @display("bgb=414,200");
    types:
    submodules:
        master1: master1 {
            @display("p=90,84");
        }
        master2: master2 {
            @display("p=236,84");
        }
}

