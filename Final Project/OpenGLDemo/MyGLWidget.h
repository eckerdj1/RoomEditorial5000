#pragma once
#define GLEW_STATIC
#pragma comment(lib, "glew32s.lib")

#include "glew.h"
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include <QGLWidget>
#include "RotateDial.h"
#include <stdlib.h>
#include "Cube.h"
#include "Floor.h"
#include "Chair.h"
#include "Table.h"
#include "Box.h"
#include "SceneGraph.h"


#define BUFFER_OFFSET(bytes) ((GLvoid*) (bytes))

class MyGLWidget : public QGLWidget
{
	Q_OBJECT
public:
	MyGLWidget(QWidget*);
	~MyGLWidget(void);

	void initializeGL(void);
	void paintGL(void);
	void resizeGL(int, int);
	void setUniformMatrixAndDraw(mat4 matrix);
	void rotateX(mat4& m, float deg);
	void rotateY(mat4& m, float deg);
	void rotateZ(mat4& m, float deg);
	void translateToFloorPos(mat4& m, int x, int z, Floor& f);
	void scale(mat4& m, vec3 s);
	void makeWorld(mat4& m, vec3 scaleBy, float rotate, int x, int z, Floor& f);
	void readScene(string filename);


	//helper function to read shader source and put it in a char array
	//thanks to Swiftless.com
	char* textFileRead(const char*);

public slots:
	void rotateCameraY(int);
	void rotateCameraX(int);
	void rotateCameraLeft(void);
	void rotateCameraRight(void);
	void zoomCamera(int);
	void lightX(int);
	void lightY(int);
	void lightZ(int);
	void loadNewScene(string fileName);

	void nextGeo();
	void prevGeo();

	void moveXPos();
	void moveXNeg();
	void moveYPos();
	void moveYNeg();
	void moveZPos();
	void moveZNeg();

	void scaleXUp();
	void scaleXDown();
	void scaleYUp();
	void scaleYDown();
	void scaleZUp();
	void scaleZDown();

	void rotateLeft();
	void rotateRight();

signals:
	void sendInt(int);

private:
	unsigned int vertexShader;
	unsigned int fragmentShader;
	unsigned int shaderProgram;

	unsigned int vbo;
	unsigned int vLocation;
	unsigned int vColor;
	unsigned int vNormal;

	unsigned int u_projLocation;
	unsigned int u_modelMatrix;
	unsigned int u_lightPos;
	unsigned int u_cameraPos;

	SceneGraph* sg;
	Cube blueCube, redCube, greenCube, orangeCube, purpleCube, whiteCube;
	Floor* floor;
	Table* table;
	Chair* chair;
	Box* box;

	mat4 cameraTrans;
	vec3 cameraPos;
	vec3 cameraUp;
	vec3 cameraRef;
	float camRotY;
	float camRotX;
	float camZoom;

	vec3 lightPos;
	mat4 lightMatrix;

	int next;

};