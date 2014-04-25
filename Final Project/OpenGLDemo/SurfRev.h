#pragma once
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include "Extrusion.h"
using std::vector;
using std::string;
using glm::vec3;
using glm::vec4;
using glm::mat4;
using glm::rotate;
using std::ifstream;



class SurfaceRev
{
public:
	SurfaceRev();
	~SurfaceRev();

	void readData(ifstream& fin);
	void makeSlices();
	void triangulate();
	vector<triangle> getFaces();

	bool convex();

private:

	vector<vec4> polyLine;
	vector<vector<vec4>> slices;
	int sliceCount;
	int polyLinePointCount;

	vector<triangle> faces;
	float height;
	int numberOfPointsInBase;



};