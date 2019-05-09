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
  * Important characteristics: Resistance
* Capacitor
  * Important characteristics: Capacitance
* Inductor
  * Important characteristics: Resistance, Inductance
* Diode
  * Important characteristics: Direction, Breakdown Voltage
* Voltage source/function generator
  * Important characteristics: just Voltage?
* Transistor - special case of a node - how does this fit into circuit representation?
  * BJTs
    * Connections: Collector, Emitter, Base
    * Important characteristics: Type, Activation Voltage
    * Types:
      * NPN: V_BE > 0.7V allows current to flow from Collector to Emitter
      * PNP: V_CE - V_BE > 0.7V allows current to flow from C->E
    * 
  * FETs
    * Connections: Drain, Source, Gate
    * Important characteristics: Type, Pinch-Off Voltage
    * ![3D graph of JFET behavior](https://images.slideplayer.com/26/8302733/slides/slide_69.jpg)
    * N-Channel
      * "default on"
      * I_DS is proportional to V_GS (ohmic) for small values of V_GS up to pinch-off voltage
      * After pinch-off voltage, I_DS is essentially constant (I_DS_max)
      * more negative V_GS -> less current
    * P-Channel
      * "default off"

### Analysis
* KVL - find loops in graph
  * DFS can find loops in an undirected graph
  * "The graph has a cycle if and only if there exists a back edge. A back edge is an edge that is from a node to itself (selfloop) or one of its ancestor in the tree produced by DFS forming a cycle." - https://stackoverflow.com/questions/19113189/detecting-cycles-in-a-graph-using-dfs-2-different-approaches-and-whats-the-dif
  * is analysis of loops containing loops necessary, or are only the smallest loops necessary to analyze?
    * it seems that analyzing all smallest loops is sufficient
* KCL - iterate over nodes
  * does current analysis have to come after voltage analysis? 




### Code Structure