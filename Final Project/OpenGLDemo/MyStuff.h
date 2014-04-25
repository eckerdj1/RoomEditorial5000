//Daniel Ecker
#pragma once
#include <glm\glm.hpp>
#include <vector>
using std::vector;
using glm::vec3;
using glm::vec4;

class Face;

const int CCW = 1;
const int CW = -1;


vec4 cross(vec4 v1, vec4 v2);
vec4 cross(vec3 v1, vec3 v2);

vec4 findFaceNormal(Face* face);

bool windingOrderIs(int clockDir, vector<vec4> points);

class ID
{
public:
	ID();
	static int getUniqueID();
};