#include "Elli.h"

Elli::Elli()
{
}

Elli::~Elli()
{
}

void Elli::Draw(QPainter& painter)
{
	//painter.drawEllipse(start.x(), start.y(),
	//	end.x() - start.x(), end.y() - start.y());
  
	int x0 = start.x();
	int y0 = start.y();
	int x1 = end.x();
	int y1 = end.y();

    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    if (CTRL) {
        dx = dy = (dx + dy) / 2;
        if (y1 - y0 < 0 && x1 - x0 < 0) {
            x1 = x0 - dx;
            y1 = y0 - dx;
        }
        else if (y1 - y0 < 0 && x1 - x0 > 0) {
            x1 = x0 + dx;
            y1 = y0 - dx;
        }
        else if (y1 - y0 > 0 && x1 - x0 < 0) {
            x1 = x0 - dx;
            y1 = y0 + dx;
        }
        else {
            x1 = x0 + dx;
            y1 = y0 + dx;
        }
    }

	double a = abs(x1 - x0) / 2.0;
	double b = abs(y1 - y0) / 2.0;
	double xc = (x0 + x1) / 2.0;
	double yc = (y0 + y1) / 2.0;

	double x = 0;
	double y = b;
	painter.drawPoint(xc + a, yc);
	painter.drawPoint(xc - a, yc);
	painter.drawPoint(xc , yc + b);
	painter.drawPoint(xc , yc - b);
	
    double d1 = b * b + a * a * (-b + 0.25);
    while (b * b * (x + 1) < a * a * (y - 0.5))
    {
        if (d1 < 0)
        {
            d1 += b * b * (2 * x + 3);
        }
        else
        {
            d1 += b * b * (2 * x + 3) + a * a * (-2 * y + 2);
            y--;
        }
        x++;
        painter.drawPoint(x + xc, y + yc);
        painter.drawPoint(-x + xc, y + yc);
        painter.drawPoint(x + xc, -y + yc);
        painter.drawPoint(-x + xc, -y + yc);
    }
    double d2 = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b;
    while (y > 0)
    {
        if (d2 < 0)
        {
            d2 += b * b * (2 * x + 2) + a * a * (-2 * y + 3);
            x++;
        }
        else
        {
            d2 += a * a * (-2 * y + 3);
        }
        y--;
        painter.drawPoint(x + xc, y + yc);
        painter.drawPoint(-x + xc, y + yc);
        painter.drawPoint(x + xc, -y + yc);
        painter.drawPoint(-x + xc, -y + yc);
    }

}