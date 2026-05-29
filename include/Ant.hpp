#ifndef ANT_HPP
#define ANT_HPP

#include "Room.hpp"

class Ant {

public:

    int id;
    Room* current;
    bool finished;

    Ant(int i, Room* start);

    void move(Room* r);
};

#endif