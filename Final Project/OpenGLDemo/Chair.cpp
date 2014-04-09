#include "Chair.h"

Chair::Chair()
{
	setModelCount(6);
	init();
}

void Chair::init()
{
	//seat
	//currentModel = getModelMatrix(0);
	currentModel = mat4(1.0f);
	currentModel = glm::translate(currentModel, vec3(0.0f, 0.85f, 0.0f));
	currentModel = glm::scale(currentModel, vec3(0.8f, 0.05f, 0.8f));
	getModelMatrix(0) = currentModel;

	//front right leg
	//currentModel = getModelMatrix(1);
	currentModel = mat4(1.0f);
	currentModel = glm::translate(currentModel, vec3(0.35f, 0.0f, 0.35f));
	currentModel = glm::scale(currentModel, vec3(0.09f, 0.85f, 0.09f));
	getModelMatrix(1) = currentModel;

	//front left leg
	//currentModel = getModelMatrix(2);
	currentModel = mat4(1.0f);
	currentModel = glm::translate(currentModel, vec3(-0.35f, 0.0f, 0.35f));
	currentModel = glm::scale(currentModel, vec3(0.09f, 0.85f, 0.09f));
	getModelMatrix(2) = currentModel;

	//back left leg
	//currentModel = getModelMatrix(3);
	currentModel = mat4(1.0f);
	currentModel = glm::translate(currentModel, vec3(-0.35f, 0.0f, -0.35f));
	currentModel = glm::scale(currentModel, vec3(0.09f, 0.85f, 0.09f));
	getModelMatrix(3) = currentModel;

	//back right leg
	//currentModel = getModelMatrix(4);
	currentModel = mat4(1.0f);
	currentModel = glm::translate(currentModel, vec3(0.35f, 0.0f, -0.35f));
	currentModel = glm::scale(currentModel, vec3(0.09f, 0.85f, 0.09f));
	getModelMatrix(4) = currentModel;

	//seat back
	//currentModel = getModelMatrix(5);
	currentModel = mat4(1.0f);
	currentModel = glm::translate(currentModel, vec3(0.0f, 0.85f, -0.35f));
	currentModel = glm::scale(currentModel, vec3(0.78f, 0.95f, 0.05f));
	getModelMatrix(5) = currentModel;
	
}

float Chair::getHeight()	
{
	return 0.55f;
}

void Chair::draw(mat4 trans)
{
	mat4 m(1.0f);
	for (int i=0; i<getModelCount(); ++i)
	{
		m = trans * getModelMatrix(i);
		cube->draw(m);
	}

}
