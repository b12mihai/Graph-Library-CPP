#include "graph.h"
#include "vertex.h"
#include "edge.h"

#include <fstream>
#include <utility>
#include <stack>
#include <queue>

int t;

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
		
		v1.setValues(tmpv1, ALB, 0, NULL, idx1);
		v2.setValues(tmpv2, ALB, 0, NULL, idx2);
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

VertexSet Graph::getVertexSet()
{
	return this->V;
}

void Graph::printGraphInfo()
{
	cout << "Number of vertex = " << this->n << endl;
	cout << "Number of edges = " << this->m << endl;

	VertexSet::iterator itv;
	EdgeSet::iterator ite;
	Vertex v1;
	Vertex v2;

	cout << "Vertex set content: ";
	for(itv = this->V.begin(); itv != this->V.end(); ++itv) {
		cout << itv->second.getTag() << " ";
		cout << itv->second.getDist() << " ";
		cout << endl;
	}

	cout << endl;

	cout << "Edge set content: " << endl;
	for(ite = this->E.begin(); ite != this->E.end(); ++ite) {
		v1 = (*ite).second.getOrigVertex();
		v2 = (*ite).second.getDestVertex();
		cout << v1.getTag() << " " << v2.getTag() << " ";
		cout << v1.getIndex() << " " << v2.getIndex() << " ";
		cout << (*ite).second.getTag() << endl;
	}

	//Optional: Print adjmat, should be deleted when
	//everything is done
	for(int i = 0; i < this->n; ++i) {
		for(int j = 0; j < this->n; ++j)
			cout << adjmat[i][j] << " ";
		cout << endl;
	}

	this->clearVertex();
}

void Graph::clearVertex()
{
	VertexSet::iterator iter;
	for(iter = this->V.begin(); iter != this->V.end(); ++iter) {
		(*iter).second.setColor(ALB);
		(*iter).second.setPred(NULL);
	}
}

//TODO - make DFS exploration work
void Graph::DFS()
{
	this->clearVertex();
	t = 0;

	VertexSet::iterator iter;
	Vertex v;

	for(iter = this->V.begin(); iter != this->V.end(); ++iter) {
		v = (*iter).second;
		if(v.getColor() == ALB)
			this->DFSV((*iter).second);
	}


}

//TODO - make this buggy function work
void Graph::DFSV(Vertex u)
{
	int j, i;
	int uidx = u.getIndex();
	pair<int, int> ed;
	u.setColor(GRI);
	++t;
	u.setStart(t);
	VertexSet::iterator iter;
    Vertex *v, *x;
	stack<Vertex*> s;

	s.push(&u);

	while(!s.empty()) {
		x = s.top();
		s.pop();
		i = x->getIndex();
		if(x->getColor() == ALB) {
			this->V[i].setColor(GRI);	
		}
		for(iter = this->V.begin(); iter != this->V.end(); ++iter) {
			v = &(iter->second);
			j = v->getIndex();
			if(v->getColor() == ALB && this->adjmat[uidx][j] == 1) {
				s.push(v);
				cout << v->getIndex() << " ";
				this->V[j].setPred(&u);
			}
		}

	}
} 
void Graph::BFS(Vertex s)
{
	VertexSet::iterator iter;
	queue<Vertex> q;
	Vertex u;

	for(iter = this->V.begin(); iter != this->V.end(); ++iter) {
		iter->second.setColor(ALB);
		iter->second.setPred(NULL);
		iter->second.setDist(INF);
	}
	s.setDist(0);
	s.setPred(NULL);
	s.setColor(GRI);
	q.push(s);
	int j, uidx, i;

	while(!q.empty()) {
		u = q.front();
		q.pop();
		uidx = u.getIndex();
		cout << uidx << " " <<u.getTag() << " " << u.getDist() <<" "<<endl;
		for(iter = this->V.begin(); iter != this->V.end(); ++iter) {
			j = iter->second.getIndex();
			if(this->adjmat[uidx][j] == 1 && iter->second.getColor() == ALB) {
				i = iter->second.getIndex();
				this->V[i].setColor(GRI);
				this->V[i].setDist(u.getDist() + 1);
				this->V[i].setPred(&u);
				q.push(iter->second);
			}
		}
		u.setColor(NEGRU);
	}
}
