//Author(s):Dan Ecker
//COMP 361
//Due May 5th, 2014
//Desc: Loads a config file upon the accept button click.

#pragma once

#include <QLineEdit>
#include <string>
using std::string;

class LoadTextBox : public QLineEdit
{
	Q_OBJECT
public:
	LoadTextBox(QWidget*);
	~LoadTextBox(void);
signals:
	void loadFile(string);
public slots:
	void accept();
};