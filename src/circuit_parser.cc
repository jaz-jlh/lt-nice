
#include "circuit_parser.hh"
#include "circuit_element.hh"
#include "circuit_elements/resistor.hh"

#include <iostream>

typedef std::vector<std::vector<std::string>> CircuitRepresentation; // for convenient referencing

#define TYPE_CIRCUIT    "CIRCUIT"
#define TYPE_ELEMENT    "ELEMENT"
#define TYPE_ATTRIBUTE  "ATTRIBUTE"
#define TYPE_SIMULATION "SIMULATION"
#define TYPE_PLOT       "PLOT"

CircuitParser::CircuitParser(std::string filename) {

}

const std::ifstream CircuitParser::readFile(const std::string filename) {
    std::ifstream infile(filename);
    return infile;
}

const Circuit CircuitParser::generateCircuit(const CircuitRepresentation circuit) {
    // for (CircuitRepresentation::iterator row = circuit.begin(); row != circuit.end(); ++row) {
    //     for(std::vector<std::string>::iterator cell = row->begin(); cell != row->end(); ++cell){
            
    //     }
    // }
    for (const auto& row : circuit) {
        std::string line_type = row[0];
        if(line_type == TYPE_CIRCUIT) {
            std::cout << "Generating circuit..." << std::endl;
        } else if (line_type == TYPE_ELEMENT) {

        } else if (line_type == TYPE_ATTRIBUTE) {

        } else if (line_type == TYPE_SIMULATION) {
            std::cout << "simulation not implemented yet, skipping..." << std::endl;
        } else if (line_type == TYPE_PLOT) {
            std::cout << "plots not implemented yet, skipping..." << std::endl;
        }
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

const CircuitElement CircuitParser::row_to_element(std::vector<std::string> row) {
    unsigned int element_id = std::stoi(row[1].substr(1));
    char element_type = row[2].at(0);
    CircuitElement new_element;
    switch (element_type) {
        case 'R':
            new_element = new Resistor(element_id, );
            break;
        case 'C':

            break;
        case 'V':

            break;
        default:
            std::cout << "Unrecognized element type in line: " << element_type << std::endl;
            break;
    }
}