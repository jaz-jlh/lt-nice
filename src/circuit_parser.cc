
#include "circuit_parser.hh"

typedef std::vector<std::vector<std::string>> CircuitRepresentation; // for convenient referencing

CircuitParser::CircuitParser(std::string filename) {

}

const std::ifstream CircuitParser::readFile(const std::string filename) {
    std::ifstream infile(filename);
    return infile;
}

const Circuit CircuitParser::generateCircuit(const CircuitRepresentation circuit) {
    for (CircuitRepresentation::iterator it = circuit.begin(); it != circuit.end(); ++it) {
        
    }
}

// https://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c

const CircuitRepresentation CircuitParser::parseFile(std::ifstream filestream) {
    // iterate over lines in file
    CircuitRepresentation circuit_representation;
    for (std::string line; getline(filestream, line);) {
        std::vector<std::string> line_items;
        std::stringstream lineStream(line);
        std::string cell;
        // iterate over fields in line
        while(getline(lineStream, cell, ',')) {
            line_items.push_back(cell);
        }
        circuit_representation.push_back(line_items);
    }
    return circuit_representation;
}