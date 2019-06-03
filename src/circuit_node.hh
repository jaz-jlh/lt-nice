#pragma once

#include "src/circuit_element.hh"

#include <vector>

class CircuitNode {
    private:
        unsigned int id;
        std::vector<CircuitElement&> _elements;
    public:
        CircuitNode();
        ~CircuitNode();
        void add_element(CircuitElement&);
};