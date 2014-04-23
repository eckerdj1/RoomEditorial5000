//Andrew Claudy
#pragma once
#include "Face.h"
#include "Vertex.h"

//Forward Declaration
class Face;

//COUNTER CLOCKWISE WINDING
class HalfEdge
{
public:
	HalfEdge(void);
	HalfEdge(const HalfEdge& copy);
	HalfEdge& operator=(const HalfEdge& rhs) { return *this; }
	~HalfEdge(void);
	int id;
	Face* ownerFace;
	Vertex* vertex;
	HalfEdge* symetric;
	HalfEdge* nextEdge;
};
