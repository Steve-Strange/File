#pragma once

#include "Shape.h"

class Curve : public Shape {
public:
	Curve();
	~Curve();		   
	void set_end(QPoint e);					   
											   
	QVector<QPoint> point_list_;
											   
	void Draw(QPainter& painter);			   
};											   