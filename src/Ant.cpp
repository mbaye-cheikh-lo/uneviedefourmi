#include "Ant.hpp"

Ant::Ant(int i, Room* start) {

    id = i;
    currentRoom = start;
    finished = false;
}

void Ant::move(Room* nextRoom) {

    currentRoom = nextRoom;
}

bool Ant::hasFinished() {

    return finished;
}