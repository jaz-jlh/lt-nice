
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
    CircuitElement new_element = CircuitElement();
    switch (element_type) {
        case 'R':
            new_element = Resistor(element_id, );
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

const double CircuitParser::parseElementValue(std::string raw_string) {
    double value = 0.0;
    char multiplier = '';
    // check the string to see if we have a multiplier
    if (isalpha(raw_string.back())) {
        multiplier = raw_string.back();
        raw_string.pop_back(); // remove the multiplier so we can parse the number
    }
    if (raw_string.find('.') == std::string::npos) {
        // we have an int value
        value = double(std::stoi(raw_string));
    } else {
        // we have a float value
        value = std::stod(raw_string);
    }
    switch (multiplier) {
    case 'u':
        value /= 1000000;
        break;
    case 'm':
        value /= 1000;
        break;
    case 'M':
        value *= 1000000;
        break;
    case 'k':
        value *= 1000;
        break;
    default:
        std::cout << "Invalid/unsupported multiplier: " << multiplier << std::endl;
        break;
    }
}