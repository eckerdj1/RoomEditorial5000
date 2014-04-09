#include "Geometry.h"

Geometry::~Geometry()
{
	delete [] models;
}

mat4& Geometry::getModelMatrix(int index)
{
	return models[index];
}

void Geometry::draw(unsigned int mm, mat4 transform)
{
}

void Geometry::setCube(Cube* cube)
{
	this->cube = cube;
}

void Geometry::setModelCount(int c)
{
	modelCount = c;
	models = new mat4[modelCount];
}

int Geometry::getModelCount()
{
	return modelCount;
}
