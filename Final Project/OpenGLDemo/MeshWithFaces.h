//Andrew Claudy

#pragma once
#include "glm/glm.hpp"
using glm::vec2;
using glm::vec3;
using glm::vec4;

#include "Face.h"
#include "HalfEdge.h"
#include "Vertex.h"

#include <deque>
using std::deque;

class MeshWithFaces
{
public:
	MeshWithFaces(void);
	~MeshWithFaces(void);
	deque<Face*> facesCollection;
	void subdivideCatmullClark(); //Executes a Catmull-Clark subdivide.
};

