#include "Face.h"


Face::Face(void)
{
}

Face::Face(const Vertex& one_, 
		   const Vertex& two_, 
		   const Vertex& three_, 
		   const Vertex& four_)
{
	//I numbered the face's halfedges HE0, HE1, HE2, HE3
	//TODO: Planarity Test
	//TODO: Convexity Test

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
	HE0->nextEdge->nextEdge->vertex; //aka half-edge->symetric
	HE0->nextEdge->nextEdge->nextEdge->vertex;
	*/
}

vec4 Face::calculateFaceNormal() const
{
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