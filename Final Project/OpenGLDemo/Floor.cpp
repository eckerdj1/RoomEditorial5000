#include "Floor.h"

Floor::Floor()
{
	setModelCount(1);
	xScale = 1;
	zScale = 1;
	init();
}

Floor::~Floor()
{

}


void Floor::init()
{
	currentModel = mat4(1.0f);
	currentModel = glm::translate(currentModel, vec3(0.0f, 0.0f, 0.0f));
	scale();
}


void Floor::setSize(int x, int z)
{
	xScale = x;
	zScale = z;
	init();
}

void Floor::scale()
{
	currentModel = glm::scale(currentModel, vec3(static_cast<float>(xScale), 0.01f, static_cast<float>(zScale)));
}

vec3 Floor::floorIndexToVec3(int x, int z)
{
	float xPos = -(xScale / 2.0f) + 0.5f + x;
	float zPos = -(zScale / 2.0f) + 0.5f + z;
	return vec3(xPos, 0.0f, zPos);
}

int Floor::getXsize()
{
	return xScale;
}

int Floor::getZsize()
{
	return zScale;
}

float Floor::getHeight()
{
	return 0.01f;
}

void Floor::draw(mat4 trans)
{
	mat4 mt = trans * currentModel;
	cube->draw(mt);
}
