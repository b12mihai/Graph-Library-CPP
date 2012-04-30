#ifndef __GRAPH__H__
#define __GRAPH__H__

#pragma once

#include "vertex.h"
#include "edge.h"
#include <string>
#include <vector>
#include <list>
#include <map>
#include <iostream>

using namespace std;

typedef map<int, Vertex> VertexSet;
typedef map<pair<int, int>, Edge> EdgeSet;

extern int t; //for time of discovery

class Graph {
	private:
		map <int, Vertex> V; //set of Vertexes
		map <pair<int, int>, Edge> E; //set of Edges
		int n; //number of vertex
		int m; //number of edges
		int **adjmat; //matrix of adjancency

	public:
		Graph();
		bool loadGraphFromFile(const char* fileName);
		void printGraphInfo();
		void clearVertex();
		void DFS();
		void DFSV(Vertex v);

};

#endif
