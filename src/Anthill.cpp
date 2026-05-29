#include "Anthill.hpp"

#include <iostream>

Anthill::Anthill() {

    start = nullptr;
    end = nullptr;
    antCount = 0;
}

void Anthill::addRoom(std::string name, int capacity) {

    Room* room = new Room(name, capacity);

    rooms.push_back(room);

    roomMap[name] = room;

    if (name == "Sv")
        start = room;

    if (name == "Sd")
        end = room;
}

void Anthill::addTunnel(std::string r1, std::string r2) {

    Room* a = roomMap[r1];
    Room* b = roomMap[r2];

    if (a == nullptr || b == nullptr)
        return;

    a->addNeighbor(b);
    b->addNeighbor(a);

    Tunnel* tunnel = new Tunnel(a, b);

    tunnels.push_back(tunnel);
}

Room* Anthill::getRoom(std::string name) {

    return roomMap[name];
}

void Anthill::createAnts() {

    for (int i = 1; i <= antCount; i++) {

        ants.push_back(new Ant(i, start));
    }
}

void Anthill::displayGraph() {

    std::cout << "\n===== GRAPH =====\n";

    for (Room* room : rooms) {

        std::cout << room->name << " -> ";

        for (Room* neighbor : room->neighbors) {

            std::cout << neighbor->name << " ";
        }

        std::cout << std::endl;
    }
}