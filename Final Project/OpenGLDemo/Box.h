#pragma once
#include "Geometry.h"
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include <stdlib.h>
#include <string>
#include "Cube.h"
using glm::vec4;
using glm::vec3;
using glm::mat4;
using std::string;

class Box: public Geometry
{
public:
	Box();
	Box(int x, int y, int z):xScale(x), yScale(y), zScale(z)
	{
		setModelCount(1);
		init();
	}
	void init();
	void scale(float x, float y, float z);
	void setSize(int x, int y);
	void draw(mat4 trans);
	float getHeight();

private:
	float xScale, yScale, zScale;
	mat4 currentModel;
};