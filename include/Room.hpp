#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include <vector>

using namespace std;

class Room {

public:

    string name;
    int capacity;
    int occupiedCount;
    vector<Room*> neighbors;

    Room(string n, int c = 1);

    void addNeighbor(Room* room);

    bool isFull();

    void enter();

    void leave();
};

#endif