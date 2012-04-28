#include <string>
#include "vertex.h"

using namespace std;

/* Vertex::Vertex(string tag, enum Color color, double dist, Vertex* pred)
{
	this->tag.assign(tag);
	this->color = color;
	this->dist = dist;
	this->pred = pred;
} */


void Vertex::setValues (string tag, enum Color color, double dist, Vertex* pred)
{	
	this->tag.assign(tag);
	this->color = color;
	this->dist = dist;
	this->pred = pred;
}

string Vertex::getTag()
{
	return this->tag;
}

void Vertex::setTag(string tag)
{
	this->tag.assign(tag);
}

enum Color Vertex::getColor()
{
	return this->color;
}

void Vertex::setColor(enum Color color)
{
	this->color = color;
}

double Vertex::getDist()
{
	return this->dist;
}

void Vertex::setDist(double dist)
{
	this->dist = dist;
}

Vertex* Vertex::getPred()
{
	return this->pred;
}

void Vertex::setPred(Vertex* v)
{
	this->pred = v;
}
