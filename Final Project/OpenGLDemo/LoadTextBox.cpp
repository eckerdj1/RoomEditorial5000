//Author(s): Dan Ecker
//COMP 361
//Due May 5th, 2014
//Desc: 
#include "LoadTextBox.h"

LoadTextBox::LoadTextBox(QWidget* parent) : QLineEdit(parent)
{

}

LoadTextBox::~LoadTextBox()
{

}


void LoadTextBox::accept()
{
	emit loadFile(text().toStdString());
}