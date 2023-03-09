#include "Line.h"

Line::Line()
{
}

Line::~Line()
{
}

void Line::Draw(QPainter& painter)
{
	//painter.drawLine(start, end);

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
	int D = 2 * dy - dx;
	int y = y0;

	if (dx >= dy) {
		if (x1 >= x0) {
			for (int x = x0; x <= x1; x++) {
				painter.drawPoint(x, y);
				if (D > 0) {
					if (y1 > y0) y++;
					else y--;
					D -= 2 * dx;
				}
				D += 2 * dy;
			}
		}
		else {
			for (int x = x0; x >= x1; x--) {
				painter.drawPoint(x, y);
				if (D > 0) {
					if (y1 > y0) y++;
					else y--;
					D -= 2 * dx;
				}
				D += 2 * dy;
			}
		}
	}
	else {
		x0 = start.y();
		y0 = start.x();
		x1 = end.y();
		y1 = end.x();
		dx = abs(x1 - x0);
		dy = abs(y1 - y0);
		D = 2 * dy - dx;
		y = y0;

		if (x1 >= x0) {
			for (int x = x0; x <= x1; x++) {
				painter.drawPoint(y, x);
				if (D > 0) {
					if (y1 > y0) y++;
					else y--;
					D -= 2 * dx;
				}
				D += 2 * dy;
			}
		}
		else {
			for (int x = x0; x >= x1; x--) {
				painter.drawPoint(y, x);
				if (D > 0) {
					if (y1 > y0) y++;
					else y--;
					D -= 2 * dx;
				}
				D += 2 * dy;
			}
		}
	}


	/*if (dx == 0) {
		if (dy > 0) for (int i = y0; i <= y1; i++) painter.drawPoint(x0, i);
		else for (int i = y1; i <= y0; i++) painter.drawPoint(x0, i);
	}
	else if (dy == 0) {
		if (dx > 0) for (int i = x0; i <= x1; i++) painter.drawPoint(i,y0);
		else for (int i = x1; i <= x0; i++) painter.drawPoint(i,y0); 
	}
	else {
		if (abs(dx) >= abs(dy)) {
			int k = (int)dx / dy;
			int extra = abs(dx - k * dy);
			int cnt = dy;
			int insert = 0;
			if (extra) insert = cnt / extra;
				if (y1 > y0) {
					if (x1 > x0) {
						int x = x0;
						for (int i = y0; i <= y1; i++) {
							if (extra) {
								if (i % insert == 0) painter.drawPoint(x++,i);
								extra--;
							}
							for (int j = 0; j < k &&x <=x1; j++) {
								painter.drawPoint(x++, i);
							}
						}
					}
				}
		}
	}*/



}
