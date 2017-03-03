#include "window.h"

Window::Window(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout();
    graph = new QCustomPlot();
    graph->xAxis->setRange(0,1);
    graph->yAxis->setRange(-1.2,1.2);
    slider = new QSlider(Qt::Horizontal);

    layout->addWidget(graph);
    layout->addWidget(slider);

    principal = nullptr;

    connect(slider,SIGNAL(valueChanged(int)),this,SLOT(updateGraph(int)));

    setLayout(layout);
}

void Window::inicialize(double xLim, double tLim, double Q, int nT, f_x Ugran, f_x Unach, int Numb_KRS)
{
    if(principal != nullptr)
    {
        delete principal;
    }
    principal = new Principal(xLim,tLim,Q,nT,Ugran,Unach,Numb_KRS);
    slider->setRange(0,nT-1);
    updateGraph(0);
}

void Window::updateGraph(int t)
{
    if(principal!=nullptr)
    {
        graph->clearGraphs();
        graph->addGraph();
        graph->graph(0)->addData(principal->getX(),principal->getVector(t));
        graph->replot();
    }
}
