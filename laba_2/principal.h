#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QVector>

typedef double (*f_x)(double x);

class Principal
{
public:
    Principal(double xLim,
              double tLim, double Q,
              int nT,
              f_x Ugran,
              f_x Unach,
              int Numb_KRS);

    QVector<double> getVector(int t);
    QVector<double> getX();
    enum Number_KRS {KRS1,KRS2,KRS3,KRS4};

private:

    double tLim_;//Предел по времени
    double xLim_;//Предел по координате

    int nX_;//Количество точек разбиений
    int nT_;//Количество точек разбиений

    double hT_;//Шаг по t
    double hX_;//Шаг по x

    double Q_;//число Курранта

    double *x_;//Массив узлов
    double *t_;//Массив узлов

    const int Aa_ = 1;//Скорость распространения волны(из ур-я)

    f_x Unach_;
    f_x Ugran_;

    QVector<QVector<double>> *U1_;


};

#endif // PRINCIPAL_H

/*

    for n=1:(nt-1)
    for i=1:nx
    f(i)=U3(i)/ht;
    end;
    %находим правую точку явной схемой
    U3(nx)=-Aa*ht/hx*(U3(nx)-U3(nx-1))+U3(nx);
    %ищем коэффициенты для прогонки
    B(nx)=U3(nx);
    A(nx)=0;
    j=nx;
    while j>2
    A(j-1)=-a(j-1)/(c(j-1)*A(j)+b(j-1));
    B(j-1)=(f(j-1)-c(j-1)*B(j))/(c(j-1)*A(j)+b(j-1));
    j=j-1;
    end;
    B(1)=G(t(n));
    U3(1)=B(1);
    %ищем решение на слое начиная слева
    for j=2:nx-1
        U3(j)=A(j)*U3(j-1)+B(j);
    end;
*/
