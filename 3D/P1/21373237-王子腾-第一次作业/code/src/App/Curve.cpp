#include "Curve.h"

Curve::Curve()
{
}

Curve::~Curve()
{
	point_list_.clear();
}


void Curve::set_end(QPoint e)
{
	end = e;
	point_list_.push_back(e);
}

void Curve::Draw(QPainter& painter)
{
	for (int i = 0; i < point_list_.size() - 1; i++)
	{
		painter.drawLine(point_list_[i], point_list_[i + 1]);
	}
}