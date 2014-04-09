#pragma once
#include <QSlider>

class RotateSlider : public QSlider
{
	Q_OBJECT
public:
	RotateSlider(QWidget*);
	~RotateSlider(void);


private:

	float value;

};
