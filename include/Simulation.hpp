#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <queue>
#include <algorithm>
#include <vector>

#include "Anthill.hpp"

class Simulation {

private:

    Anthill* anthill;

public:

    Simulation(Anthill* a);

    std::vector<Room*> bfs();

    void simulate();
};

#endif