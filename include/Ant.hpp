#ifndef ANT_HPP
#define ANT_HPP

#include "Room.hpp"

class Ant {

public:

    int id;
    Room* currentRoom;
    bool finished;

    Ant(int i, Room* start);

    void move(Room* nextRoom);

    bool hasFinished();
};

#endif