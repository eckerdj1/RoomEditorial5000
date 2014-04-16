//Andrew Claudy

#pragma once
#include "HalfEdge.h"
#include <glm/glm.hpp>

class Face
{
public:
	Face(void);
	~Face(void);
	HalfEdge* halfedge;
	//TODO: should face know about half edge pointing to it?
	void useHalfEdges(); //TODO: needs to return something
	glm::vec4 calculateFaceNormal() const;
};

