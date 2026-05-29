# uneviedefourmi
# Une vie de fourmi

## Description

Ce projet a été réalisé dans le cadre du module de programmation C++.

L'objectif est de simuler le déplacement d'un groupe de fourmis dans une fourmilière composée de salles reliées par des tunnels. Toutes les fourmis doivent rejoindre le dortoir (`Sd`) depuis le vestibule (`Sv`) en un minimum d'étapes tout en respectant les contraintes d'occupation des salles.

Le projet utilise la programmation orientée objet ainsi que l'algorithme BFS (Breadth First Search) afin de déterminer les chemins utilisables dans la fourmilière.

---

## Problématique

Une fourmilière est représentée sous forme de graphe :

* Les sommets représentent les salles.
* Les arêtes représentent les tunnels.
* Le vestibule (`Sv`) est la salle de départ.
* Le dortoir (`Sd`) est la salle d'arrivée.

Contraintes :

* Toutes les fourmis démarrent dans `Sv`.
* Toutes les fourmis doivent atteindre `Sd`.
* Une salle intermédiaire ne peut contenir qu'une seule fourmi à la fois.
* Les tunnels sont traversés instantanément.
* Le nombre total d'étapes doit être minimisé.

---

## Architecture du projet

```text
uneviedefourmi/
│
├── include/
│   ├── Room.hpp
│   ├── Ant.hpp
│   ├── Tunnel.hpp
│   ├── Anthill.hpp
│   ├── Parser.hpp
│   └── Simulation.hpp
│
├── src/
│   ├── Room.cpp
│   ├── Ant.cpp
│   ├── Tunnel.cpp
│   ├── Anthill.cpp
│   ├── Parser.cpp
│   ├── Simulation.cpp
│   └── main.cpp
│
├── maps/
│   └── map1.txt
│
└── README.md
```

---

## Classes principales

### Room

Représente une salle de la fourmilière.

Attributs :

* nom de la salle
* capacité
* nombre de fourmis présentes
* salles voisines

---

### Ant

Représente une fourmi.

Attributs :

* identifiant
* salle actuelle
* état d'arrivée

---

### Tunnel

Représente un tunnel reliant deux salles.

---

### Anthill

Représente la fourmilière complète.

Responsabilités :

* stockage des salles
* stockage des tunnels
* création des fourmis
* affichage du graphe

---

### Parser

Permet de charger une fourmilière à partir d'un fichier texte.

---

### Simulation

Responsable :

* de la recherche de chemins avec BFS
* de la simulation des déplacements
* de l'affichage des étapes

---

## Algorithme utilisé

### Breadth First Search (BFS)

Le BFS est utilisé pour trouver les chemins entre le vestibule et le dortoir.

Principe :

1. Exploration du graphe niveau par niveau.
2. Recherche du plus court chemin.
3. Reconstruction du chemin grâce à une table de parents.
4. Répétition pour trouver plusieurs chemins distincts.

Complexité :

```text
O(V + E)
```

avec :

* V = nombre de salles
* E = nombre de tunnels

---

## Exemple de fichier d'entrée

```text
3
Sv
S1
S2
Sd
Sv-S1
Sv-S2
S1-Sd
S2-Sd
```

Signification :

* 3 fourmis
* 4 salles
* 4 tunnels

---

## Exemple de sortie

```text
===== GRAPH =====
Sv -> S1 S2
S1 -> Sv Sd
S2 -> Sv Sd
Sd -> S1 S2

+++ E1 +++
f1-Sv-S1
f2-Sv-S2

+++ E2 +++
f1-S1-Sd
f2-S2-Sd
f3-Sv-S1

+++ E3 +++
f3-S1-Sd
```

Toutes les fourmis atteignent le dortoir en 3 étapes.

---

## Compilation

Sous Linux :

```bash
g++ src/*.cpp -Iinclude -std=c++17 -o ants
```

Sous Windows (MinGW) :

```bash
g++ src/*.cpp -Iinclude -std=c++17 -o ants.exe
```

---

## Exécution

Linux :

```bash
./ants
```

Windows :

```bash
ants.exe
```

---

## Améliorations possibles

### Multi-chemins avancés

Utilisation de :

* Edmonds-Karp
* Ford-Fulkerson
* Maximum Flow

afin d'optimiser davantage la répartition des fourmis.

### Interface graphique

Ajout d'une visualisation avec :

* SFML
* SDL2

pour observer le déplacement des fourmis en temps réel.

### Benchmark

Comparaison de plusieurs algorithmes :

* BFS
* DFS
* Edmonds-Karp
* Ford-Fulkerson

---

## Compétences mobilisées

* Programmation orientée objet en C++
* Structures de données
* Graphes
* Algorithmes de parcours
* Gestion de mémoire dynamique
* Organisation modulaire d'un projet
* Git et GitHub

---

## Conclusion

Ce projet permet de mettre en pratique la modélisation d'un problème réel sous forme de graphe et l'utilisation de l'algorithme BFS pour optimiser le déplacement d'agents dans un réseau de salles connectées.

L'approche orientée objet facilite l'évolution du projet et l'ajout de nouvelles fonctionnalités comme la visualisation graphique ou l'utilisation d'algorithmes d'optimisation plus avancés.
