#ifndef OPENGLDEMO_H
#define OPENGLDEMO_H

#include <QtWidgets/QMainWindow>
#include "ui_opengldemo.h"

class OpenGLDemo : public QMainWindow
{
	Q_OBJECT

public:
	OpenGLDemo(QWidget *parent = 0);
	~OpenGLDemo();

private:
	Ui::OpenGLDemoClass ui;
};

#endif // OPENGLDEMO_H
