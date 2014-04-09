#include "Table.h"

Table::Table()
{
	setModelCount(5);
	init();
}

void Table::init()
{
	currentModel = mat4(1.0f);

	//table top
	currentModel = glm::translate(currentModel, vec3(0.0f, 1.2f, 0.0f));
	currentModel = glm::scale(currentModel, vec3(1.0f, 0.09f, 1.0f));
	getModelMatrix(0) = currentModel;

	//front right leg
	currentModel = getModelMatrix(1);
	currentModel = mat4(1.0f);
	currentModel = glm::translate(currentModel, vec3(0.4f, 0.0f, 0.4f));
	currentModel = glm::scale(currentModel, vec3(0.09f, 1.2f, 0.09f));
	getModelMatrix(1) = currentModel;

	//front left leg
	currentModel = getModelMatrix(2);
	currentModel = mat4(1.0f);
	currentModel = glm::translate(currentModel, vec3(-0.4f, 0.0f, 0.4f));
	currentModel = glm::scale(currentModel, vec3(0.09f, 1.2f, 0.09f));
	getModelMatrix(2) = currentModel;

	//back left leg
	currentModel = getModelMatrix(3);
	currentModel = mat4(1.0f);
	currentModel = glm::translate(currentModel, vec3(-0.4f, 0.0f, -0.4f));
	currentModel = glm::scale(currentModel, vec3(0.09f, 1.2f, 0.09f));
	getModelMatrix(3) = currentModel;

	//back right leg
	currentModel = getModelMatrix(4);
	currentModel = mat4(1.0f);
	currentModel = glm::translate(currentModel, vec3(0.4f, 0.0f, -0.4f));
	currentModel = glm::scale(currentModel, vec3(0.09f, 1.2f, 0.09f));
	getModelMatrix(4) = currentModel;
}

void Table::draw(mat4 trans)
{
	mat4 m(1.0f);
	for (int i=0; i<getModelCount(); ++i)
	{
		m = trans * getModelMatrix(i);
		cube->draw(m);
	}

}

float Table::getHeight()
{
	return 1.29f;
}
