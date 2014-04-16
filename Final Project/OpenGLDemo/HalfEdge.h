//Andrew Claudy
#pragma once

#include "Vertex.h"

//COUNTER CLOCKWISE WINDING
class HalfEdge
{
public:
	HalfEdge(void);
	~HalfEdge(void);
	int id;
	Vertex* vertex;
	HalfEdge* symetric;
	HalfEdge* nextEdge;
};

