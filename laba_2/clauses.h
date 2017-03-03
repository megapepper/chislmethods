#ifndef CLAUSES_H
#define CLAUSES_H

#include <cmath>


const double d_=0.1;
const double x0_=-d_;
const double Aa_=1;
const double x1_=0.1;
const double h_=1;
const double l_=1;
const double a0_=-0.1;
const double b0_=0.1;

double stupNach(double x);
double stupGran(double x);

double rectNach(double x);
double rectGran(double x);

double gaussNach(double x);
double gaussGran(double x);

#endif // CLAUSES_H
