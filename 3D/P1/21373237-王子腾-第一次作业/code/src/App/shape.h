#pragma once

#include <QtGui>

class Shape
{
public:
	Shape();
	virtual ~Shape();
	virtual void Draw(QPainter& paint) = 0;
	virtual void set_start(QPoint s);
	virtual void set_end(QPoint e);
	virtual void set_temp(QPoint s);
	virtual void Ctrl_down(int k);
	//int add_point(QPoint t);

public:
	enum Type
	{
		kDefault = 0,
		kLine = 1,
		kRect = 2,
		kElli = 3,
		kPoly = 4,
		kCurve = 5
	};

protected:
	QPoint start;
	QPoint end;
	QPoint temp;
	int CTRL=0;
};