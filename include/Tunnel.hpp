#ifndef TUNNEL_HPP
#define TUNNEL_HPP

#include "Room.hpp"

class Tunnel {

public:

    Room* roomA;
    Room* roomB;

    Tunnel(Room* a, Room* b);
};

#endif