#include "vertex.h"
#include "edge.h"
#include <string>

using namespace std;

Edge::Edge (Vertex* firstVertex, Vertex* secVertex, double inCost, string tag) 
{
	this->orig = firstVertex;
	this->dest = secVertex;
	this->cost = inCost;
	this->tag.assign(tag);
}

void Edge::setValues(Vertex* firstVertex, Vertex* secVertex, double inCost, string tag)
{
	this->orig = firstVertex;
	this->dest = secVertex;
	this->cost = inCost;
	this->tag.assign(tag);
}

void Edge::setDestVertex(Vertex *dest)
{
	this->dest = dest;
}

void Edge::setOrigVertex(Vertex *orig)
{
	this->orig = orig;
}

void Edge::setCost(double cost)
{
	this->cost = cost;
}

void Edge::setTag(string tag)
{
	this->tag = tag;
}
    
Vertex* Edge::getDestVertex() 
{
	return this->dest;
}

Vertex* Edge::getOrigVertex() 
{
	return this->orig;
}

double Edge::getCost() 
{
	return this->cost;
}

string Edge::getTag() 
{
	return this->tag;    
}

