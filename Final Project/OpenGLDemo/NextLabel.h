/*
Creator: Garrett Young
Purpose: QT label class to display the index value of the select geometry
*/

#pragma once

#include <QLabel>

class NextLabel : public QLabel {
	Q_OBJECT
public:
	NextLabel(QWidget*);
	~NextLabel(void);
};

