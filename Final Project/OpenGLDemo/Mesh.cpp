#include "Mesh.h"
#include "SurfRev.h"
#include "Extrusion.h"


#include <fstream>
using std::ifstream;


Mesh::Mesh(void)
{
}


Mesh::~Mesh(void)
{
}

void Mesh::init(unsigned int shaderProgram)
{
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &nbo);
	glGenBuffers(1, &cbo);
	glGenBuffers(1, &ibo);

	modelMatrix = glGetUniformLocation(shaderProgram, "u_modelMatrix");
	vLocation = glGetAttribLocation(shaderProgram, "vs_position");
	vColor = glGetAttribLocation(shaderProgram, "vs_color");
	vNormal = glGetAttribLocation(shaderProgram, "vs_normal");
}

void Mesh::readDataFromFile(string fileName)
{
	ifstream fin;
	fin.open(fileName);
	if (fin.fail())
	{
		// Out put to some qt widget here
		return;
	}
	string type;
	fin >> type;
	if (type == "surfrev")
	{
		SurfaceRev s;
		s.readData(fin);
		s.makeSlices();
		s.triangulate();
		//faces = s.getFaces();
	}
	else if (type == "extrusion")
	{
		Extrusion e;
		e.readData(fin);
		e.makeMesh();
		faces = e.getFaces();
		vertices = e.getVertices();
		halfEdges = e.getHalfEdges();
		float highest = 0.0f;
		for (int i=0; i<vertices.size(); ++i)
		{
			if (vertices[i]->position.y > highest)
			{
				highest = vertices[i]->position.y;
			}
		}
		height = highest;
	}
	fin.close();
}

float Mesh::getHeight()
{
	return height;
}

void Mesh::draw(mat4 trans)
{
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glEnableVertexAttribArray(vLocation);
	glVertexAttribPointer(vLocation, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, nbo);
	glEnableVertexAttribArray(vNormal);
	glVertexAttribPointer(vNormal, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, cbo);
	glEnableVertexAttribArray(vColor);
	glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

	glUniformMatrix4fv(modelMatrix, 1, GL_FALSE, &trans[0][0]);
	glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0);
}

void Mesh::triangulateMesh()
{
	deque<Face*> newFaces;
	deque<HalfEdge*> newHalfEdges;
	for (int i=0; i<faces.size(); ++i)
	{
		HalfEdge* edge = faces[i]->HE0;

		// this edge will point to the vertex we want
		// to split with
		HalfEdge* nextEdge = edge->nextEdge->nextEdge;
		
		// these will be used to keep track of edges made 
		// in the previous iteration
		HalfEdge *last1, *last2;
		Face* lastFace;

		last1 = new HalfEdge();
		last2 = new HalfEdge();
		lastFace = new Face();

		//give new id's and copy pointers over
		//set sym pointers, as well
		last1->id = ID::getUniqueID();
		last2->id = ID::getUniqueID();
		last1->copyPointers(edge);
		last1->setSym(last2);
		last2->copyPointers(nextEdge);

		//add last1 as the nextEdge of the open edge
		nextEdge->nextEdge = last1;

		// add halfEdges to the new face;
		attachEdgesToFace(last1, lastFace);
		lastFace->HE0 = last1;

		nextEdge = last2->nextEdge;
		
		//	Add new stuff to deques
		newFaces.push_back(lastFace);
		newHalfEdges.push_back(last1);
		newHalfEdges.push_back(last2);

		// after making the initial triangle, iterate through the
		// rest of the face
		while (nextEdge->nextEdge != edge)
		{
			//	This loop does everything above iteratively over
			//	the rest of the face
			HalfEdge* new1 = new HalfEdge();
			HalfEdge* new2 = new HalfEdge();
		
			Face* newFace = new Face();

			//	Set up new HalfEdges
			new1->id = ID::getUniqueID();
			new2->id = ID::getUniqueID();
			new1->setSym(new2);
			new1->copyPointers(edge);
			new1->nextEdge = last2;
			new2->copyPointers(nextEdge);
			nextEdge->nextEdge = new1;

			//	Set up the new Face
			attachEdgesToFace(new1, newFace);
			newFace->HE0 = new1;

			//	Jump to next edge in face
			nextEdge = new2->nextEdge;

			//	Keep track of what we just made
			last1 = new1;
			last2 = new2;
			lastFace = newFace;
			
			//	Push new stuff into containers
			newFaces.push_back(lastFace);
			newHalfEdges.push_back(last1);
			newHalfEdges.push_back(last2);
		}

		edge->nextEdge = last2;
		last2->ownerFace = faces[i];
	}	//	End of for loop over all faces

	//	Push all our new stuff into the Mesh's containers
	for (int i=0; i<newFaces.size(); ++i)
	{
		faces.push_back(newFaces[i]);
	}
	for (int i=0; i<newHalfEdges.size(); ++i)
	{
		halfEdges.push_back(newHalfEdges[i]);
	}
	
	//	Loop over all triangulated faces and calculate normals
	for (int i=0; i<faces.size(); ++i)
	{
		findFaceNormal(faces[i]);
	}

}

void Mesh::attachEdgesToFace(HalfEdge* startEdge, Face* face)
{
	HalfEdge* currentEdge = startEdge;
	face->HE0 = currentEdge;
	do // attach HE's to new Face
	{
		currentEdge->ownerFace = face;
		currentEdge = currentEdge->nextEdge;
	}while (currentEdge != startEdge);
}

void Mesh::calculateNormals()
{
	count = vertices.size();
	for (int i=0; i<count; ++i)
	{
		vertices[i]->calculateNormal();
	}

}

void Mesh::fillBuffers()
{
	count = vertices.size();

	int counter = 0;
	int index = 0;

	vec4* points = new vec4[count];
	vec4* normals = new vec4[count];
	vec3* colors = new vec3[count];
	vector<unsigned int> indices;

	for (int i=0; i<faces.size(); ++i)
	{
		HalfEdge* current = faces[i]->HE0;
		do
		{
			if (current->vertex->isBuffered)
			{
				indices.push_back(current->vertex->index);
			}
			else
			{
				points[index] = current->vertex->position;
				normals[index] = current->vertex->normal;
				colors[index] = current->vertex->color;
				current->vertex->index = index;
				current->vertex->isBuffered = true;
				indices.push_back(index);
				index++;
			}
			current = current->nextEdge;
		}while (current != faces[i]->HE0);
	}
	counter = indices.size();
	unsigned int* indexBuffer = new unsigned int[counter];
	for (int i=0; i<counter; ++i)
	{
		indexBuffer[i] = indices[i];
	}


	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, count * sizeof(vec4), points, GL_STATIC_DRAW);

	glEnableVertexAttribArray(vLocation);
	glVertexAttribPointer(vLocation, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, nbo);
	glBufferData(GL_ARRAY_BUFFER, count * sizeof(vec4), normals, GL_STATIC_DRAW);

	glEnableVertexAttribArray(vNormal);
	glVertexAttribPointer(vNormal, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, cbo);
	glBufferData(GL_ARRAY_BUFFER, count * sizeof(vec3), colors, GL_STATIC_DRAW);

	glEnableVertexAttribArray(vColor);
	glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, counter * sizeof(unsigned int), indexBuffer, GL_STATIC_DRAW);


	delete [] points;
	delete [] normals;
	delete [] colors;
	delete [] indexBuffer;

	count = counter;

}

void Mesh::makeMeshFromFile(string fileName)
{
	readDataFromFile(fileName);
	triangulateMesh();
	calculateNormals();
	fillBuffers();
}

void Mesh::setSubdivisionCount(int s)
{
	subDivisionCount = s;
}

void Mesh::subdivideCatmullClark()
{
	deque<Face*> newCollection; //Deck some faces, like a boss.
	for(int i = 0; i < static_cast<int>(faces.size()); i++) //For each face in facesCollection
	{
		vector<Face*> tempFour; //Scoped INSIDE the for loop because it should not hold a history.
		//int e, f, g, h;
		//h = 1+(g = 1+( f = 1+(e = i * 4))); //Init variables, like a boss.
		tempFour = faces.at(i)->splitIntoFourFaces();
		if(tempFour.size() != 4)
			throw new exception("The face did not split into 4 faces correct"); //Throw exceptions, like a boss.

		//Begin self-assign ownerFace
		//tempFour.at(0).assignOwnerFace();
		//tempFour.at(1).assignOwnerFace();
		//tempFour.at(2).assignOwnerFace();
		//tempFour.at(3).assignOwnerFace();
		//End of symmetry setup

			//Also, should be starting at the lower left corner
			//D_______________________C
			//|			|			  |
			//|	at(h)	|	at(g)	  |
			//|<--------o-------------| <e.g. this point is BCHalfPt
			//|	at(e)	^	at(f)	  |
			//|			|			  |
			//V________>|_____________|
			//A			^ABHalfPt	  B
			//TODO: do some other face interaction

		// Dump the contents of the vector "tempFour", the 4 new faces, into the back of newCollection (order doesn't matter)
		while(!tempFour.empty())
		{
			newCollection.push_back(tempFour.front());
			tempFour.erase(tempFour.begin());
		}
	}//End of for loop (iterating through all the faces in the mesh).

	//At the very end overwrite the datastructure with the new collection of faces.
	faces = newCollection; // Probably very expensive deep copy.
}

void Mesh::splitEdgeAtMidpoint(HalfEdge* edge)
{
	HalfEdge* sym = edge->symetric;

	HalfEdge* newEdge = new HalfEdge();
	HalfEdge* otherNewEdge = new HalfEdge();

	newEdge->copyPointers(edge);
	otherNewEdge->copyPointers(sym);

	edge->setSym(otherNewEdge);
	newEdge->setSym(sym);

	edge->nextEdge = newEdge;
	sym->nextEdge = otherNewEdge;

	newEdge->ownerFace = edge->ownerFace;
	otherNewEdge->ownerFace = sym->ownerFace;

	vec4 newPos = calculateMidpoint(edge->vertex->position, edge->symetric->vertex->position);
	Vertex* newVertex = new Vertex(newPos, edge->vertex->color);
	
	sym->vertex = newVertex;
	edge->vertex = newVertex;

	newVertex->myHalfEdge = edge;

	vertices.push_back(newVertex);
	halfEdges.push_back(newEdge);
	halfEdges.push_back(otherNewEdge);


}

vector<Face*> Mesh::splitIntoFourFaces(Face* face)
{
	HalfEdge* HE0 = face->HE0;
	if(HE0 == nullptr)
		throw new NotInitializedException;

	HalfEdge *HE1 = HE0->nextEdge;
	HalfEdge *HE2 = HE1->nextEdge;
	HalfEdge *HE3 = HE2->nextEdge;
	vector<Face*> fourNewFaces;
	
	vec4 centroidAveragePointOfFace = calculateFaceCenterAveragePoint(face);
	vec4 ABHalfPt = calculateMidpoint(HE0->vertex->position, HE1->vertex->position);
	vec4 BCHalfPt = calculateMidpoint(HE1->vertex->position, HE2->vertex->position);
	vec4 CDHalfPt = calculateMidpoint(HE2->vertex->position, HE3->vertex->position);
	vec4 DAHalfPt = calculateMidpoint(HE3->vertex->position, HE0->vertex->position);

	//instantiate 4 new faces
	//ajc: Here is the naming convention (A = HE0, B = HE1, C = HE2, D = HE3)
	//D_______________________C
	//|			|			  |
	//|	Quad4	|	Quad3	  |
	//|---------|-------------| <e.g. this point is BCHalfPt
	//|	Quad1	|	Quad2	  |
	//|_________|_____________|
	//A			^ABHalfPt	  B
	//Place a breakpoint here and use Immediate Window to observe idCounter.
	fourNewFaces.push_back(
		new Face( HE0->vertex, //A
		new Vertex(ABHalfPt, HE0->vertex->color),
		new Vertex(centroidAveragePointOfFace, HE0->vertex->color),
		new Vertex(DAHalfPt, HE0->vertex->color) ) 
		);

	fourNewFaces.push_back( 
		new Face(new Vertex(ABHalfPt, HE1->vertex->color),
		HE1->vertex, //B
		new Vertex(BCHalfPt, HE1->vertex->color),
		new Vertex(centroidAveragePointOfFace, HE1->vertex->color) ) 
		);

	fourNewFaces.push_back(
		new Face(new Vertex(centroidAveragePointOfFace, HE2->vertex->color),
		new Vertex(BCHalfPt, HE2->vertex->color),
		HE2->vertex, //C
		new Vertex(CDHalfPt, HE2->vertex->color) )
		);

	fourNewFaces.push_back(
		new Face(new Vertex(DAHalfPt, HE3->vertex->color),
		new Vertex(centroidAveragePointOfFace, HE3->vertex->color),
		new Vertex(CDHalfPt, HE3->vertex->color),
		HE3->vertex) //D
		);

	//Begin 8 symmetry setup
	fourNewFaces.at(0)->HE0->nextEdge->nextEdge->symetric = fourNewFaces.at(1)->HE0;
	fourNewFaces.at(1)->HE0->symetric = fourNewFaces.at(0)->HE0->nextEdge->nextEdge;
					  
	fourNewFaces.at(1)->HE0->nextEdge->nextEdge->nextEdge->symetric = fourNewFaces.at(2)->HE0->nextEdge;
	fourNewFaces.at(2)->HE0->nextEdge->symetric = fourNewFaces.at(1)->HE0->nextEdge->nextEdge->nextEdge;
					  
	fourNewFaces.at(2)->HE0->symetric = fourNewFaces.at(3)->HE0->nextEdge->nextEdge;
	fourNewFaces.at(3)->HE0->nextEdge->nextEdge->symetric = fourNewFaces.at(2)->HE0;
					  
	fourNewFaces.at(3)->HE0->nextEdge->symetric = fourNewFaces.at(0)->HE0;
	fourNewFaces.at(0)->HE0->symetric = fourNewFaces.at(3)->HE0->nextEdge;
	//End of 8 symmetry setup

	//Place a breakpoint here and use Immediate Window to observe idCounter.
	return fourNewFaces; //Danger: ownerFace doesn't preserve here.
}

vec4 Mesh::calculateFaceCenterAveragePoint(Face* face) const
{
	HalfEdge* HE0 = face->HE0;
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