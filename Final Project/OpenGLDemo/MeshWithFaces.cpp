//Author(s):Andrew Claudy
//COMP 361
//Due May 5th, 2014
//Desc: 

#include "MeshWithFaces.h"
#include <exception>
using std::exception;

MeshWithFaces::MeshWithFaces(void)
{
}


MeshWithFaces::~MeshWithFaces(void)
{
}


void MeshWithFaces::subdivideCatmullClark()
{
	deque<Face*> newCollection; //Deck some faces, like a boss.
	for(int i = 0; i < static_cast<int>(facesCollection.size()); i++) //For each face in facesCollection
	{
		vector<Face*> tempFour; //Scoped INSIDE the for loop because it should not hold a history.
		//int e, f, g, h;
		//h = 1+(g = 1+( f = 1+(e = i * 4))); //Init variables, like a boss.
		tempFour = facesCollection.at(i)->splitIntoFourFaces();
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
	facesCollection = newCollection; // Probably very expensive deep copy.
}