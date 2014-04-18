//Andrew Claudy
//I numbered the face's halfedges HE0, HE1, HE2, HE3

#include "Face.h"

#include "PlanarityTester.h"
#include "ConvexityTester.h"

#include <vector>
using std::vector;

Face::Face(void)
{
	HE0 = nullptr;
}

Face::Face(const Vertex& one_, 
		   const Vertex& two_, 
		   const Vertex& three_, 
		   const Vertex& four_)
{
	//I numbered the face's halfedges HE0, HE1, HE2, HE3
	vector<vec4> positions = vector<vec4>();
	positions.push_back(one_.position);
	positions.push_back(two_.position);
	positions.push_back(three_.position);
	positions.push_back(four_.position);

	if( !checkPlanarity(positions) )
	{
		throw new NotPlanarException;
	}
	if( !isConvexPolygon(positions) )
	{
		throw new NotConvexException;
	}
	
	//Set up the half edges, but don't assign vertices yet.
	HE0 = new HalfEdge(); //HE0
	HE0->ownerFace = this;
	HE0->id = idCounter++;

	HE0->nextEdge = new HalfEdge();
	HalfEdge* HE1 = HE0->nextEdge;
	HE1->id = idCounter++;
	HE1->ownerFace = this;
	
	HE0->nextEdge->nextEdge = new HalfEdge();
	HalfEdge* HE2 = HE0->nextEdge->nextEdge; //Just identifier name alias
	HE2->id = idCounter++;
	HE2->symetric = HE0; //Set symmetry pointers
	HE0->symetric = HE2; //Set symmetry pointers
	HE2->ownerFace = this;

	HE0->nextEdge->nextEdge->nextEdge = new HalfEdge();
	HalfEdge* HE3 = HE0->nextEdge->nextEdge->nextEdge;
	HE3->id = idCounter++;
	HE3->symetric = HE1; //Set symmetry pointers
	HE1->symetric = HE3; //Set symmetry pointers
	HE3->ownerFace = this;
	
	//Don't forget that the 3rd HE needs a proper circular assignment
	HE3->nextEdge = HE0; //HE3->nextEdge = HE0

	//Now assign the vertices.
	//Uses copy constructor of Vertex...creates new Vertex objects.
	HE0->vertex = new Vertex(one_);
	HE0->nextEdge->vertex = new Vertex(two_);
	HE0->nextEdge->nextEdge->vertex = new Vertex(three_);
	HE0->nextEdge->nextEdge->nextEdge->vertex = new Vertex(four_);

	//Calculate the normal
	vec4 calculatedNormal = calculateFaceNormal();

	//Store the normal in each vertex
	HE0->vertex->normal = calculatedNormal;
	HE1->vertex->normal = calculatedNormal;
	HE2->vertex->normal = calculatedNormal;
	HE3->vertex->normal = calculatedNormal;
}


Face::~Face(void)
{
	//DE stands for DELETING EDGE
	HalfEdge *DE1 = nullptr, *DE2 = nullptr, *DE3 = nullptr;
	if(HE0 != nullptr) //Prevent crashes from dereferencing null pointers.
		DE1= HE0->nextEdge;

	if(DE1 != nullptr)
	{
		DE2 = DE1->nextEdge;
		delete DE1;
	}

	if(DE2 != nullptr)
	{
		DE3 = DE2->nextEdge;
		delete DE2;
	}

	if(DE3 != nullptr)
		delete DE3;

	//Lastly,
	if(HE0 != nullptr)
		delete HE0;
}


void Face::useHalfEdges()
{
	//DO something.
	HE0->vertex;
	HalfEdge* h = HE0->nextEdge;
	//DO something.
	h = h->nextEdge; //aka halfedge->symetric, aka HE2
	//DO something.
	h = h->nextEdge; //aka HE3
	//Do something
	//Done going through the quad face.

	/////
	//Alternative
	/*
	HE0->vertex;
	HE0->nextEdge->vertex;
	HE0->nextEdge->nextEdge->vertex; //aka half-edge->symmetric
	HE0->nextEdge->nextEdge->nextEdge->vertex;
	*/
}

vec4 Face::calculateFaceNormal() const
{
	if(HE0 == nullptr)
		throw new NotInitializedException;
	//Assumes that half edge positions are is w=1
	//BA and BC need to be w=0 because they are vectors
	vec3 BA = vec3( //A-B
		HE0->vertex->position.x - HE0->nextEdge->vertex->position.x,
		HE0->vertex->position.y - HE0->nextEdge->vertex->position.y,
		HE0->vertex->position.z - HE0->nextEdge->vertex->position.z);

	vec3 BC = vec3( //C-B
		(HE0->nextEdge->nextEdge->vertex->position) -
		(HE0->nextEdge->vertex->position));
	vec3 crossProduct = glm::cross(BA, BC);
	crossProduct = glm::normalize(crossProduct);
	return vec4(crossProduct, 0.f); //make normal have w=0;
}

vec4 Face::calculateFaceCenterAveragePoint() const
{
	if(HE0 == nullptr)
		throw new NotInitializedException;

	HalfEdge *HE1 = HE0->nextEdge;
	HalfEdge *HE2 = HE1->nextEdge;
	HalfEdge *HE3 = HE2->nextEdge;

	float xSum = HE0->vertex->position.x + HE1->vertex->position.x + HE2->vertex->position.x + HE3->vertex->position.x;
	float ySum = HE0->vertex->position.y + HE1->vertex->position.y + HE2->vertex->position.y + HE3->vertex->position.y;
	float zSum = HE0->vertex->position.z + HE1->vertex->position.z + HE2->vertex->position.z + HE3->vertex->position.z;

	float xAvg = xSum / 4.0f;
	float yAvg = ySum / 4.0f;
	float zAvg = zSum / 4.0f;

	return vec4(xAvg, yAvg, zAvg, 1.0f); //w=1 because it's a point in 3D space.
}