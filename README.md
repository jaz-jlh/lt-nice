# lt-nice

lt-nice is a circuit simulator written in c++

## Design

### Circuit Representation
Circuits are represented as an undirected graph:
* Edges are circuit components
* Output signals are measured at nodes
The undirected graph is represented in an adjacency matrix with references to the circuit components as entries in the matrix

#### Circuit Elements
* Resistor
* Capacitor
* Inductor
* Voltage source/function generator
* Transistor - is this a special case of a node?

### Analysis
* KVL - find loops in graph - note we have to start with the outermost loops first
* KCL - iterate over nodes 