//Andrew Claudy

#pragma once
#include "HalfEdge.h"
#include "Vertex.h"

#include <glm/glm.hpp>
using glm::vec2;
using glm::vec3;
using glm::vec4;

#include <exception>
using std::exception;

//Forward declaration
class HalfEdge;
class Vertex;
class NotPlanarException : public exception
{
	const char* what() const {
		return "Arguments passed were not planar. The points comprising a face must form a plane.";
	}
};

class NotConvexException : public exception 
{
	const char* what() const {
		return "Arguments passed were not convex. Next time, only send points that form a convex polygon.";
	}
};

class NotInitializedException : public exception
{
	const char* what() const {
		return "Half Edge zero HE0 is not pointing to anything.";
	}
};

class Face //Four vertex plane
{
public:
	Face(void);
	~Face(void);
	HalfEdge* HE0; //I numbered the face's halfedges HE0, HE1, HE2, HE3
	Face(const Vertex& one_, 
		 const Vertex& two_, 
		 const Vertex& three_, 
		 const Vertex& four_);
	void useHalfEdges(); //TODO: needs to return something
	vec4 calculateFaceNormal() const;

	vec4 calculateFaceCenterAveragePoint() const;
};

