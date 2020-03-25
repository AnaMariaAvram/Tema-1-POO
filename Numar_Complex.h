#ifndef NUMAR_COMPLEX_H
#define NUMAR_COMPLEX_H
#include <iostream>
#include <string>
using namespace std;

class Matrice_Complexa;

class Numar_Complex
{
    double re,im;
public:
    Numar_Complex();
    Numar_Complex(double a,double b);
    ~Numar_Complex();
    void set_numar(double a,double b);
    double get_numar(string ce);

    friend istream& operator>> (istream&, Numar_Complex&);
    friend ostream& operator<<(ostream&, Numar_Complex&);

    friend Numar_Complex operator +(const Numar_Complex &a, const Numar_Complex &b);
    friend Numar_Complex operator *(const Numar_Complex &a, const Numar_Complex &b);

    friend class Matrice_Complexa;


};

#endif // NUMAR_COMPLEX_H
