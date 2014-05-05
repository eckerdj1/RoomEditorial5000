//Author(s):Andrew Claudy, Dan Ecker
//COMP 361
//Due May 5th, 2014
//Desc: 
#pragma once
#include "Face.h"
#include "Vertex.h"
//#include "MyStuff.h"

//Forward Declaration
class Face;

struct triangle
{
	triangle(vec4 _p0, vec4 _p1, vec4 _p2)
	{
		p0 = _p0;
		p1 = _p1;
		p2 = _p2;

		vec4 e1 = p1 - p0;
		vec4 e2 = p2 - p0;
		normal = glm::normalize(cross(e2, e1));
	};
	vec4 p0;
	vec4 p1;
	vec4 p2;
	vec4 normal;
};

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

	void setSym(HalfEdge* he);
	void copyPointers(HalfEdge* he);

	HalfEdge* previousEdge();


};
