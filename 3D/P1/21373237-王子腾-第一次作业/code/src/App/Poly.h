#pragma once

#include "Shape.h"
#include <vector>

class Poly : public Shape {
public:
	Poly();
	~Poly();

	void Draw(QPainter& painter);
	void set_start(QPoint s);//����ε�start��end��������Ҫ��������
	void set_temp(QPoint s);
private:
	QVector<QPoint> point_list_;
	QPoint temp;
};