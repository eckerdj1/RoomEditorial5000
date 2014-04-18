//Andrew Claudy

#pragma once
#include <glm\glm.hpp>
using glm::vec3;
using glm::vec4;

static int idCounter = 0; //GLOBAL

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
	vec4 position;	//In model space coordinates
	vec3 color;		//RGB color
	vec4 normal;	//Normal
};

