//Andrew Claudy
//COMP 361
//Due May 5th, 2014
//Desc: 

#include "Vertex.h"
#include "HalfEdge.h"

Vertex::Vertex(void)
{
	index = 0;
	isBuffered = false;
	myHalfEdge = 0;
}

Vertex::Vertex(const Vertex& copy) //Copy CTOR
{
	this->id		= copy.id; //need to copy the id//DO NOT COPY copy.id, preserve id's uniqueness.
	this->position	= copy.position;
	this->color		= copy.color;
	this->normal	= copy.normal;
	this->myHalfEdge = 0;
	this->isBuffered = copy.isBuffered;
	this->index = copy.index;
}

Vertex& Vertex::operator=(const Vertex& rhs) //danger: untested
{
	if(this == &rhs) //e.g., rhs = rhs;
        return *this; 
	//implied else
	return *(new Vertex(rhs.position, rhs.color, rhs.normal));
}

Vertex::Vertex(vec4 position_, vec3 color_, vec4 normal_)
{
	id			= ID::getUniqueID();
	position	= position_;
	color		= color_;
	normal		= normal_;
	isBuffered	= false;
	myHalfEdge	= 0;
}

Vertex::Vertex(vec4 position_, vec3 color_) //Normal removed in this CTOR
{
	id			= ID::getUniqueID();
	position	= position_;
	color		= color_;
	normal		= vec4(0); //To be overwritten over anyways.
	isBuffered	= false;
	myHalfEdge	= 0;
}

Vertex::Vertex(vec3 position_, vec3 color_, vec4 normal_)
{
	id			= ID::getUniqueID();
	position	= vec4(position_, 1); //Convert vec3 into vec4 point
	color		= color_;
	normal		= normal_;
	isBuffered	= false;
	myHalfEdge	= 0;
}

Vertex::Vertex(vec3 position_, vec3 color_) //Normal removed in this CTOR
{
	id			= ID::getUniqueID();
	position	= vec4(position_, 1); //Convert vec3 into vec4 point
	color		= color_;
	normal		= vec4(0); //To be overwritten over anyways.
	isBuffered	= false;
	myHalfEdge	= 0;
}

Vertex::~Vertex(void)
{
}

//A global function, not a member of Vertex.
const vec4 calculateMidpoint(const vec4& ptA, const vec4& ptB)
{
	return vec4((ptA.x + ptB.x) / 2.0f,
				(ptA.y + ptB.y) / 2.0f,
				(ptA.z + ptB.z) / 2.0f,
				1.0f);
}

const vec4 Vertex::calculateMidpoint(const vec4& withThisLocation) const
{
	return ::calculateMidpoint(this->position, withThisLocation);
}

const vec4 Vertex::calculateMidpoint(const Vertex& withThisLocation) const
{
	return ::calculateMidpoint(this->position, withThisLocation.position);
}

void Vertex::calculateNormal()
{
	vector<vec4> norms;
	vec4 avgNorm = vec4(0);
	HalfEdge* current = myHalfEdge;

	do
	{
		norms.push_back(current->ownerFace->normal);
		current = current->nextEdge->symetric;
	}while (current != myHalfEdge);

	for (int i=0; i<norms.size(); ++i)
	{
		avgNorm += norms[i];
	}

	avgNorm /= norms.size();

	normal = avgNorm;
}
