#pragma once
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include <stdlib.h>
#include <string>
#include "Cube.h"
using glm::vec4;
using glm::vec3;
using glm::mat4;
using std::string;

class Geometry
{
public:
	virtual ~Geometry();
	mat4& getModelMatrix(int index);
	void setCube(Cube* cube);
	void draw(unsigned int mm, mat4 transform);
	void setModelCount(int c);
	int getModelCount();
	virtual float getHeight() = 0;
	virtual void draw(mat4 trans) = 0;
	void setPos(int x, int z) {xPos = x; zPos = z;}
	
	unsigned int modelLocation;
	Cube* cube;

private:
	mat4* models;
	int modelCount;
	int xPos, zPos;

};
