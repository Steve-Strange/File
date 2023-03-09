#pragma once

#include "Shape.h"
#include <vector>

class Poly : public Shape {
public:
	Poly();
	~Poly();

	void Draw(QPainter& painter);
	void set_start(QPoint s);//多边形的start和end函数都需要单独定义
	void set_temp(QPoint s);
private:
	QVector<QPoint> point_list_;
	QPoint temp;
};