#include "Extrusion.h"

Extrusion::Extrusion()
{

};

Extrusion::~Extrusion()
{

}

void Extrusion::readData(ifstream& fin)
{
	//*******file format********************//
	// type									//
	// height (base 2 base)					//
	// number of points in base				//
	// X Z (one per line * number of points)//
	//______________________________________//


	fin >> height;
	fin >> numberOfPointsInBase;
	count = numberOfPointsInBase - 1;

	for (int i=0; i<numberOfPointsInBase; ++i)
	{
		float x, z;
		fin >> x >> z;
		vec4 p = vec4(x, 0.0f, z, 1.0f);
		vec4 p2 = vec4(x, height, z, 1.0f);
		basePoints.push_back(p);
		extrudedPoints.push_back(p2);
	}
}


void Extrusion::makeMesh()
{
	//loop through all points and create vertex deque
	vec3 color(0,0,1);
	for (int i=0; i<count; ++i)
	{
		vertices.push_back(new Vertex(basePoints[i], color));
	}
	for (int i=0; i<count; ++i)
	{
		vertices.push_back(new Vertex(extrudedPoints[i], color));
	}

	// loop through all base points and make side faces
	// and construct top and bottom faces along the way;
	Face* topFace = new Face();
	Face* bottomFace = new Face();
	Vertex* topV;
	Vertex* botV;
	Vertex* lastTopV;
	Vertex* lastBotV;
	for (int i=0; i<count; ++i)
	{
		int nextI = (i + 1) % count;
		int prevI = i - 1;
		// make vertices
		if (i == 0)
		{
			lastBotV = findMatchingVertex(basePoints[i]);
			lastTopV = findMatchingVertex(extrudedPoints[i]);
		}
		else
		{
			lastBotV = botV;
			lastTopV = topV;
		}
		botV = findMatchingVertex(basePoints[nextI]);
		topV = findMatchingVertex(extrudedPoints[nextI]);
		// make the new side face
		Face* newSideFace = new Face(
			lastBotV,
			botV,
			topV,
			lastTopV);

		// make the new halfEdge for the top face
		HalfEdge* topEdge = new HalfEdge();
		topEdge->id = ID::getUniqueID();
		topEdge->vertex = newSideFace->at(2)->vertex;
		topEdge->ownerFace = topFace;

		// make the new halfEdge for the bottom face
		HalfEdge* botEdge = new	HalfEdge();
		botEdge->id = ID::getUniqueID();
		botEdge->vertex = newSideFace->at(0)->vertex;
		botEdge->ownerFace = bottomFace;

		// set face's he pointers
		

		// set sym pointers for top and bottom faces
		newSideFace->setSymAt(1, botEdge);
		newSideFace->setSymAt(3, topEdge);
		
		// add the new edges to the top and bottom faces
		if (windingOrderIs(CCW, basePoints))
		{
			topFace->addNewEdgeCCW(topEdge);
			bottomFace->addNewEdgeCW(botEdge);
		}
		else
		{
			topFace->addNewEdgeCW(topEdge);
			bottomFace->addNewEdgeCCW(botEdge);
		}

		// set sym pointers on left of this face
		if (i > 0)
		{
			newSideFace->setSymAt(0, faces[prevI]->at(2));
		}

		// if this is the last face, then set the sym
		// pointers for the right side of this face to
		// the left of the original face
		if (i == count - 1)
		{
			newSideFace->setSymAt(2, faces[0]->at(0));
		}
		faces.push_back(newSideFace);
		for (int k=0; k<4; ++k)
		{
			halfEdges.push_back(newSideFace->at(k));
		}
	}
	// close off top and bottom faces
	topFace->finishFace();
	bottomFace->finishFace();

	// add them to the face deques
	faces.push_back(topFace);
	faces.push_back(bottomFace);
	
	// push their halfEdges onto the halfEdge deques
	HalfEdge* one = topFace->HE0;
	halfEdges.push_back(one);
	one = one->nextEdge;
	do 
	{
		halfEdges.push_back(one);
		one = one->nextEdge;
	}while(one != topFace->HE0);

	one = bottomFace->HE0;
	halfEdges.push_back(one);
	one = one->nextEdge;
	do 
	{
		halfEdges.push_back(one);
		one = one->nextEdge;
	}while(one != bottomFace->HE0);

	// makes sure all vertices have a halfEdge pointer
	for (int i=0; i<halfEdges.size(); ++i)
	{
		HalfEdge* ve = halfEdges[i]->vertex->myHalfEdge;
		if (ve == 0)
			halfEdges[i]->vertex->myHalfEdge = halfEdges[i];
	}
}


bool Extrusion::convex()
{
	vec4 thisPoint, nextPoint, prevPoint;
	vec4 nextEdge, prevEdge;
	int num = numberOfPointsInBase - 1;
	vec4 norm, prevNorm;
	norm = vec4(0);
	for (int i=0; i<num; ++i)
	{
		int prev = (i + num - 1) % num;
		int next = (i + 1) % num;
		thisPoint = basePoints[i];
		nextPoint = basePoints[next];
		prevPoint = basePoints[prev];

		nextEdge = nextPoint - thisPoint;
		prevEdge = prevPoint - thisPoint;

		prevNorm = norm;
		norm = glm::normalize(cross(nextEdge, prevEdge));
		if (i > 0)
		{
			if (norm != prevNorm)
				return false;
		}
	}
	return true;
}

deque<Vertex*> Extrusion::getVertices()
{
	return vertices;
}
deque<HalfEdge*> Extrusion::getHalfEdges()
{
	return halfEdges;
}
deque<Face*> Extrusion::getFaces()
{
	return faces;
}

//void Extrusion::triangulateBase(vector<vec4> base, bool bottom)
//{
//	vec4 firstPoint = base[0];
//
//	for (int i=1; i< base.size() - 2; ++i)
//	{
//		vec4 secondPoint = base[i];
//		vec4 thirdPoint = base[i+1];
//
//		triangle t = triangle(firstPoint, secondPoint, thirdPoint);
//		if (!bottom)
//			t.normal = -t.normal;
//		faces.push_back(t);
//	}
//}

Vertex* Extrusion::findMatchingVertex(vec4 v)
{
	for (int i=0; i<vertices.size(); ++i)
	{
		if (vertices[i]->position == v)
			return vertices[i];
	}
	return 0;
}