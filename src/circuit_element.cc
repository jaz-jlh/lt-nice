#include "circuit_element.hh"


CircuitElement::CircuitElement(unsigned int id, CircuitNode& left_node, CircuitNode& right_node) {
    _id = id;
    _left_node = left_node;
    _right_node = right_node;
}



void CircuitElement::set_value(double new_value) {
    _value = new_value;
}
double CircuitElement::get_value() {
    return _value;
}