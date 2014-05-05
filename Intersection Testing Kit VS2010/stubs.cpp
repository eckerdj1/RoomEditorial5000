#include "stubs.h"
#include <limits>
using std::numeric_limits;

#include "glm/gtc/matrix_transform.hpp"
using namespace glm;

double getAreaOfTriangle(const vec3& moe, const vec3& larry, const vec3& curly)
{
	//Implements Heron's Formula
	return 1;
}

double Test_RaySphereIntersect(const vec3& P0, const vec3& V0, const mat4& T) {
	//vec4 (P0, 1)    vec4 ( V0, 0)    transformation matrix of the sphere
	// See the documentation of this function in stubs.h.
	
	/*mat4 inversedWorldMatrix = glm::inverse(T); // Inverts the transformation-into-world matrix
	mat4 CStarMatrix = T;
	CStarMatrix[1][3] = 0;
	CStarMatrix[2][3] = 0;
	CStarMatrix[2][3] = 0;
	mat4 CStarMatrixInverse = glm::inverse(CStarMatrix);

	vec3 sphereCenter = vec3(0, 0, 0); //in model space
	float sphereRadius = 1;

	vec4 transformedP0IntoLocalSpace = vec4(P0, 1) * inversedWorldMatrix;
	vec4 transformedV0IntoLocalSpace = vec4(V0-P0, 0) * CStarMatrixInverse; //Direction = P - E
	//Do not renormalize here.
	*/

	//ray line points = E + t V
	//sphere is (sphere points - sphereCenter)^2 = radius^2
	//Want to find if rayline points == sphere points 
	// (E+tV - sphereCenter)^2 = r^2
	//assuming sphere is centered at 0 means (E+tV)^2 = r^2
	//E^2 + 2(t*V*E) + (tV)^2 - r^2 = 0
	//rearranged: (tV)^2 +2t(VE) + E^2 - r^2 =0
	//quadradic formula to solve for t
	//t = -(2VE) +- sqrt( (2VE)^2 - 4(V^2)(E^2-r^2) ) / 2*(V^4)
	//where 2*(V^4) != 0 so check before dividing.


	vec4 sphereCenterPosition = vec4(T[3][0], T[3][1], T[3][2], 1.0f);
	float radius = 1; //Radius is always 1???
		//T[0][0];
	float a = pow(V0.x, 2) + pow(V0.y, 2) + pow(V0.z, 2);
	float b = 2 *(	V0.x*(P0.x-sphereCenterPosition.x) +
					V0.y*(P0.y-sphereCenterPosition.y) +
					V0.z*(P0.z-sphereCenterPosition.z) );
	float c =	pow(P0.x-sphereCenterPosition.x, 2) +
				pow(P0.y-sphereCenterPosition.y, 2) +
				pow(P0.z-sphereCenterPosition.z, 2) -
				pow(radius, 2);
	float discriminant = pow(b, 2) - 4 * a * c;
	if(discriminant > 0)
	{
		//solutions, there are 2;

	}
	else if (discriminant == 0)
	{
		//solutions, there is 1;
	}
	else //discriminant < 0
	{
		//solutions, there are none.
		return -1;
	}

	if(0 == 2*a) return -1; //Prevent divide by zero runtime errors.
	//tP is positive version, tN is negative version
	float tP = (-b + sqrt(discriminant)) / (2*a); 
	float tN = (-b - sqrt(discriminant)) / (2*a);

	if(tP > 0 && tP < tN) 
		return tP;
	if(tN > 0 && tN < tP)
		return tN;

	return -1;
}

double Test_RayPolyIntersect(const vec3& P0, const vec3& V0, const vec3& p1, const vec3& p2, const vec3& p3, const mat4& T) {
	// See the documentation of this function in stubs.h.
	//MAKE IT LOCAL SPACE
	mat4 localMatrix = glm::inverse(T);
	vec4 rayStartLocal = localMatrix * vec4(P0, 1.f); //w=1 it is a point
	mat4 cStar = T;
	cStar[3][0] = 0;
	cStar[3][1] = 0;
	cStar[3][2] = 0;
	mat4 cStarInverse = glm::inverse(cStar);
	vec4 rayDirectionLocal = cStarInverse * vec4(V0, 0.f); //w=0 it is a vector

	//Assuming planarity here.
	vec3 normal = normalize(cross((p2- p1),(p3-p1)));
	/*{
		//Turned it into a vec4 normal
		vec4 norm = vec4(normal, 0.0f);
		norm = norm * localMatrix;
		normal = vec3(norm.x, norm.y, norm.z); //put it back into normal
	}*/

	float denominator = dot(normal, vec3(rayDirectionLocal));
	if(denominator == 0) return -1; //Prevents divide by zero.
	float t = dot(normal, (p1-vec3(rayStartLocal))/denominator);

	if(t < 0)
		return -1;

	vec3 p = vec3(rayStartLocal) + t*vec3(rayDirectionLocal);

	double a1, a2, a3;

	a1 = sarrus(p1.y,p1.z,1,p2.y,p2.z,1,p3.y,p3.z,1);
	a2 = sarrus(p1.z,p1.x,1,p2.z,p2.x,1,p3.z,p3.x,1);
	a3 = sarrus(p1.x,p1.y,1,p2.x,p2.y,1,p3.x,p3.y,1);
	double s = (.5f*sqrt(pow(a1,2) + pow(a2,2) + pow(a3,2)));

	double b1, b2, b3;

	b1 = sarrus(p.y,p.z,1,p2.y,p2.z,1,p3.y,p3.z,1);
	b2 = sarrus(p.z,p.x,1,p2.z,p2.x,1,p3.z,p3.x,1);
	b3 = sarrus(p.x,p.y,1,p2.x,p2.y,1,p3.x,p3.y,1);
	double s1 = (.5f*sqrt((pow(b1,2) + pow(b2,2) + pow(b3,2))))/s;

	double c1, c2, c3;

	c1 = sarrus(p.y,p.z,1,p3.y,p3.z,1,p1.y,p1.z,1);
	c2 = sarrus(p.z,p.x,1,p3.z,p3.x,1,p1.z,p1.x,1);
	c3 = sarrus(p.x,p.y,1,p3.x,p3.y,1,p1.x,p1.y,1);
	double s2 = (.5f*sqrt((pow(c1,2) + pow(c2,2) + pow(c3,2))))/s;

	double d1, d2, d3;

	d1 = sarrus(p.y,p.z,1,p1.y,p1.z,1,p2.y,p2.z,1);
	d2 = sarrus(p.z,p.x,1,p1.z,p1.x,1,p2.z,p2.x,1);
	d3 = sarrus(p.x,p.y,1,p1.x,p1.y,1,p2.x,p2.y,1);
	double s3 = (.5f*sqrt((pow(d1,2) + pow(d2,2) + pow(d3,2))))/s;

	if(s1 + s2 + s3 == 1)
		return t;

	return -1;
}

double sarrus(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33)
{
	return (a11*a22*a33)+(a12*a23*a31)+(a13*a21*a32)-(a31*a22*a13)-(a32*a23*a11)-(a33*a21*a12);
}

//Returns the distance from P0 to the intersection.
double Test_RayCubeIntersect(const vec3& P0, const vec3& V0, const mat4& T) {
	//Cube is -.5 to .5 in local space therefore the slabs are ...?
	vec3 boxMinExtent(-0.5, -0.5, -0.5);
	vec3 boxMaxExtent( 0.5,  0.5,  0.5);

	//make a scaling matrix
	mat4 scalingMatrix = mat4(1);
	double xScale = T[0][0]; //Should NOT == 0 or bad things occur
	double yScale = T[1][1]; //Should NOT == 0 or bad things occur
	double zScale = T[2][2]; //Should NOT == 0 or bad things occur
	if(xScale == yScale && yScale == zScale) //and by transitivity property x == z.
	{
		scalingMatrix = glm::scale(mat4(1), vec3(xScale, yScale, zScale));
		boxMaxExtent = vec3(scalingMatrix * vec4(boxMaxExtent, 1));
		boxMinExtent = vec3(scalingMatrix * vec4(boxMinExtent, 1));
	}

	//MAKE IT LOCAL SPACE FOR AXIS ALIGNMENT
	mat4 localMatrix = glm::inverse(T);
	vec4 rayStartLocal = scalingMatrix * localMatrix * vec4(P0, 1.f); //w=1
	vec4 rayDirection  = localMatrix * vec4(V0, 0.f); //w-0
	//boxMinExtent = vec3(localMatrix * vec4(boxMinExtent, 1.f)); //NO
	//boxMaxExtent = vec3(localMatrix * vec4(boxMaxExtent, 1.f)); //NO
	
	//Step zero: initialize the tnear and tfar to infinity (or neg inf)
	double tXnear = numeric_limits<double>::min();
	double tXfar  = numeric_limits<double>::max();
	double tYnear = numeric_limits<double>::min();
	double tYfar  = numeric_limits<double>::max();
	double tZnear = numeric_limits<double>::min();
	double tZfar  = numeric_limits<double>::max();

	//Check for x y or z == 0 for capitalizing on the opportunity for 2D collision detection
	if((rayDirection.x == 0 &&
		rayDirection.y == 0 &&
		rayDirection.z == 0)
	   )//endcondition
	{
		//OH CRAP! DIVIDE BY ZERO. CAN'T DO IT.
		return -1;
	}

#pragma region Z-axis collision intersection point calculation
	if (rayDirection.x == 0 && rayDirection.y == 0)
	{
		bool withinXChannel = boxMaxExtent.x > rayStartLocal.x && boxMinExtent.x < rayStartLocal.x;
		bool withinYChannel = boxMaxExtent.y > rayStartLocal.y && boxMinExtent.y < rayStartLocal.y;

		if(withinXChannel && withinYChannel)
		{
			//True but not useful statements:
			//double intersectionX = rayStartLocal.x;
			//double intersectionY = rayStartLocal.y;
			tZnear = min(boxMinExtent.z-rayStartLocal.z, boxMaxExtent.z-rayStartLocal.z);
			tZfar  = max(boxMinExtent.z-rayStartLocal.z, boxMaxExtent.z-rayStartLocal.z);
			return min(abs(tZnear), abs(tZfar));
		}
		else 
			return -1;
	}
#pragma endregion
#pragma region Y-axis collision intersection point calculation
	if (rayDirection.x == 0 && rayDirection.z == 0)
	{
		bool withinXChannel = boxMaxExtent.x > rayStartLocal.x && boxMinExtent.x < rayStartLocal.x;
		bool withinZChannel = boxMaxExtent.z > rayStartLocal.z && boxMinExtent.z < rayStartLocal.z;

		if(withinXChannel && withinZChannel)
		{
			//True but not useful statements:
			//double intersectionX = rayStartLocal.x;
			//double intersectionZ = rayStartLocal.z;
			tYnear = min(boxMinExtent.y-rayStartLocal.y, boxMaxExtent.y-rayStartLocal.y);
			tYfar  = max(boxMinExtent.y-rayStartLocal.y, boxMaxExtent.y-rayStartLocal.y);
			return min(abs(tYnear), abs(tYfar));
		}
		else
			return -1;
	}
#pragma endregion
#pragma region X-axis only intersection point calculation
	if (rayDirection.y == 0 && rayDirection.z == 0)
	{
		bool withinYChannel = boxMaxExtent.y > rayStartLocal.y && boxMinExtent.y < rayStartLocal.y;
		bool withinZChannel = boxMaxExtent.z > rayStartLocal.z && boxMinExtent.z < rayStartLocal.z;

		if(withinYChannel && withinZChannel)
		{
			//True but not useful statements:
			//double intersectionX = rayStartLocal.x;
			//double intersectionZ = rayStartLocal.z;
			tXnear = min(boxMinExtent.x-rayStartLocal.x, boxMaxExtent.x-rayStartLocal.x);
			tXfar  = max(boxMinExtent.x-rayStartLocal.x, boxMaxExtent.x-rayStartLocal.x);
			return min(abs(tXnear), abs(tXfar));
		}
		else
			return -1;
	}
#pragma endregion


	double  t0x, t0y, t0z, 
			t1x, t1y, t1z;

	if(rayDirection.x == 0)
	{
		//rayStartLocal.x < near bound's .x 
		t0x = t1x = 0;		
		t0y = (boxMinExtent.y - rayStartLocal.y) / rayDirection.y;
		t0z = (boxMinExtent.z - rayStartLocal.z) / rayDirection.z;
		t1y = (boxMaxExtent.y - rayStartLocal.y) / rayDirection.y;
		t1z = (boxMaxExtent.z - rayStartLocal.z) / rayDirection.z;
	
		if(t0z > t0y) 
			tZnear = t0y;
		else
			tZnear = t0z;

		if(t1z < t1y)
			tYnear = t1z;
		else
			tYnear = t1y;

		return min(tYnear, tZnear);
	}
	else if(rayDirection.y == 0)
	{
		//rayStartLocal.y < near bound's .y
		t0y = t1y = 0;
		t0x = (boxMinExtent.x - rayStartLocal.x) / rayDirection.x;
		t0z = (boxMinExtent.z - rayStartLocal.z) / rayDirection.z;
		t1x = (boxMaxExtent.x - rayStartLocal.x) / rayDirection.x;
		t1z = (boxMaxExtent.z - rayStartLocal.z) / rayDirection.z;
		tZnear = t0z < t0x ? t0z : t0x;
		tXnear = t1z < t1x ? t1z : t1x;
		return min(tXnear, tZnear);
	}
	else if(rayDirection.z == 0)
	{
		//rayStartLocal.z < near bound's .z
		t0z = t1z = 0;
		t0x = (boxMinExtent.x - rayStartLocal.x) / rayDirection.x;
		t0y = (boxMinExtent.y - rayStartLocal.y) / rayDirection.y;
		t1x = (boxMaxExtent.x - rayStartLocal.x) / rayDirection.x;
		t1y = (boxMaxExtent.y - rayStartLocal.y) / rayDirection.y;
		tXnear = t0x < t0y ? t0x : t0y;
		tYnear = t1x < t1y ? t1x : t1y;
		return min(tXnear, tXnear);
	}

	//END OF WEIRD SITUATIONS where the direction has a zero component.
	//Step one: foreach(PlanePair pear in PairsOfPlains)
	//Step two:   call that polyDetection function...lol. jk.

	//The ray direction has no component == to zero so it is safe to divide.
	t0x = (boxMinExtent.x - rayStartLocal.x) / rayDirection.x;
	t0y = (boxMinExtent.y - rayStartLocal.y) / rayDirection.y;
	t0z = (boxMinExtent.z - rayStartLocal.z) / rayDirection.z;
	t1x = (boxMaxExtent.x - rayStartLocal.x) / rayDirection.x;
	t1y = (boxMaxExtent.y - rayStartLocal.y) / rayDirection.y;
	t1z = (boxMaxExtent.z - rayStartLocal.z) / rayDirection.z;

	if(t0x < t0y && t0x < t0z) 
		tXnear = t0x;
	else
	{
		if(t0y < t0z)
			tXnear = t0y;
		else
			tXnear = t0z;
	}

	if(t1x < t1y && t1x < t1z)
		tYnear = t1x;
	else
	{
		if(t1y < t1z)
			tYnear = t1y;
		else
			tYnear = t1z;
	}
	//not sure what to return in this situation.
	
	return -1;
}