#include "HalfEdge.h"


HalfEdge::HalfEdge(void)
{
	id = -1;
	ownerFace	= nullptr;
	vertex		= nullptr;
	symetric	= nullptr;
	nextEdge	= nullptr;
}


HalfEdge::~HalfEdge(void)
{
	if(vertex != nullptr)
		delete vertex;
}
