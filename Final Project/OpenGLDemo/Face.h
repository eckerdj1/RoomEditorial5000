//Andrew Claudy

#pragma once
#include "HalfEdge.h"
#include "Vertex.h"
#include <glm/glm.hpp>
using glm::vec2;
using glm::vec3;
using glm::vec4;

//Forward declaration
class HalfEdge;
class Vertex;

class Face //Four vertex plane
{
public:
	Face(void);
	~Face(void);
	HalfEdge* HE0; //I numbered the face's half edges HE0, HE1, HE2, HE3
	Face(const Vertex& one_, 
		 const Vertex& two_, 
		 const Vertex& three_, 
		 const Vertex& four_);
	void useHalfEdges(); //TODO: needs to return something
	vec4 calculateFaceNormal() const;
};