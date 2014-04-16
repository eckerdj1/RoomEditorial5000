//Andrew Claudy

#pragma once
#include "HalfEdge.h"
#include "Vertex.h"
#include <glm/glm.hpp>

//Forward declaration
class HalfEdge;
class Vertex;

class Face //Four vertex plane
{
public:
	Face(void);
	~Face(void);
	HalfEdge* halfedge;
	Face(Vertex one, Vertex two, Vertex three, Vertex four);
	void useHalfEdges(); //TODO: needs to return something
	glm::vec4 calculateFaceNormal() const;
};

