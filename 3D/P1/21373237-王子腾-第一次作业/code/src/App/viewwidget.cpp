#include "viewwidget.h"
#include <QDebug>

ViewWidget::ViewWidget(QWidget* parent)
	: QWidget(parent)	
{
	ui.setupUi(this);
	draw_status_ = false;
	shape_ = NULL;
	type_ = Shape::kDefault;
	setFocusPolicy(Qt::StrongFocus);
}

ViewWidget::~ViewWidget()
{
	for (size_t i = 0; i < shape_list_.size(); i++)
	{
		if (shape_list_[i])
		{
			delete shape_list_[i];
			shape_list_[i] = NULL;
		}
	}
}

void ViewWidget::setLine()
{
	if (!draw_status_)	type_ = Shape::kLine;
}

void ViewWidget::setRect()
{
	if (!draw_status_)	type_ = Shape::kRect;
}

void ViewWidget::setElli()
{
	if (!draw_status_)	type_ = Shape::kElli;
}

void ViewWidget::setPoly()
{
	if (!draw_status_)	type_ = Shape::kPoly;
}

void ViewWidget::setCurve()
{
	if (!draw_status_)	type_ = Shape::kCurve;
}

void ViewWidget::clearAll() {
	for (size_t i = 0, k = shape_list_.size(); i < k; ++i)
	{
		if (shape_list_[i])
		{
			delete shape_list_[i];
			shape_list_[i] = NULL;
		}
	}       //防止内存泄露
	shape_list_.clear();
}

void ViewWidget::mousePressEvent(QMouseEvent* event)
{
	if (Qt::LeftButton == event->button())
	{
		if (!draw_status_)//按下左键的意义已经不只是创建新图形了，需要判断
		{
			switch (type_)
			{
			case Shape::kDefault:
				break;
			case Shape::kLine:
				shape_ = new Line();
				break;
			case Shape::kRect:
				shape_ = new Rect();
				break;
			case Shape::kElli:
				shape_ = new Elli();
				break;
			case Shape::kPoly:
				shape_ = new Poly();
				break;
			case Shape::kCurve:
				shape_ = new Curve();
				break;

			}
		}
		if (shape_ != NULL)
		{	
			draw_status_ = true;
			start_point_ = end_point_ = event->pos();
			shape_->set_start(start_point_);
			shape_->set_end(end_point_);
			shape_->set_temp(start_point_);     //多边形temp初始值 防止跑到左上角
			shape_->Ctrl_down(k);
			//qDebug("%d %d",start_point_.x(), start_point_.y());
		}
	}
	else if (Qt::RightButton == event->button())
	{
		if (shape_ != NULL && type_ == Shape::kPoly)
		{
			draw_status_ = false;
			shape_list_.push_back(shape_);
			shape_ = NULL;
		}
	}
	update();
}

void ViewWidget::mouseMoveEvent(QMouseEvent* event)
{
	setMouseTracking(true);
	if (draw_status_ && shape_ != NULL)
	{
		end_point_ = event->pos();
		shape_->set_end(end_point_);
		if (type_ == Shape::Type::kPoly) shape_->set_temp(event->pos());
		shape_->Ctrl_down(k);
	}
}

void ViewWidget::mouseReleaseEvent(QMouseEvent* event)
{
	if (shape_ != NULL && type_ != Shape::Type::kPoly)
	{
		draw_status_ = false;
		shape_list_.push_back(shape_);
		shape_->Ctrl_down(k);
		shape_ = NULL;
		
	}
	
}

void ViewWidget::paintEvent(QPaintEvent*)
{
	QPainter painter(this);

	for (int i = 0; i < shape_list_.size(); i++)
	{
		shape_list_[i]->Draw(painter);
	}

	if (shape_ != NULL) {
		shape_->Draw(painter);
	}

	update();
}

void ViewWidget::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Control) {  // 如果按下了CTRL键
		k = 1;
		qDebug() << "down";
	}
	if (shape_ != NULL) shape_->Ctrl_down(k);
	
}
void ViewWidget::keyReleaseEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Control) {
		k = 0;
		qDebug() << "release ";
	}
	if (shape_ != NULL) shape_->Ctrl_down(k);
}
