#pragma once
#include <glm\glm.hpp>
using glm::vec3;
using glm::vec4;
class Vertex
{
public:
	Vertex(void);
	~Vertex(void);
	int id;
	glm::vec4 position; //In model space coordinates
	glm::vec3 color;	//RGB color
	glm::vec4 normal;	//Normal
};

