#include "principal.h"

Principal::Principal(double xLim,
                     double tLim,
                     double Q,
                     //int nX,
                     int nT,
                     f_x Ugran,
                     f_x Unach,
                     int Numb_KRS)
{
    Ugran_ = Ugran;
    Unach_ = Unach;

    xLim_=xLim;
    tLim_=tLim;
    Q_=Q;

    nT_ = nT;

    hT_ = tLim_/(nT_-1);
    hX_=Aa_*hT_/Q_;
    nX_=xLim_/hX_+1;

    //nX_ = nX;

    //hX_ = xLim_/(nX_-1);
    //Q_=Aa_*hT_/hX_;

    U1_ = new QVector<QVector<double>>(nT_);
    for(int i=0;i<nT_;i++)
    {
        U1_->operator [](i) = QVector<double>(nX_);
    }

    //Начальное условие
    for(int i=0;i<nX_;i++)
    {
        U1_->operator [](0)[i]=Unach_(i*hX_);
    }
    //Граничное условие
    for(int i=0;i<nT_;i++)
    {
        U1_->operator [](i)[0]=Ugran_(i*hT_);
    }

    switch(Numb_KRS)
    {
    case KRS1:
        for(int n=1;n<nT_;n++)
        {
            for(int j=1;j<nX_;j++)
            {               
                U1_->operator [](n)[j] = -Aa_*hT_*1.0/hX_*(U1_->operator [](n-1)[j]-U1_->operator [](n-1)[j-1])+U1_->operator [](n-1)[j];

            }

        }
        break;
    case KRS2:
        for(int n=1;n<nT_;n++)
        {
            for(int j=1;j<nX_;j++)
            {
                U1_->operator [](n)[j]=(Q_*U1_->operator [](n)[j-1]+U1_->operator [](n-1)[j])/(1+Q_);
            }
        }
        break;
    case KRS3:
        int i,n,j;
        double *A;
        double *B;
        double *a;
        double *b;
        double *c;
        double *f;
        A= new double[nX_];
        B= new double[nX_];
        a= new double[nX_];
        b= new double[nX_];
        c= new double[nX_];
        f= new double[nX_];
        for (i=0;i<nX_;i++){
            A[i]=0;
            B[i]=0;
            a[i]=-Q/2;
            b[i]=1;
            c[i]=Q/2;
            f[i]=U1_->operator [](0)[i];
        }
        for (n=0;n<nT_-1;n++){
            for (i=0;i<nX_;i++){
                f[i]=U1_->operator [](n)[i];
            }
            //находим правую точку явной схемой
            U1_->operator [](n+1)[nX_-1]=-Q*(U1_->operator [](n)[nX_-1]-U1_->operator [](n)[nX_-2])+U1_->operator [](n)[nX_-1];
            B[nX_-1]=U1_->operator [](n+1)[nX_-1];
            A[nX_-1]=0;
            j=nX_-1;
            while (j>1){
                A[j-1]=-a[j-1]/(c[j-1]*A[j]+b[j-1]);
                B[j-1]=(f[j-1]-c[j-1]*B[j])/(c[j-1]*A[j]+b[j-1]);
                j=j-1;
            }
            B[0]=Ugran_(n*hT_);
            U1_->operator [](n+1)[0]=B[0];
            for (j=1;j<nX_-1;j++){
                  U1_->operator [](n+1)[j]=A[j]*U1_->operator [](n+1)[j-1]+B[j];
            }
        }

        delete[]A;
        delete[]B;
        delete[]a;
        delete[]b;
        delete[]c;
        delete[]f;
        break;

    case KRS4:
        for(int n=1;n<nT_;n++)
        {
            for(int j=1;j<nX_-1;j++)
            {
                U1_->operator [](n)[j]=U1_->operator [](n-1)[j]-Q_/2*(U1_->operator [](n-1)[j+1]-U1_->operator [](n-1)[j-1])+pow(Q_,2)/2*(U1_->operator [](n-1)[j+1]-2*U1_->operator [](n-1)[j]+U1_->operator [](n-1)[j-1]);
            }
            U1_->operator [](n)[nX_-1]=(Q_*U1_->operator [](n)[nX_-2]+U1_->operator [](n-1)[nX_-1])/(1+Q_);
        }
        break;
    }

}

QVector<double> Principal::getVector(int t)
{
    return U1_->at(t);
}

QVector<double> Principal::getX()
{
    QVector<double> result;

    for(int i=0;i<nX_;i++)
    {
        result.push_back(i*hX_);
    }
    return result;
}
