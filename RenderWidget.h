//
// copyright 2018 Palestine Polytechnic Univeristy
//
// This software can be used and/or modified for academich use as long as 
// this commented part is listed
//
// Last modified by: Zein Salah, on 24.04.2018
//


#pragma once

#include <QWidget>

class RenderWidget : public QWidget
{
    Q_OBJECT

  public:
    RenderWidget(QWidget *parent = 0);

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

    void drawLine(QPair<int, int> p1, QPair<int, int> p2);

    void drawCircle(QPair<int, int> c, int r);

    void drawArc(QPair<int, int> c, double t1, double t2, int r);

  protected:
    void paintEvent(QPaintEvent *event) override;

};
