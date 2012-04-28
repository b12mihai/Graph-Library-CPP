#pragma once

#ifndef __EDGE_H__
#define __EDGE_H__

#include "vertex.h"

#include <string>

using namespace std;

class Edge;

class Edge {
  private:
    Vertex *orig;		//the originating vertex
    Vertex *dest;		//the destination vertex
    double cost;		//cost of the edge
    string tag;			//tag of the edge

  public:
    Edge (Vertex* firstVertex, Vertex* secVertex, double inCost, string tag);
	void setValues(Vertex* firstVertex, Vertex* secVertex, double inCost, string tag);

	//setters
	void setDestVertex(Vertex* v);
	void setOrigVertex(Vertex* v);
	void setCost(double cost);
	void setTag(string tag);

	//getters
    Vertex* getDestVertex();
    Vertex* getOrigVertex();
	double getCost();
	string getTag();
};

#endif
