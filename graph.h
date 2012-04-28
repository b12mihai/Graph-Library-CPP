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

class Graph {
	private:
		map <int, Vertex> V; //set of Vertexes
		map <pair<int, int>, Edge> E; //set of Edges
		int n; //number of vertex
		int m; //number of edges
		int **adjmat; //matrix of adjancency

	public:
		Graph();
		void insertVertex(Vertex v);
		void insertEdge(Edge e);

		bool loadGraphFromFile(const char* fileName);

};

#endif
