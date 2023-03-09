#include "Poly.h"

Poly::Poly()
{
}

Poly::~Poly()
{
	point_list_.clear();
}

void Poly::set_start(QPoint s)
{
	point_list_.push_back(s);
}

void Poly::set_temp(QPoint s)
{
	temp = s;
}


void Poly::Draw(QPainter& painter)
{
	int k = point_list_.size() - 1;
	for (int i = 0; i < k; i++)
	{
		painter.drawLine(point_list_[i], point_list_[i + 1]);
	}
	if(k>=1) painter.drawLine(point_list_[k], temp);
	if(k>=0) painter.drawLine(point_list_[0], temp);

}
