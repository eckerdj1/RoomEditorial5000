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