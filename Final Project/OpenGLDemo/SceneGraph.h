#pragma once
#include "Geometry.h"
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include <QGLWidget>
#include <stdlib.h>
#include <string>
#include <vector>
#include "Floor.h"
#include "Chair.h"
#include "Table.h"
#include "Box.h"
#include <fstream>
using glm::vec4;
using glm::vec3;
using glm::mat4;
using std::string;
using std::vector;
using std::ifstream;



class SceneGraph
{
public:
	SceneGraph();
	SceneGraph(int w, int d);

	void setTransX(float x) {transX = x;}
	void setTransY(float y) {transY = y;}
	void setTransZ(float z) {transZ = z;}
	
	void setScaleX(float x) {scaleX = x;}
	void setScaleY(float y) {scaleY = y;}
	void setScaleZ(float z) {scaleZ = z;}
	
	void setRotY(float theta) {rotY = theta;}
	void setFloorSize(int x, int z);

	void incNext();

	void setChildCount(int c);
	void addChild(SceneGraph* sg, int x, int z);
	void addChild(SceneGraph* sg);
	void linkGeometry(Geometry* geom);

	void traverse(mat4 m);

	
private:
	SceneGraph** children;
	float height;
	int width, depth;
	Geometry* model;
	int floorX, floorZ;

	float transX, transY, transZ;
	float scaleX, scaleY, scaleZ;
	float rotY;

	int next;

	//tNode* root;
	//int rootChildCount;
	
	//Chair* chair;
	//Table* table;
	//Box* box;
	//tNode* current;
	//int cIndex;
	//int** gCount;
};
