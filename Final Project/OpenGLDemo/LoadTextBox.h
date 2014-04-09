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