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
* KVL - find loops in graph
  * DFS can find loops in an undirected graph
  * "The graph has a cycle if and only if there exists a back edge. A back edge is an edge that is from a node to itself (selfloop) or one of its ancestor in the tree produced by DFS forming a cycle." - https://stackoverflow.com/questions/19113189/detecting-cycles-in-a-graph-using-dfs-2-different-approaches-and-whats-the-dif
  * is analysis of loops containing loops necessary, or are only the smallest loops necessary to analyze?
    * it seems that analyzing all smallest loops is sufficient
* KCL - iterate over nodes
  * does current analysis have to come after voltage analysis? 