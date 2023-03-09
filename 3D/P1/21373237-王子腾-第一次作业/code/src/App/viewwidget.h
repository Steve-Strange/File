#pragma once
#include <QKeyEvent>
#include <ui_viewwidget.h>
#include "Shape.h"
#include "Line.h"
#include "Rect.h"
#include "Elli.h"
#include "Poly.h"
#include "Curve.h"
#include <qevent.h>
#include <qpainter.h>
#include <QWidget>
#include <vector>


class ViewWidget : public QWidget
{
	Q_OBJECT

public:
	ViewWidget(QWidget* parent = 0);
	~ViewWidget();

private:
	Ui::ViewWidget ui;

private:
	bool draw_status_;
	QPoint start_point_;
	QPoint end_point_;
	QPoint temp_point_;
	Shape::Type type_;
	Shape* shape_;
	std::vector<Shape*> shape_list_;
	int k = 0;

public:
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void keyPressEvent(QKeyEvent* event); //���̰����¼�
	void keyReleaseEvent(QKeyEvent* event); //�����ɿ��¼�

public:
	void paintEvent(QPaintEvent*);
signals:
public slots:
	void setLine();
	void setRect();
	void setElli();
	void setPoly();
	void setCurve();
	void clearAll();
};
