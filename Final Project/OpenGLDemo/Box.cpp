#include "Box.h"

Box::Box()
{
	setModelCount(1);
	init();
}

void Box::init()
{
	currentModel = mat4(1.0f);
	currentModel = glm::translate(currentModel, vec3(0.0f, 0.5f, 0.0f));
	currentModel = glm::scale(currentModel, vec3(0.92f, 0.92f, 0.92f));
	getModelMatrix(0) = currentModel;

}

void Box::draw(mat4 trans)
{
	cube->draw(trans);
}

float Box::getHeight()
{
	return 1.0f;
}
