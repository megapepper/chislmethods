#include "widget.h"
#include "clauses.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    const double Q=0.9;

    const double tLim=2;
    const double xLim=1;
    const int nX=100;
    const int nT=200;

    layout = new QGridLayout();

    windows[0] = new Window();
    windows[1] = new Window();
    windows[2] = new Window();
    windows[3] = new Window();
    windows[4] = new Window();
    windows[5] = new Window();
    windows[6] = new Window();
    windows[7] = new Window();
    windows[8] = new Window();
    windows[9] = new Window();
    windows[10] = new Window();
    windows[11] = new Window();

    windows[0]->inicialize(xLim,tLim,Q,nT,gaussGran,gaussNach,Principal::KRS1);
    windows[1]->inicialize(xLim,tLim,Q,nT,rectGran,rectNach,Principal::KRS1);
    windows[2]->inicialize(xLim,tLim,Q,nT,stupGran,stupNach,Principal::KRS1);

    windows[3]->inicialize(xLim,tLim,Q,nT,gaussGran,gaussNach,Principal::KRS2);
    windows[4]->inicialize(xLim,tLim,Q,nT,rectGran,rectNach,Principal::KRS2);
    windows[5]->inicialize(xLim,tLim,Q,nT,stupGran,stupNach,Principal::KRS2);

   windows[6]->inicialize(xLim,tLim,Q,nT,gaussGran,gaussNach,Principal::KRS3);
   windows[7]->inicialize(xLim,tLim,Q,nT,rectGran,rectNach,Principal::KRS3);
   windows[8]->inicialize(xLim,tLim,Q,nT,stupGran,stupNach,Principal::KRS3);

    windows[9]->inicialize(xLim,tLim,Q,nT,gaussGran,gaussNach,Principal::KRS4);
    windows[10]->inicialize(xLim,tLim,Q,nT,rectGran,rectNach,Principal::KRS4);
    windows[11]->inicialize(xLim,tLim,Q,nT,stupGran,stupNach,Principal::KRS4);

//    windows[0]->inicialize(1,2,100,200,gaussGran,gaussNach,Principal::KRS1);
//    windows[1]->inicialize(1,2,100,200,rectGran,rectNach,Principal::KRS1);
//    windows[2]->inicialize(1,2,100,200,stupGran,stupNach,Principal::KRS1);

//    windows[3]->inicialize(1,2,100,200,gaussGran,gaussNach,Principal::KRS2);
//    windows[4]->inicialize(1,2,100,200,rectGran,rectNach,Principal::KRS2);
//    windows[5]->inicialize(1,2,100,200,stupGran,stupNach,Principal::KRS2);

////   windows[6]->inicialize(xLim,tLim,nX,nT,gaussGran,gaussNach,Principal::KRS3);
////   windows[7]->inicialize(xLim,tLim,nX,nT,rectGran,rectNach,Principal::KRS3);
////   windows[8]->inicialize(xLim,tLim,nX,nT,stupGran,stupNach,Principal::KRS3);

//    windows[9]->inicialize(1,2,100,200,gaussGran,gaussNach,Principal::KRS4);
//    windows[10]->inicialize(1,2,100,200,rectGran,rectNach,Principal::KRS4);
//    windows[11]->inicialize(1,2,100,200,stupGran,stupNach,Principal::KRS4);


    layout->addWidget(windows[0],0,0);
    layout->addWidget(windows[1],0,1);
    layout->addWidget(windows[2],0,2);
    layout->addWidget(windows[3],1,0);
    layout->addWidget(windows[4],1,1);
    layout->addWidget(windows[5],1,2);
    layout->addWidget(windows[6],2,0);
    layout->addWidget(windows[7],2,1);
    layout->addWidget(windows[8],2,2);
    layout->addWidget(windows[9],3,0);
    layout->addWidget(windows[10],3,1);
    layout->addWidget(windows[11],3,2);

    setLayout(layout);
    setFixedSize(1270,700);
}

Widget::~Widget()
{

}
