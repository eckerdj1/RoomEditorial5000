#include "MyStuff.h"
#include "Face.h"
#include <math.h>



vec4 cross(vec4 v1, vec4 v2)
{
	vec3 product = glm::cross(vec3(v1), vec3(v2));
	return vec4(product, 0.0f);
}

vec4 cross(vec3 v1, vec3 v2)
{
	vec3 product = glm::cross(v1, v2);
	return vec4(product, 0.0f);
}

vec4 findFaceNormal(Face* face)
{
	HalfEdge* edge = face->HE0;
	Vertex* anchor = edge->nextEdge->vertex;
	Vertex* left = edge->vertex;
	Vertex* right = edge->nextEdge->nextEdge->vertex;

	vec4 edgeCCW = right->position - anchor->position;
	vec4 edgeCW = left->position - anchor->position;

	face->normal = glm::normalize(cross(edgeCW, edgeCCW));
	return face->normal;
}

bool windingOrderIs(int clockDir, vector<vec4> points)
{
	vec4 cp;
	for (int i=0; i<points.size(); ++i)
	{
		int nextI = (i + 1) % points.size();
		int prevI = (i + points.size() - 1) % points.size();
		vec4 next = points[nextI] - points[i];
		vec4 prev = points[prevI] = points[i];
		cp = glm::normalize(cross(next, prev));

		if((cp.y < 0  && clockDir > 0) || (cp.y > 0 && clockDir < 0))
			return false;

	}
	return true;
}

ID::ID()
{
}

int ID::getUniqueID()
{
	static int counter = 0;
	static vector<int> usedIDs;
	for (int i=0; i<usedIDs.size(); ++i)
	{
		if (counter == usedIDs[i])
			counter++;
	}
	usedIDs.push_back(counter);
	return counter;
}
