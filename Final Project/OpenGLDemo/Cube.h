#pragma once
#define GLEW_STATIC
#include "glew.h"
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include <stdlib.h>
#include <string>
using glm::vec4;
using glm::vec3;
using std::string;
using glm::mat4;


#define BUFFER_OFFSET(bytes) ((GLvoid*) (bytes))

class Cube
{
public:
	static const int vertexCount = 24;
	static const int colorCount = 24;
	void initializeCubeCoords(unsigned int shaderProgram, float r, float g, float b);
	
	size_t sizeOfBuffer(string buffer);
	vec4* getVertexBuffer() const;
	vec3* getColorBuffer() const;
	void deleteBuffer();
	void draw(mat4 trans);

private:

	unsigned int modelLocation;

	vec3 colorData[colorCount];
	
	unsigned int vbo;
	unsigned int ibo;
	unsigned int nbo;
	unsigned int cbo;

	unsigned int vLocation;
	unsigned int vColor;
	unsigned int vNormal;

};