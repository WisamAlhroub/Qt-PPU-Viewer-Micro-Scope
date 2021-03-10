//
// copyright 2018 Palestine Polytechnic Univeristy
//
// This software can be used and/or modified for academich use as long as 
// this commented part is listed
//
// Last modified by: Zein Salah, on 24.02.2021
//


#include "RenderWidget.h"
#include <QPainter>
#include <cmath>

RenderWidget::RenderWidget(QWidget *parent) : QWidget(parent)
{
  // to be implemeted later
}

QSize RenderWidget::minimumSizeHint() const
{
  return QSize(100, 100);
}

QSize RenderWidget::sizeHint() const
{
  return QSize(600, 600);
}

void RenderWidget::paintEvent(QPaintEvent *)
{
	QPainter painter(this);

	QColor color(0, 0, 0);
	painter.setPen(color);

	painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
  
	drawLine({ 200, 450 }, { 400, 450 });
	drawLine({ 200, 435 }, { 252, 435 });
	drawLine({ 348, 435 }, { 400, 435 });
	drawLine({ 200, 450 }, { 200, 435 });
	drawLine({ 400, 450 }, { 400, 435 });

	drawArc({ 300, 450 }, 0, 3.14, 50);
	drawCircle({ 300, 420 }, 10);

	drawArc({ 300, 330 }, 3.926, 7.4, 70);
	drawArc({ 300, 330 }, 3.72, 4.3, 90);
	drawArc({ 300, 330 }, 5.085, 7.4, 90);

	drawLine({ 210, 380 }, { 270, 380 });
	drawLine({ 210, 370 }, { 270, 370 });
	drawLine({ 210, 380 }, { 210, 370 });
	drawLine({ 270, 380 }, { 270, 370 });

	drawCircle({ 318, 248 }, 20);
	drawCircle({ 318, 248 }, 15);

	drawLine({ 300, 300 }, { 315, 268 });
	drawLine({ 333, 233 }, { 354, 191 });
	drawLine({ 300, 300 }, { 260, 280 });
	drawLine({ 354, 191 }, { 314, 171 });
	drawLine({ 314, 171 }, { 260, 280 });

	drawLine({ 294, 298 }, { 285, 318});
	drawLine({ 266, 283 }, { 256, 303 });
	drawLine({ 256, 303 }, { 285, 318 });

	drawLine({ 348, 189 }, { 364, 160 });
	drawLine({ 320, 173 }, { 335, 145 });
	drawLine({ 335, 145 }, { 364, 160 });
}

void RenderWidget::drawLine(QPair<int, int> p1, QPair<int, int> p2)
{
	QPainter painter(this);
	QPen pen = Qt::black;

	pen.setWidth(2);
	painter.setPen(pen);

	int sx = p1.first < p2.first ? 1 : -1;
	int sy = p1.second < p2.second ? 1 : -1;

	int dx = abs(p2.first - p1.first);
	int dy = abs(p2.second - p1.second) * -1;

	int p = dx + dy;

	while (p1.first != p2.first || p1.second != p2.second)
	{
		painter.drawPoint(p1.first, p1.second);

		if (p * 2 >= dy)
		{
			p += dy;
			p1.first += sx;
		}
		else
		{
			p += dx;
			p1.second += sy;
		}
	}
	
}

void drawCirclePoints(QPair<int, int> c, int x, int y, QPainter& painter)
{
	painter.drawPoint(c.first + x, c.second + y);
	painter.drawPoint(c.first - x, c.second + y);
	painter.drawPoint(c.first + x, c.second - y);
	painter.drawPoint(c.first - x, c.second - y);
	painter.drawPoint(c.first + y, c.second + x);
	painter.drawPoint(c.first - y, c.second + x);
	painter.drawPoint(c.first + y, c.second - x);
	painter.drawPoint(c.first - y, c.second - x);
}

void RenderWidget::drawCircle(QPair<int, int> c, int r)
{
	QPainter painter(this);
	QPen pen = Qt::black;

	pen.setWidth(2);
	painter.setPen(pen);

	int x = 0;
	int y = r;
	int d = 3 - 2 * r;

	drawCirclePoints(c, x, y, painter);

	for (x = 1; x <= y; x++)
	{
		if (d > 0)
		{
			y--;
			d += 4 * (x - y) + 10;
		}
		else
		{
			d += +4 * x + 6;
		}

		drawCirclePoints(c, x, y, painter);
	}
}

void RenderWidget::drawArc(QPair<int, int> c, double t1, double t2, int r)
{
	QPainter painter(this);
	QPen pen = Qt::black;

	pen.setWidth(2);
	painter.setPen(pen);

	double dt= 1.0 / r;
	int x = r * cos(t1);
	int y = r * sin(t1);

	while (t1 <= t2)
	{
		t1 += dt;
		x = round(r * cos(t1));
		y = round(r * sin(t1));

		painter.drawPoint(c.first + x , c.second - y);
	}
}