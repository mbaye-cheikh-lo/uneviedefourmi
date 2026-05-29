#ifndef PARSER_HPP
#define PARSER_HPP

#include <fstream>
#include <sstream>
#include "Anthill.hpp"

class Parser {

private:

    string filename;

public:

    Parser(string file);

    void parse(Anthill& anthill);
};

#endif