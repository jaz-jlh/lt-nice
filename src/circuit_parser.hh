#pragma once

#include "src/circuit.hh"

#include <fstream>

class CircuitParser {
    private:
        typedef std::vector<std::vector<std::string>> CircuitRepresentation; // for convenient referencing
        const std::ifstream readFile(const std::string filename);
        const CircuitRepresentation parseFile(std::ifstream filestream);
        const Circuit generateCircuit(const CircuitRepresentation circuit);
        const CircuitElement row_to_element(std::vector<std::string> row);
        Circuit _circuit;
    public:
        CircuitParser(std::string filename);
        ~CircuitParser();
};