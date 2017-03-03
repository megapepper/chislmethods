#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include "qcustomplot.h"
#include "principal.h"
#include "window.h"

class Widget : public QWidget
{
    Q_OBJECT

private:
    QGridLayout *layout;
    Window *windows[12];

public:

//    const double xLim=1;
//    const double tLim=2;
//    const double nX=100;
//    const double nT=200;

    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
