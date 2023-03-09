#include "Rect.h"

Rect::Rect()
{
}

Rect::~Rect()
{
}

void Rect::Draw(QPainter& painter)
{
	if (CTRL) {
		if ((end.x() - start.x()) < 0 && (end.y() - start.y()) > 0) painter.drawRect(start.x(), start.y(),
			-(-end.x() + start.x() + end.y() - start.y()) / 2, (-end.x() + start.x() + end.y() - start.y()) / 2);

		else if ((end.x() - start.x()) > 0 && (end.y() - start.y()) < 0) painter.drawRect(start.x(), start.y(),
			(end.x() - start.x() - end.y() + start.y()) / 2, -(end.x() - start.x() - end.y() + start.y()) / 2);
		else painter.drawRect(start.x(), start.y(),
			(end.x() - start.x() + end.y() - start.y()) / 2, (end.x() - start.x() + end.y() - start.y()) / 2);
	}
	else {
		painter.drawRect(start.x(), start.y(),
			end.x() - start.x(), end.y() - start.y());
	}
}
