#pragma once

class CircuitElement {
    private:
        unsigned int id;
        CircuitNode& _left_node;
        CircuitNode& _right_node;
    public:
        CircuitElement();
        ~CircuitElement();
        void add_connection(CircuitElement& other_element, CircuitNode& other_node);
};