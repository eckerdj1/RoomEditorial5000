//Andrew Claudy
#pragma once
#include <glm\glm.hpp>
using glm::vec3;
using glm::vec4;
#include "MyStuff.h"

//static int idCounter = 0; //GLOBAL

class HalfEdge;

class Vertex
{
public:
	Vertex(void);
	Vertex(const Vertex& copy); //Copy CTOR
	Vertex& operator=(const Vertex& object);
	Vertex(vec4 position_, vec3 color_, vec4 normal_);
	Vertex(vec4 position_, vec3 color_);
	Vertex(vec3 position_, vec3 color_, vec4 normal_);
	Vertex(vec3 position_, vec3 color_);
	~Vertex(void);
	int id;
	bool isBuffered;
	unsigned int index;
	vec4 position;	//In model space coordinates
	vec3 color;		//RGB color
	vec4 normal;	//Normal (TODO: needs to be a vertex normal, not a face normal)

	HalfEdge* myHalfEdge;

	const vec4 calculateMidpoint(const vec4& withThisLocation) const;
	const vec4 calculateMidpoint(const Vertex& withThisLocation) const;

	void calculateNormal();
};

const vec4 calculateMidpoint(const vec4& ptA, const vec4& ptB); //Nonmember helper function