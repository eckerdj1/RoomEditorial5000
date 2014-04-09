#include "Cube.h"

void Cube::initializeCubeCoords(unsigned int shaderProgram, float r, float g, float b)
{
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &nbo);
	glGenBuffers(1, &ibo);
	glGenBuffers(1, &cbo);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	vLocation = glGetAttribLocation(shaderProgram, "vs_position");
	vColor = glGetAttribLocation(shaderProgram, "vs_color");
	vNormal = glGetAttribLocation(shaderProgram, "vs_normal");
	modelLocation = glGetUniformLocation(shaderProgram, "u_modelMatrix");

	vec4 tempPoints[] = 
	{
		//left 
		vec4(-0.5f, 1.0f, -0.5f, 1.0f),  //left top back
		vec4(-0.5f, 0.0f, -0.5f, 1.0f), //left bottom back
		vec4(-0.5f, 0.0f, 0.5f, 1.0f),	 //left bottom front
		vec4(-0.5f, 1.0f, 0.5f, 1.0f),   //left top front

		//right 
		vec4(0.5f, 1.0f, 0.5f, 1.0f),    //right top front
		vec4(0.5f, 0.0f, 0.5f, 1.0f),   //right bottom front
		vec4(0.5f, 0.0f, -0.5f, 1.0f),  //right bottom back
		vec4(0.5f, 1.0f, -0.5f, 1.0f),   //right top back

		//front
		vec4(-0.5f, 1.0f, 0.5f, 1.0f), //left top front
		vec4(-0.5f, 0.0f, 0.5f, 1.0f), //left bottom front
		vec4(0.5f, 0.0f, 0.5f, 1.0f),  //right bottom front
		vec4(0.5f, 1.0f, 0.5f, 1.0f),  //right top front

		//back
		vec4(-0.5f, 1.0f, -0.5f, 1.0f), //left top back
		vec4(-0.5f, 0.0f, -0.5f, 1.0f), //left bottom back
		vec4(0.5f, 0.0f, -0.5f, 1.0f),  //right bottom back
		vec4(0.5f, 1.0f, -0.5f, 1.0f),   //right top back

		//top face
		vec4(-0.5f, 1.0f, -0.5f, 1.0f), //left top back
		vec4(-0.5f, 1.0f, 0.5f, 1.0f),  //left top front
		vec4(0.5f, 1.0f, 0.5f, 1.0f),   //right top front
		vec4(0.5f, 1.0f, -0.5f, 1.0f),  //right top back

		//bottom face
		vec4(-0.5f, 0.0f, 0.5f, 1.0f),  //left bottom front
		vec4(-0.5f, 0.0f, -0.5f, 1.0f), //left bottom back
		vec4(0.5f, 0.0f, -0.5f, 1.0f),  //right bottom back
		vec4(0.5f, 0.0f, 0.5f, 1.0f)    //right bottom front
	};
	unsigned int tempInd[] = 
	{
		//left
		0, 1, 2,	
		3, 0, 2,
		//right
		4, 5, 6,
		7, 4, 6,
		//front
		8, 9, 10,
		11, 8, 10,
		//back
		12, 13, 14,
		15, 12, 14,
		//top
		16, 17, 18,
		19, 16, 18,
		//bottom
		20, 21, 22,
		23, 20, 22
	};
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 36 * sizeof(unsigned int), tempInd, GL_STATIC_DRAW);

	vec4 tempData[] = 
	{   //left face
		vec4(-0.5f, 0.0f, -0.5f, 1.0f), //left bottom back
		vec4(-0.5f, 0.0f, 0.5f, 1.0f),	 //left bottom front
		vec4(-0.5f, 1.0f, 0.5f, 1.0f),   //left top front
		vec4(-0.5f, 1.0f, -0.5f, 1.0f),  //left top back
		//right face
		vec4(0.5f, 0.0f, -0.5f, 1.0f),  //right bottom back
		vec4(0.5f, 1.0f, -0.5f, 1.0f),   //right top back
		vec4(0.5f, 1.0f, 0.5f, 1.0f),    //right top front
		vec4(0.5f, 0.0f, 0.5f, 1.0f),   //right bottom front
		//front face
		vec4(0.5f, 1.0f, 0.5f, 1.0f),   //right top front
		vec4(-0.5f, 1.0f, 0.5f, 1.0f),  //left top front
		vec4(-0.5f, 0.0f, 0.5f, 1.0f), //left bottom front
		vec4(0.5f, 0.0f, 0.5f, 1.0f),  //right bottom front
		//back face
		vec4(-0.5f, 1.0f, -0.5f, 1.0f),  //left top back
		vec4(0.5f, 1.0f, -0.5f, 1.0f),   //right top back
		vec4(0.5f, 0.0f, -0.5f, 1.0f),  //right bottom back
		vec4(-0.5f, 0.0f, -0.5f, 1.0f), //left bottom back
		//top face
		vec4(-0.5f, 1.0f, -0.5f, 1.0f), //left top back
		vec4(-0.5f, 1.0f, 0.5f, 1.0f),  //left top front
		vec4(0.5f, 1.0f, 0.5f, 1.0f),   //right top front
		vec4(0.5f, 1.0f, -0.5f, 1.0f),  //right top back
		//bottom face
		vec4(-0.5f, 0.0f, -0.5f, 1.0f), //left bottom back
		vec4(-0.5f, 0.0f, 0.5f, 1.0f),  //left bottom front
		vec4(0.5f, 0.0f, 0.5f, 1.0f),   //right bottom front
		vec4(0.5f, 0.0f, -0.5f, 1.0f)  //right bottom back
	};
	//vec3 tempColorData[] = 
	//{   //left face blue
	//	vec3(0.0f, 0.0f, 1.0f), //left bottom back
	//	vec3(0.0f, 0.33f, 0.7f),	 //left bottom front
	//	vec3(0.0f, 0.33f, 0.7f),   //left top front
	//	vec3(0.0f, 0.0f, 1.0f),  //left top back
	//	//right face
	//	vec3(0.0f, 0.3f, 0.18f),  //right bottom back
	//	vec3(0.0f, 0.3f, 0.18f),   //right bottom front
	//	vec3(0.0f, 1.0f, 0.28f),    //right top front
	//	vec3(0.0f, 1.0f, 0.28f),   //right top back
	//	//back face red
	//	vec3(1.0f, 0.0f, 0.0f),  //right bottom back
	//	vec3(0.6f, 0.0f, 0.23f),   //right top back
	//	vec3(0.6f, 0.0f, 0.23f),  //left top back
	//	vec3(1.0f, 0.0f, 0.0f), //left bottom back
	//	//front face red
	//	vec3(1.0f, 0.0f, 0.0f),  //right bottom front
	//	vec3(0.87f, 0.3f, 0.0f),  //right top front
	//	vec3(1.0f, 0.0f, 0.0f),  //left top front
	//	vec3(0.87f, 0.3f, 0.0f),  //left bottom front
	//	//top face cyan?
	//	vec3(0.0f, 0.5f, 1.0f), //left top back
	//	vec3(0.0f, 0.5f, 1.0f),  //left top front
	//	vec3(0.0f, 1.0f, 0.8f),   //right top front
	//	vec3(0.0f, 1.0f, 0.8f),  //right top back
	//	//bottom face purple?
	//	vec3(0.87f, 0.3f, 0.0f), //left bottom back
	//	vec3(0.4f, 0.4f, 1.0f),  //left bottom front
	//	vec3(0.2f, 0.01f, 0.7f),   //right bottom front
	//	vec3(0.9f, 0.0f, 0.6f)  //right bottom back
	//};
	vec3 tempColorData[] = 
	{   //left face blue
		vec3(r, g, b),  //left bottom back
		vec3(r, g, b),  //left bottom front
		vec3(r, g, b),  //left top front
		vec3(r, g, b),  //left top back
		//right face
		vec3(r, g, b),  //right bottom back
		vec3(r, g, b),  //right bottom front
		vec3(r, g, b),  //right top front
		vec3(r, g, b),  //right top back
		//back face red
		vec3(r, g, b),  //right bottom back
		vec3(r, g, b),  //right top back
		vec3(r, g, b),  //left top back
		vec3(r, g, b),  //left bottom back
		//front face red
		vec3(r, g, b),  //right bottom front
		vec3(r, g, b),  //right top front
		vec3(r, g, b),  //left top front
		vec3(r, g, b),  //left bottom front
		//top face cyan?
		vec3(r, g, b),  //left top back
		vec3(r, g, b),  //left top front
		vec3(r, g, b),  //right top front
		vec3(r, g, b),  //right top back
		//bottom face purple?
		vec3(r, g, b),  //left bottom back
		vec3(r, g, b),  //left bottom front
		vec3(r, g, b),  //right bottom front
		vec3(r, g, b)  //right bottom back
	};
	for (int i=0; i<colorCount; ++i)
		colorData[i] = tempColorData[i];

	vec4 tempNormalData[] = 
	{//left face
		vec4(-1.0f, 0.0f, 0.0f, 0.0f), //left bottom back
		vec4(-1.0f, 0.0f, 0.0f, 0.0f),	 //left bottom front
		vec4(-1.0f, 0.0f, 0.0f, 0.0f),   //left top front
		vec4(-1.0f, 0.0f, 0.0f, 0.0f),  //left top back
		//right face
		vec4(1.0f, 0.0f, 0.0f, 0.0f),  //right bottom back
		vec4(1.0f, 0.0f, 0.0f, 0.0f),   //right top back
		vec4(1.0f, 0.0f, 0.0f, 0.0f),    //right top front
		vec4(1.0f, 0.0f, 0.0f, 0.0f),   //right bottom front
		//front face
		vec4(0.0f, 0.0f, 1.0f, 0.0f),  //left top back
		vec4(0.0f, 0.0f, 1.0f, 0.0f),   //right top back
		vec4(0.0f, 0.0f, 1.0f, 0.0f),  //right bottom back
		vec4(0.0f, 0.0f, 1.0f, 0.0f), //left bottom back
		//back face
		vec4(0.0f, 0.0f, -1.0f, 0.0f),   //right top front
		vec4(0.0f, 0.0f, -1.0f, 0.0f),  //left top front
		vec4(0.0f, 0.0f, -1.0f, 0.0f), //left bottom front
		vec4(0.0f, 0.0f, -1.0f, 0.0f),  //right bottom front
		//top face
		vec4(0.0f, 1.0f, 0.0f, 0.0f), //left top back
		vec4(0.0f, 1.0f, 0.0f, 0.0f),  //left top front
		vec4(0.0f, 1.0f, 0.0f, 0.0f),   //right top front
		vec4(0.0f, 1.0f, 0.0f, 0.0f),  //right top back
		//bottom face
		vec4(0.0f, -1.0f, 0.0f, 0.0f), //left bottom back
		vec4(0.0f, -1.0f, 0.0f, 0.0f),  //left bottom front
		vec4(0.0f, -1.0f, 0.0f, 0.0f),   //right bottom front
		vec4(0.0f, -1.0f, 0.0f, 0.0f)  //right bottom back
	};

	glBindBuffer(GL_ARRAY_BUFFER, nbo);
	glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(vec4), tempNormalData, GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(vNormal);
	glVertexAttribPointer(vNormal, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeOfBuffer("vertex"), tempPoints, GL_STATIC_DRAW);

	glEnableVertexAttribArray(vLocation);
	glVertexAttribPointer(vLocation, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glBindBuffer(GL_ARRAY_BUFFER, cbo);
	glBufferData(GL_ARRAY_BUFFER, sizeOfBuffer("color"), tempColorData, GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(vColor);
	glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
}



size_t Cube::sizeOfBuffer(string buffer)
{
	if (buffer == "vertex")
		return vertexCount * sizeof(vec4);
	else if (buffer == "color")
		return colorCount * sizeof(vec3);
	return 0;
}


void Cube::draw(mat4 trans)
{
	glBindBuffer(GL_ARRAY_BUFFER, cbo);
	glBufferData(GL_ARRAY_BUFFER, sizeOfBuffer("color"), colorData, GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(vColor);
	glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &trans[0][0]);
	//glDrawArrays(GL_QUADS, 0, vertexCount);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}