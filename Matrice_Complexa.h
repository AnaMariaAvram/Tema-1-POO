#ifndef MATRICE_COMPLEXA_H
#define MATRICE_COMPLEXA_H
#include <Numar_Complex.h>

class Matrice_Complexa
{
    int nr_linii,nr_coloane;
    Numar_Complex **mat;
public:

    friend class Numar_Complex;

    Matrice_Complexa(int n,int m); ///Constructor de initializare
    Matrice_Complexa(int n,int m,Numar_Complex nr);  ///Constructor de initializare cu un nr.
    Matrice_Complexa(const Matrice_Complexa &ob); ///Constructor de copiere
    ~Matrice_Complexa();

    friend istream& operator >>(istream&, Matrice_Complexa&);
    friend ostream& operator <<(ostream&, Matrice_Complexa&);
    friend Matrice_Complexa operator+(const Matrice_Complexa &a, const Matrice_Complexa &b);
    friend Matrice_Complexa operator*( const Matrice_Complexa &a, const Matrice_Complexa &b);


};

#endif // MATRICE_COMPLEXA_H
