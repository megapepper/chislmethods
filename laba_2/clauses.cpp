#include "clauses.h"

//double hT=tLim/(nT-1);
//double hX=Aa_*hT/Q;
//double nX=round(xLim/hX+1);
//double hX=xLim/(nX-1);
//double Q=Aa_*hT/hX;

double stupNach(double x)
{
    if(x<x1_)
    {
        return h_;
    }
    return 0;
}

double stupGran(double x)
{
    if(-Aa_*x<x1_)
    {
        return h_;
    }
    return 0;
}

double rectNach(double x)
{
    if ((x>a0_)&&(x<b0_))
    {
        return l_;
    }
    return 0;
}

double rectGran(double x)
{
    if ((-Aa_*x>a0_)&&(-Aa_*x<b0_))
    {
        return l_;
    }
    return 0;
}

double gaussNach(double x)
{
    return exp(-pow((x-x0_),2)/pow(d_,2));
}

double gaussGran(double x)
{
    return exp(-pow((-x0_-Aa_*x),2)/pow(d_,2));
}
