Graph Library in C++
====================

This is a simple implementation in C++ for graph
algorithms.

Class Graph has all the relevant functions for graph algorithms

Graphs are represented using adjancency matrix, which is an inneficient
solution for representing sparse graphs, as memory cost is O(n^2) in this
case.

Adjacency list might save memory, but with this representation is slower to find
the presence or absence of a specific edge.
