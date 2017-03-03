#ifndef WINDOW_H
#define WINDOW_H

#include <QObject>
#include <QWidget>

#include <QBoxLayout>
#include <QSlider>
#include "qcustomplot.h"
#include "principal.h"

class Window : public QWidget
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    void inicialize(double xLim,
                    double tLim,
                    double Q,
                    int nT,
                    f_x Ugran,
                    f_x Unach,
                    int Numb_KRS);

signals:

public slots:
    void updateGraph(int t);

private:
    QBoxLayout *layout;
    QSlider *slider;
    QCustomPlot *graph;

    Principal *principal;

};

#endif // WINDOW_H
