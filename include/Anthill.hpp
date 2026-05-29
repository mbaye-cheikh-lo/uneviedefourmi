#ifndef ANTHILL_HPP
#define ANTHILL_HPP

#include <map>
#include <vector>
#include <string>

#include "Room.hpp"
#include "Ant.hpp"
#include "Tunnel.hpp"

class Anthill {

private:

    std::map<std::string, Room*> roomMap;

public:

    std::vector<Room*> rooms;
    std::vector<Tunnel*> tunnels;
    std::vector<Ant*> ants;

    Room* start;
    Room* end;

    int antCount;

    Anthill();

    void addRoom(std::string name, int capacity = 1);

    void addTunnel(std::string r1, std::string r2);

    Room* getRoom(std::string name);

    void createAnts();

    void displayGraph();
};

#endif