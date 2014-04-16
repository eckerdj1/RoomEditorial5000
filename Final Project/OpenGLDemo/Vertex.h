#pragma once
#include <glm\glm.hpp>
using glm::vec3;
using glm::vec4;

static int idCounter = 0;

class Vertex
{
public:
	Vertex(void);
	Vertex(const Vertex& copy); //Copy CTOR
	Vertex(vec4 position_, vec3 color_, vec4 normal_);
	~Vertex(void);
	int id;
	vec4 position; //In model space coordinates
	vec3 color;	//RGB color
	vec4 normal;	//Normal
};

