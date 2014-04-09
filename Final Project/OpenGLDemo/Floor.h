#pragma once
#include "Geometry.h"
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include <stdlib.h>
#include <string>
using glm::vec4;
using glm::vec3;
using glm::mat4;
using std::string;

class Geometry;

class Floor : public Geometry
{
public:
	Floor();
	Floor(int x, int z):xScale(x), zScale(z)
	{
		setModelCount(1);
		init();
	}
	~Floor();
	void init();
	void scale();
	void setSize(int x, int y);
	int getXsize();
	int getZsize();
	float getHeight();
	vec3 floorIndexToVec3(int x, int z);
	void draw(mat4 trans);

private:
	int xScale, zScale;
	mat4 currentModel;
};