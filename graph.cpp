#include "graph.h"
#include "vertex.h"
#include "edge.h"

#include <fstream>
#include <utility>

Graph::Graph()
{
	this->m = 0;
	this->n = 0;
}

/* Structure of a file
 * First line = n
 * Second line = m
 * m lines with
 * Vertex_Idx1 Vertex1_tag Vertex_Idx2 Vertex2_tag Edge_Cost Tag_of_Edge
 * */

bool Graph::loadGraphFromFile(const char* fileName, bool isDirected)
{
	int m, n;
	ifstream in(fileName);
	if(!in.good()) {
		cout << "Error! Could not open file " << endl;
		return false;
	}

	//Load number of vertex and edges
	in >> n;
	in >> m;

	this->n = n; 
	this->m = m;
	int i;
	int idx1, idx2;
	double tmpcost;
	string tmpe, tmpv1, tmpv2;
	pair<int, int> ed;
	Vertex v1, v2;
	Edge e;

	//Initialize adjancency matrix with 0
	adjmat = new int*[n];
	for(i = 0; i < n; ++i)
		adjmat[i] = new int[n];

	for(i = 0; i < m; ++i) {
		in >> idx1 >> tmpv1 >> idx2 >> tmpv2 >> tmpcost >> tmps;
		
		v1.setValues(tmpv1, ALB, 0, NULL);
		v2.setValues(tmpv2, ALB, 0, NULL);
		e.setValues(&v1, &v2, tmpcost, tmps);
		
		this->V.insert( pair<int, Vertex>(idx1, v1) );
		this->V.insert( pair<int, Vertex>(idx2, v2) );
		ed = make_pair(idx1, idx2);
		this->E.insert( pair < pair<int, int>, Edge >(ed, e) );

		adjmat[idx1][idx2] = 1;

		if(isDirected == false) {
			adjmat[idx2][idx1] = 1;
		}
	}

	return true;
}
