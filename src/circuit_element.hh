#pragma once

#include "circuit_node.hh"

class CircuitElement {
    private:
        unsigned int _id;
        CircuitNode& _left_node;
        CircuitNode& _right_node;
        double _value;
    public:
        CircuitElement();
        CircuitElement(unsigned int id, double value);
        CircuitElement(unsigned int id, CircuitNode& left_node, CircuitNode& right_node);
        ~CircuitElement();
        void add_connection(CircuitElement& other_element, CircuitNode& other_node);
        void set_value(double new_value);
        double get_value();
};