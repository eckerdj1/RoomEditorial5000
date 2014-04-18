//Andrew Claudy

#include "PlanarityTester.h"
#include <vector>
using std::vector;

#include <glm/glm.hpp>
using glm::vec2;
using glm::vec3;
using glm::vec4;
using glm::cross;

bool checkPlanarity(const vector<vec4>& pts) //CLAUDY CODE begin!
{
	int size = (int)pts.size();
	if(size == 0 || size == 1 || size == 2) return false;
	if(size == 3) return true;

	//Using the enhanced version...where one normal is the 'chosen one' and
	//all other normals must equal it. (@ajc convexity compares sign only, planarity uses == value)
	//A normal must be calculated at each point.
	vec3 a = vec3(pts.at(0));
	vec3 b = vec3(pts.at(1));
	vec3 c = vec3(pts.at(2));
	vec3 goldenNormal = cross( a-b, c-b );
	vec3 ithNormal;
	for(int i = 1; i < size-2; ++i) //0th was already calculated, will == 0th normal tautologically.
	{
		a = vec3(pts.at(i));
		b = vec3(pts.at(i+1));
		c = vec3(pts.at(i+2));
		ithNormal = cross( a-b, c-b );
		if (goldenNormal != ithNormal) return false;
	}
	//Well, all the ithNormals == goldenNormal so the shape must be planar.
	return true;
}