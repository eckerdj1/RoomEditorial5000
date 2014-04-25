//Andrew Claudy

#pragma once
#include <glm/glm.hpp>
using glm::vec2;
using glm::vec3;
using glm::vec4;

#include "Face.h"
#include "HalfEdge.h"
#include "Vertex.h"
#include "Geometry.h"

#include <vector>
#include <deque>
#include <string>
using std::string;
using std::deque;
using std::vector;

class Mesh : public Geometry
{
public:
	Mesh(void);
	~Mesh(void);

	void init(unsigned int shaderProgram);

	void makeMeshFromFile(string fileName);
	
	void readDataFromFile(string fileName);
	void triangulateMesh();
	void attachEdgesToFace(HalfEdge* start, Face* face);

	void setSubdivisionCount(int s);

	void fillBuffers();
	void calculateNormals();

	void subdivideCatmullClark(); //Executes a Catmull-Clark subdivision
	void splitEdgeAtMidpoint(HalfEdge* edge);
	vector<Face*> splitIntoFourFaces(Face* face);
	vec4 calculateFaceCenterAveragePoint(Face* face) const;

	void draw(mat4 trans);
	float getHeight();

private:
	deque<Face*> faces;
	deque<Vertex*> vertices;
	deque<HalfEdge*> halfEdges;

	float height;

	int count;
	int subDivisionCount;

	unsigned int vbo;
	unsigned int ibo;
	unsigned int nbo;
	unsigned int cbo;

	unsigned int modelMatrix;
	unsigned int vLocation;
	unsigned int vColor;
	unsigned int vNormal;
};

