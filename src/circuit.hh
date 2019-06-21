#pragma once

#include "src/circuit_element.hh"
#include "src/circuit_node.hh"

#include <vector>
#include <map>

class Circuit {
    private:
        std::map<unsigned int, CircuitNode&> _nodes;
        std::map<unsigned int, CircuitElement&> _elements;
        void addWire(CircuitNode& first_node, CircuitNode& second_node);
    public:
        Circuit(std::string filename);
        ~Circuit();
        CircuitElement& getElement(const unsigned int id) const;
        CircuitNode& getNode(const unsigned int id) const;
        void addElement(CircuitElement new_element);
};
