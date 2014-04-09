#include "opengldemo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	OpenGLDemo w;
	w.show();
	return a.exec();
}
