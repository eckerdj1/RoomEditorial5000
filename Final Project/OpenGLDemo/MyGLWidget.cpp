#include "MyGLWidget.h"
#include "Face.h"

MyGLWidget::MyGLWidget(QWidget* parent) : QGLWidget(parent) {
	camZoom = 10.0f;
	camRotX = -45.0f;
	camRotY = 0.0f;
	lightPos = vec3(0.0f, 5.5f, 10.0f);
	Face f( Vertex(vec4(1, 1, -1, 1), vec3(.8f, .7f, .43f)),
		Vertex(vec4(2, 1, -1, 1), vec3(.8f, .7f, .43f)),
		Vertex(vec4(2, 2, -2, 1), vec3(.8f, .7f, .43f)),
		Vertex(vec4(1, 2, -2, 1), vec3(.8f, .7f, .43f))  );

}

MyGLWidget::~MyGLWidget() {

	glDetachShader(shaderProgram, vertexShader);
	glDetachShader(shaderProgram, fragmentShader);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	glDeleteBuffers(1, &vbo);
}

void MyGLWidget::initializeGL() {
	glewInit();
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0);

	glGenBuffers(1, &vbo);
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	shaderProgram = glCreateProgram();

	const char* vertexSource = textFileRead("phong.vert");
	const char* fragmentSource = textFileRead("phong.frag");
	glShaderSource(vertexShader, 1, &vertexSource, 0);
	glShaderSource(fragmentShader, 1, &fragmentSource, 0);
	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	vLocation = glGetAttribLocation(shaderProgram, "vs_position");
	vColor = glGetAttribLocation(shaderProgram, "vs_color");
	vNormal = glGetAttribLocation(shaderProgram, "vs_normal");

	u_projLocation = glGetUniformLocation(shaderProgram, "u_projMatrix");
	u_modelMatrix = glGetUniformLocation(shaderProgram, "u_modelMatrix");
	u_lightPos = glGetUniformLocation(shaderProgram, "u_lightPos");
	u_cameraPos = glGetUniformLocation(shaderProgram, "u_cameraPos");

	glUseProgram(shaderProgram);

	blueCube.initializeCubeCoords(shaderProgram, 0.0f, 0.0f, 1.0f);
	redCube.initializeCubeCoords(shaderProgram, 1.0f, 0.0f, 0.0f);
	greenCube.initializeCubeCoords(shaderProgram, 0.0f, 1.0f, 0.0f);
	orangeCube.initializeCubeCoords(shaderProgram, 1.0f, 0.45f, 0.0f);
	purpleCube.initializeCubeCoords(shaderProgram, 1.0f, 0.0f, 1.0f);
	whiteCube.initializeCubeCoords(shaderProgram, 1.0f, 1.0f, 1.0f);

	cameraTrans = mat4(1.0f);
	cameraPos = vec3(0.0f, 0.0f, 10.0f);
	cameraUp = vec3(0.0f, 1.0f, 0.0f);
	cameraRef = vec3(0.0f);

	readScene("testSceneHW1.txt");

	//In case children[0] is empty, selects next child no matter what
	//Otherwise if children[0] is empty, manipulations would cause program crash
	sg->incNext();
	//Update the QT label
	emit sendInt(sg->getNext());
}

void MyGLWidget::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	cameraTrans = mat4(1.0f);
	mat4 rotY = glm::rotate(mat4(1.0f), camRotY, vec3(0.0f, 1.0f, 0.0f));
	mat4 rotX = glm::rotate(mat4(1.0f), camRotX, vec3(1.0f, 0.0f, 0.0f));
	
	vec4 camPos(0, 0, camZoom, 1);
	vec4 camUp(0, 1, 0, 0);
	camUp = rotY * rotX * camUp;
	camPos = rotY * rotX * camPos;
	
	//Set the camera
	cameraTrans = glm::lookAt(vec3(camPos.x, camPos.y, camPos.z), vec3(0, 0, 0), vec3(camUp.x, camUp.y, camUp.z));

	//Create Camera Matrix for the shader
	glUniformMatrix4fv(u_cameraPos, 1, GL_FALSE, &cameraTrans[0][0]);

	//Lighting Calculations and Representation
	//lightMatrix = mat4(1.0f);
	mat4 lightTrans = glm::translate(mat4(1.0f), lightPos);
	mat4 lightScale = glm::scale(mat4(1.0f), vec3(0.5f, 0.5f, 0.5f));
	lightTrans = cameraTrans * lightTrans * lightScale;

	glUniformMatrix4fv(u_lightPos, 1, GL_FALSE, &lightTrans[0][0]);

	whiteCube.draw(lightTrans);

	//Traverse the scene graph
	sg->traverse(cameraTrans);

	//Indicator Representation
	mat4 indicatorTrans = glm::translate(mat4(1.0f), vec3(sg->getChildTransX(), sg->getChildTransY() + 3.0f, sg->getChildTransZ()));
	mat4 indicatorScale = glm::scale(mat4(1.0f), vec3(0.125f, 0.5f, 0.125f));
	indicatorTrans = cameraTrans * indicatorTrans * indicatorScale;
	purpleCube.draw(indicatorTrans);
	
	glFlush();
}

void MyGLWidget::setUniformMatrixAndDraw(mat4 matrix)
{
	//glUniformMatrix4fv(u_modelMatrix, 1, GL_FALSE, &matrix[0][0]);
	//glDrawArrays(GL_QUADS, 0, blueCube.vertexCount);
}

void MyGLWidget::resizeGL(int width, int height) {
	glViewport(0, 0, width, height);

	//Here's how to make matrices for transformations, check the documentation of GLM for rotation, scaling, and translation
	glm::mat4 projection = glm::perspective(90.0f, static_cast<float>(width) / static_cast<float>(height), 0.1f, 30.0f);
	//glm::mat4 camera = glm::lookAt(glm::vec3(0.0f, 0.0f, 10.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	//Can multiply matrices together, careful about ordering!
	//projection = projection;// * camera;
	
	//Do something similar for u_modelMatrix before rendering things
	glUniformMatrix4fv(u_projLocation, 1, GL_FALSE, &projection[0][0]);
}

//from swiftless.com
char* MyGLWidget::textFileRead(const char* fileName) {
    char* text;
    
    if (fileName != NULL) {
        FILE *file = fopen(fileName, "rt");
        
        if (file != NULL) {
            fseek(file, 0, SEEK_END);
            int count = ftell(file);
            rewind(file);
            
            if (count > 0) {
                text = (char*)malloc(sizeof(char) * (count + 1));
                count = fread(text, sizeof(char), count, file);
                text[count] = '\0';	//cap off the string with a terminal symbol, fixed by Cory
            }
            fclose(file);
        }
    }
    return text;
}

void MyGLWidget::rotateX(mat4& m, float deg)
{
	m = glm::rotate(m, deg, vec3(1.0f, 0.0f, 0.0f));
}

void MyGLWidget::rotateY(mat4& m, float deg)
{
	m = glm::rotate(m, deg, vec3(0.0f, 1.0f, 0.0f));
}

void MyGLWidget::rotateZ(mat4& m, float deg)
{
	m = glm::rotate(m, deg, vec3(0.0f, 0.0f, 1.0f));
}

void MyGLWidget::scale(mat4& m, vec3 scaleBy)
{
	m = glm::scale(m, scaleBy);
}

void MyGLWidget::translateToFloorPos(mat4& m, int x, int z, Floor& f)
{
	m = glm::translate(m, f.floorIndexToVec3(x, z));
}

void MyGLWidget::makeWorld(mat4& m, vec3 scaleBy, float rotate, int x, int z, Floor& f)
{
	m = mat4(1.0f);
	translateToFloorPos(m, x, z, f);
	rotateY(m, rotate);
	scale(m, scaleBy);
}

void MyGLWidget::readScene(string filename)
{
	ifstream fin;
	fin.open(filename);
	if (fin.fail())
	{
		exit(1);
	}
	int x, z, itemCount;
	fin >> x >> z >> itemCount;
	floor = new Floor(x, z);
	table = new Table();
	chair = new Chair();
	box = new Box();
	floor->setCube(&purpleCube);
	table->setCube(&orangeCube);
	chair->setCube(&blueCube);
	box->setCube(&redCube);
	sg = new SceneGraph(x, z);
	sg->setFloorSize(x, z);
	sg->linkGeometry(floor);
	
	for (int i=0; i<itemCount; ++i)
	{
		SceneGraph* s = new SceneGraph();
		string type;
		int xx, zz, theta;
		float sx, sy, sz;
		fin >> type >> xx >> zz >> theta >> sx >> sy >> sz;
		if (type == "table")
			s->linkGeometry(table);
		if (type == "chair")
			s->linkGeometry(chair);
		if (type == "box")
			s->linkGeometry(box);
		s->setFloorSize(x,z);
		s->setRotY(theta);
		s->setScaleX(sx);
		s->setScaleY(sy);
		s->setScaleZ(sz);
		
		sg->addChild(s, xx, zz);
	}

}

void MyGLWidget::rotateCameraY(int num)
{
	camRotY = (float)num;
	paintGL();
	update();
}

void MyGLWidget::rotateCameraX(int num)
{
	camRotX = (float)num;
	paintGL();
	update();
}
void MyGLWidget::lightX(int num)
{
	lightPos.x = num / 10.0f;
	paintGL();
	update();
}
void MyGLWidget::lightY(int num)
{
	lightPos.y = num / 10.0f;
	paintGL();
	update();
}
void MyGLWidget::lightZ(int num)
{
	lightPos.z = num / 10.0f;
	paintGL();
	update();
}

void MyGLWidget::rotateCameraLeft()
{
	camRotY -= 0.1f;
	paintGL();
}

void MyGLWidget::rotateCameraRight()
{
	camRotY += 0.1f;
	paintGL();
}

void MyGLWidget::zoomCamera(int num)
{
	float zoom = ((float)num) / 10.0f;
	camZoom = zoom;
	paintGL();
	update();
}

void MyGLWidget::loadNewScene(string fileName)
{
	readScene(fileName);
	paintGL();
	update();
}

//Selects next child and updates QT label
void MyGLWidget::nextGeo()
{
	sg->incNext();
	emit sendInt(sg->getNext());
	paintGL();
	update();
}

//Selects previous child and updates QT label
void MyGLWidget::prevGeo()
{
	sg->decNext();
	emit sendInt(sg->getNext());
	paintGL();
	update();
}

void MyGLWidget::moveXPos()
{
	sg->transXPos();
	paintGL();
	update();
}

void MyGLWidget::moveXNeg()
{
	sg->transXNeg();
	paintGL();
	update();
}

void MyGLWidget::moveYPos()
{
	sg->transYPos();
	paintGL();
	update();
}

void MyGLWidget::moveYNeg()
{
	sg->transYNeg();
	paintGL();
	update();
}

void MyGLWidget::moveZPos()
{
	sg->transZPos();
	paintGL();
	update();
}

void MyGLWidget::moveZNeg()
{
	sg->transZNeg();
	paintGL();
	update();
}

void MyGLWidget::scaleXUp()
{
	sg->scaleXPos();
	paintGL();
	update();
}

void MyGLWidget::scaleXDown()
{
	sg->scaleXNeg();
	paintGL();
	update();
}

void MyGLWidget::scaleYUp()
{
	sg->scaleYPos();
	paintGL();
	update();
}

void MyGLWidget::scaleYDown()
{
	sg->scaleYNeg();
	paintGL();
	update();
}

void MyGLWidget::scaleZUp()
{
	sg->scaleZPos();
	paintGL();
	update();
}

void MyGLWidget::scaleZDown()
{
	sg->scaleZNeg();
	paintGL();
	update();
}

void MyGLWidget::rotateLeft()
{
	sg->rotLeft();
	paintGL();
	update();
}

void MyGLWidget::rotateRight()
{
	sg->rotRight();
	paintGL();
	update();
}