#include "Shape.h"

Shape::Shape()
{

}

Shape::~Shape()
{
}

void Shape::set_start(QPoint s)
{
	start = s;
}

void Shape::set_end(QPoint e)
{
	end = e;
}

void Shape::set_temp(QPoint s)
{

}

void Shape::Ctrl_down(int k) {
	CTRL = k;
}

//int Shape::add_point(QPoint t) {
//	arr.push_back(t);
//	return arr.size();
//}