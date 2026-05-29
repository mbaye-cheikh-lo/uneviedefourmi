#include "Ant.hpp"

Ant::Ant(int i, Room* start) {

    id = i;
    current = start;
    finished = false;
}

void Ant::move(Room* r) {

    current = r;
}