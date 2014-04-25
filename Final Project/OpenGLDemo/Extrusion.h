#pragma once
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include "Vertex.h"
#include "HalfEdge.h"
#include "Face.h"
#include "MyStuff.h"
#include <deque>
using std::deque;
using std::vector;
using std::string;
using glm::vec3;
using glm::vec4;
using std::ifstream;





class Extrusion
{
public:
	Extrusion();
	~Extrusion();

	void readData(ifstream& fin);
	void makeMesh();

	deque<Vertex*> getVertices();
	deque<HalfEdge*> getHalfEdges();
	deque<Face*> getFaces();


	bool convex();

private:
	deque<Vertex*> vertices;
	deque<HalfEdge*> halfEdges;
	deque<Face*> faces;

	vector<vec4> basePoints;
	vector<vec4> extrudedPoints;

	float height;
	int numberOfPointsInBase;
	int count;

	Vertex* findMatchingVertex(vec4 v);

};