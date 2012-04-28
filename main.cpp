#include "graph.h"
#include "vertex.h"
#include "edge.h"

int main()
{
	Graph G;
	
	if( G.loadGraphFromFile("sample-graphs/sd11pg3.txt") == false) {
		cout << "Error opening file " << endl;
		return -1;
	}

	G.printGraphInfo();


	cout << "done" << endl;
	return 0;
}
