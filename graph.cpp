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
 * directed or unidrected
 * First line = n
 * Second line = m
 * m lines with
 * Vertex_Idx1 Vertex1_tag Vertex_Idx2 Vertex2_tag Edge_Cost Tag_of_Edge
 * */

bool Graph::loadGraphFromFile(const char* fileName)
{
	int m, n;
	ifstream in(fileName);
	if(!in.good()) {
		cout << "Error! Could not open file " << endl;
		return false;
	}

	string dir;
	in >> dir;

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
		in >> idx1 >> tmpv1 >> idx2 >> tmpv2 >> tmpcost >> tmpe;
		
		v1.setValues(tmpv1, ALB, 0, NULL);
		v2.setValues(tmpv2, ALB, 0, NULL);
		e.setValues(v1, v2, tmpcost, tmpe);
		
		this->V.insert( pair<int, Vertex>(idx1, v1) );
		this->V.insert( pair<int, Vertex>(idx2, v2) );
		ed = make_pair(idx1, idx2);
		this->E.insert( pair < pair<int, int>, Edge >(ed, e) );

		adjmat[idx1][idx2] = 1;

		if(dir.compare(string("directed")) != 0) {
			adjmat[idx2][idx1] = 1;
		}
	}

	return true;
}

void Graph::printGraphInfo()
{
	cout << "Number of vertex = " << this->n << endl;
	cout << "Number of edges = " << this->n << endl;

	VertexSet::iterator itv;
	EdgeSet::iterator ite;
	Vertex v1;
	Vertex v2;

	cout << "Vertex set content: ";
	for(itv = this->V.begin(); itv != this->V.end(); ++itv) {
		cout << itv->second.getTag() << " ";
	}

	cout << endl;

	cout << "Edge set content: ";
	for(ite = this->E.begin(); ite != this->E.end(); ++ite) {
		v1 = (*ite).second.getOrigVertex();
		v2 = (*ite).second.getDestVertex();
		cout << v1.getTag() << " " << v2.getTag() << " ";
		cout << (*ite).second.getTag() << endl;
	}

	//Optional: Print adjmat, should be deleted when
	//everything is done
	for(int i = 0; i < this->n; ++i) {
		for(int j = 0; j < this->n; ++j)
			cout << adjmat[i][j] << " ";
		cout << endl;
	}
}


