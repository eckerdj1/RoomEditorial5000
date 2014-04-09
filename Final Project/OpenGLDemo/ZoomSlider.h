#pragma once
#include <QSlider>

class ZoomSlider : public QSlider
{
	Q_OBJECT
public:
	ZoomSlider(QWidget*);
	~ZoomSlider(void);


private:

	float value;

};
