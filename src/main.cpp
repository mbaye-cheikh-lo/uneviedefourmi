#include "Parser.hpp"
#include "Simulation.hpp"

int main() {

    Anthill anthill;

    // Création des salles
    anthill.addRoom("Sv", 999);
    anthill.addRoom("S1", 1);
    anthill.addRoom("S2", 1);
    anthill.addRoom("Sd", 999);

    // Création des tunnels
    anthill.addTunnel("Sv", "S1");
    anthill.addTunnel("Sv", "S2");
    anthill.addTunnel("S1", "Sd");
    anthill.addTunnel("S2", "Sd");

    // Nombre de fourmis
    anthill.antCount = 3;

    // Création des fourmis
    anthill.createAnts();

    // Affichage du graphe
    anthill.displayGraph();

    // Lancement de la simulation
    Simulation simulation(&anthill);
    simulation.simulate();

    return 0;
}