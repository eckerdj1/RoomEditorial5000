//Andrew Claudy

#pragma once
#include <glm/glm.hpp>
using glm::vec2;
using glm::vec3;
using glm::vec4;

#include "Face.h"
#include "HalfEdge.h"
#include "Vertex.h"

#include <vector>
using std::vector;

class Mesh
{
public:
	Mesh(void);
	~Mesh(void);
	vector<Face> facesCollection;
	vector<HalfEdge> halfedgesCollection;
};

