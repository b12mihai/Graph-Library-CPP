#ifndef __VERTEX_H__
#define __VERTEX_H__

#pragma once

#include <string>

using namespace std;

enum Color {
    ALB,
    GRI,
    NEGRU
};

class Vertex;

class Vertex {
	private:
		string tag;
		enum Color color;
		double dist;
//		int start;
//		int stop;	
		Vertex* pred;
	public:
		//Vertex(string tag, enum Color color, double dist, Vertex* pred);
		void setValues (string tag, enum Color color, double dist, Vertex* pred);
		string getTag();
		void setTag(string tag);
		enum Color getColor();
		void setColor(enum Color c);
		double getDist();
		void setDist(double d);
		Vertex* getPred();
		void setPred(Vertex* v);
		void setStart(int start);
		int getStart();
		void setStop(int stop);
		int getStop();

  
};



#endif
