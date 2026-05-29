#include "Simulation.hpp"

#include <iostream>
#include <map>

Simulation::Simulation(Anthill* a) {

    anthill = a;
}

std::vector<Room*> Simulation::bfs() {

    std::map<Room*, bool> visited;
    std::map<Room*, Room*> parent;
    std::queue<Room*> q;

    q.push(anthill->start);

    visited[anthill->start] = true;

    while (!q.empty()) {

        Room* current = q.front();
        q.pop();

        if (current == anthill->end)
            break;

        for (Room* neighbor : current->neighbors) {

            if (!visited[neighbor]) {

                visited[neighbor] = true;

                parent[neighbor] = current;

                q.push(neighbor);
            }
        }
    }

    std::vector<Room*> path;

    Room* current = anthill->end;

    // Vérifie qu'un chemin existe
    if (!visited[anthill->end])
        return path;

    while (current != anthill->start) {

        path.push_back(current);

        current = parent[current];
    }

    path.push_back(anthill->start);

    std::reverse(path.begin(), path.end());

    return path;
}

void Simulation::simulate() {

    std::vector<Room*> path = bfs();

    if (path.empty()) {

        std::cout << "No path found." << std::endl;
        return;
    }

    std::vector<int> positions(anthill->antCount, 0);

    int finishedAnts = 0;
    int step = 1;

    while (finishedAnts < anthill->antCount) {

        std::cout << "\n+++ STEP " << step << " +++\n";

        for (int i = 0; i < anthill->antCount; i++) {

            Ant* ant = anthill->ants[i];

            if (ant->finished)
                continue;

            int currentIndex = positions[i];

            if (currentIndex >= path.size() - 1)
                continue;

            Room* currentRoom = path[currentIndex];
            Room* nextRoom = path[currentIndex + 1];

            bool canMove = false;

            if (nextRoom == anthill->end)
                canMove = true;

            else if (!nextRoom->isFull())
                canMove = true;

            if (canMove) {

                if (currentRoom != anthill->start)
                    currentRoom->leave();

                if (nextRoom != anthill->end)
                    nextRoom->enter();

                ant->move(nextRoom);

                positions[i]++;

                std::cout << "F"
                          << ant->id
                          << ": "
                          << currentRoom->name
                          << " -> "
                          << nextRoom->name
                          << std::endl;

                if (nextRoom == anthill->end) {

                    ant->finished = true;
                    finishedAnts++;
                }
            }
        }

        step++;
    }

    std::cout << "\nSimulation finished." << std::endl;
}