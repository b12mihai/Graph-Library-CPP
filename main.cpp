#include "graph.h"
#include "vertex.h"
#include "edge.h"

int main()
{
	Graph G;
	
	if( G.loadGraphFromFile("sample-graphs/cormenBFSpg596.txt") == false) {
		cout << "Error opening file " << endl;
		return -1;
	}

	Vertex v = G.getVertexSet()[1];
	G.BFS(v);
	
	G.printGraphInfo();


	cout << "done" << endl;
	return 0;
}
