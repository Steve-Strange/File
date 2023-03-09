#include "minidraw.h"

#include <QToolBar>

MiniDraw::MiniDraw(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	view_widget_ = new ViewWidget();
	Creat_Action();
	Creat_ToolBar();
	

	setCentralWidget(view_widget_);
}

void MiniDraw::Creat_Action() {
	Action_About = new QAction(tr("&About"), this);
	connect(Action_About, &QAction::triggered, this, &MiniDraw::AboutBox);

	Action_Line = new QAction(tr("&Line"), this);
	connect(Action_Line, SIGNAL(triggered()), view_widget_, SLOT(setLine()));

	Action_Rect = new QAction(tr("&Rectangle"), this);
	connect(Action_Rect, &QAction::triggered, view_widget_, &ViewWidget::setRect);

	Action_Elli = new QAction(tr("&Ellipse"), this);
	connect(Action_Elli, &QAction::triggered, view_widget_, &ViewWidget::setElli);

	Action_Poly = new QAction(tr("&Polygon"), this);
	connect(Action_Poly, &QAction::triggered, view_widget_, &ViewWidget::setPoly);

	Action_Curve = new QAction(tr("&Curve"), this);
	connect(Action_Curve, &QAction::triggered, view_widget_, &ViewWidget::setCurve);

	Action_Clear = new QAction(tr("&Reset"), this);
	connect(Action_Clear, &QAction::triggered, this, &MiniDraw::Clear);
}

void MiniDraw::Creat_ToolBar() {
	pToolBar = addToolBar(tr("&Main"));
	pToolBar->setMovable(false);
	pToolBar->addAction(Action_Line);
	pToolBar->addAction(Action_Rect);
	pToolBar->addAction(Action_Poly);
	pToolBar->addAction(Action_Elli);
	pToolBar->addAction(Action_Curve);
	ToolBar_Spacer = new QWidget();
	ToolBar_Spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	pToolBar->addWidget(ToolBar_Spacer);
	pToolBar->addAction(Action_About);
	pToolBar->addAction(Action_Clear);
}


void MiniDraw::AboutBox() {
	QMessageBox::about(this, tr("About"), tr("MiniDraw"));
}

void MiniDraw::Clear() {
	view_widget_->clearAll();
}

MiniDraw::~MiniDraw() {}
