#include "Room.hpp"

Room::Room(string n, int c) {

    name = n;
    capacity = c;
    occupiedCount = 0;
}

void Room::addNeighbor(Room* room) {

    neighbors.push_back(room);
}
bool Room::isFull() {

    return occupiedCount >= capacity;
}

void Room::enter() {

    occupiedCount++;
}

void Room::leave() {

    occupiedCount--;
}