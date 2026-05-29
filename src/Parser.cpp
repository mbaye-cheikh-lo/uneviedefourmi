#include "Parser.hpp"

Parser::Parser(string file) {

    filename = file;
}

void Parser::parse(Anthill& anthill) {

    ifstream fin(filename);

    if (!fin) {

        cout << "Erreur ouverture fichier" << endl;
        return;
    }

    fin >> anthill.antCount;

    string line;
 while (getline(fin, line)) {

        if (line.empty())
            continue;

        if (line.find('-') != string::npos) {

            stringstream ss(line);

            string r1, r2;

            getline(ss, r1, '-');
            getline(ss, r2, '-');

            anthill.addTunnel(r1, r2);
        }
        else {

            anthill.addRoom(line);
        }
    }
}