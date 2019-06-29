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
        CircuitElement(const unsigned int id, const double value);
        CircuitElement(unsigned int id, CircuitNode& left_node, CircuitNode& right_node);
        ~CircuitElement();
        void add_connection(CircuitElement& other_element, CircuitNode& other_node);
        void set_value(double new_value);
        void set_left_node(CircuitNode& left_node);
        void set_right_node(CircuitNode& right_node);        
        double get_value();
};