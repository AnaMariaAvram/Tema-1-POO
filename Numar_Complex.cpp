#include "Numar_Complex.h"
#include <iostream>
#include <string>
#include <string>
#include <stdlib.h>
using namespace std;
Numar_Complex::Numar_Complex()
{
    re=0;
    im=0;
}

Numar_Complex::~Numar_Complex()
{
   //cout<<"Se apeleaza destructorul";
}
Numar_Complex::Numar_Complex(double a,double b)
{
    a = re;
    b = im;
}
void Numar_Complex::set_numar(double a,double b)
{
    re=a;
    im=b;

}
double Numar_Complex::get_numar(string sir)
{
    if(sir=="im")
        return im;
    if(sir=="re")
        return re;
}

Numar_Complex operator +(const Numar_Complex &a, const Numar_Complex &b)
{
    Numar_Complex temp;

    temp.re = a.re+b.re;
    temp.im = a.im+b.im;

    return temp;

}
Numar_Complex operator*(const Numar_Complex &a, const Numar_Complex &b)
{
    Numar_Complex temp;

    temp.re = a.re*b.re-a.im*b.im;
    temp.im = a.re*b.im+a.im*b.re;

    return temp;
}


istream& operator>>(istream& input, Numar_Complex& ob)
{

    input>>ob.re;
    input>>ob.im;

    return input;
}

ostream& operator<<(ostream& output, Numar_Complex& ob)
{
    if(ob.im==0)
    {
        output<<ob.re<<" ";
    }

    else
    {

        string semn;
        if(ob.im<0)
            semn='-';
        else
            semn='+';

        if(ob.re!=0)
        {
            output<<ob.re;
            output<<semn;
        }
        else
            if(ob.im<0) output<<semn;



        if(abs(ob.im)!=1) output<<"i*"<<abs(ob.im)<<" ";
        else output<<"i ";


    }
    return output;
}



