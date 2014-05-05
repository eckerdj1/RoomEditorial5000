//Author(s):Andrew Claudy, Dan Ecker
//COMP 361
//Due May 5th, 2014
//Desc: Points to exactly one halfedge.

#pragma once
#include "HalfEdge.h"
#include "Vertex.h"

#include <glm/glm.hpp>
using glm::vec2;
using glm::vec3;
using glm::vec4;

#include <exception>
using std::exception;

#include <vector>
using std::vector;

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
	Face(Vertex* one_, 
		 Vertex* two_, 
		 Vertex* three_, 
		 Vertex* four_);
	Face(vector<vec4> points);

	HalfEdge* at(int i);

	void addNewEdgeCCW(HalfEdge* he);
	void addNewEdgeCW(HalfEdge* he);
	void finishFace();
	void useHalfEdges(); //TODO: needs to return something
	void assignOwnerFace();
	void setSymAt(int i, HalfEdge* he);
	HalfEdge*& lastEdge();
	vec4 calculateFaceNormal() const;
	vector<Face*> splitIntoFourFaces();
	vec4 calculateFaceCenterAveragePoint() const;

	int id;
	vec4 normal;
};
