
#include "circuit_parser.hh"
#include "circuit_element.hh"
#include "circuit_elements/resistor.hh"
#include "circuit_elements/capacitor.hh"
#include "circuit_elements/voltage_source.hh"

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

const Circuit CircuitParser::generateCircuit(const CircuitRepresentation circuit_representation) {
    Circuit circuit = Circuit();
    for (const auto& row : circuit_representation) {
        std::string line_type = row[0];
        if(line_type == TYPE_CIRCUIT) {
            std::cout << "Generating circuit..." << std::endl;
        } else if (line_type == TYPE_ELEMENT) {
            row_to_element(row);
            // create element
            // check if left node id exists
            // if it exists, attach element to it
            // if it does not exist, create it and attach
            // repeat for right node
            // functionize & pass in Circuit reference?
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

const CircuitElement CircuitParser::row_to_element(const std::vector<std::string> row) {
    const unsigned int element_id = std::stoi(row[2].substr(1));
    const char element_type = row[2].at(0);
    const double value = parseElementValue(row[3]);
    if (element_type == 'R') {
        CircuitElement new_element = Resistor(element_id, value);
        return new_element;
    } else if (element_type == 'C') {
        CircuitElement new_element = Capacitor(element_id, value);
        return new_element;
    } else if (element_type == 'V') {
        CircuitElement new_element = VoltageSource(element_id, value);
        return new_element;
    } else {
        std::cout << "Unrecognized element type in line: " << element_type << std::endl;
    } 
}

const double CircuitParser::parseElementValue(std::string raw_string) {
    double value = 0.0;
    char multiplier = ' ';
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