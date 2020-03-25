#include "Matrice_Complexa.h"
#include <iostream>
#include <Numar_Complex.h>

using namespace std;

Matrice_Complexa::Matrice_Complexa(int n,int m)
{
    Numar_Complex nr;
    nr.set_numar(0,0);
    nr_linii=n;
    nr_coloane=m;
    mat = new Numar_Complex*[nr_linii];
    for (int i = 0; i < nr_linii; i++)
        mat[i] = new Numar_Complex[nr_coloane];

    for(int i=0; i<nr_linii; i++)
        for(int j=0; j<nr_coloane; j++)
            mat[i][j]= nr;

}

Matrice_Complexa::Matrice_Complexa(int n,int m,Numar_Complex nr)
{
    nr_linii=n;
    nr_coloane=m;
    mat = new Numar_Complex*[nr_linii];
    for (int i = 0; i < nr_linii; i++)
        mat[i] = new Numar_Complex[nr_coloane];

    for(int i=0; i<nr_linii; i++)
        for(int j=0; j<nr_coloane; j++)
            mat[i][j]= nr;

}

Matrice_Complexa::Matrice_Complexa(const Matrice_Complexa &ob)
{
    nr_linii=ob.nr_linii;
    nr_coloane=ob.nr_coloane;

    mat = new Numar_Complex*[nr_linii];
    for (int i = 0; i < nr_linii; i++)
        mat[i] = new Numar_Complex[nr_coloane];

    for(int i=0; i<nr_linii; i++)
        for(int j=0; j<nr_coloane; j++)
            mat[i][j]= ob.mat[i][j];
}

Matrice_Complexa::~Matrice_Complexa()
{
    for(int i=0; i<nr_linii; i++)
        delete mat[i];
    delete mat;

}



Matrice_Complexa operator+( const Matrice_Complexa &a,const Matrice_Complexa &b)
{
    if(a.nr_linii!=b.nr_linii || a.nr_coloane!=b.nr_coloane)
        cout<<"Nu se poate face adunarea.\n";
    else
    {
        Numar_Complex nr;
        nr.set_numar(0,0);
        Matrice_Complexa temp(a.nr_linii,a.nr_coloane,nr);

        for(int i=0; i<a.nr_linii; i++)
            for(int j=0; j<b.nr_coloane; j++)
                temp.mat[i][j]= a.mat[i][j]+b.mat[i][j];
        return temp;

    }



}

Matrice_Complexa operator*( const Matrice_Complexa &a, const Matrice_Complexa &b)
{
    if(a.nr_coloane!=b.nr_linii)
        cout<<"Matricele nu se pot inmulti.\n";
    else
    {
        Numar_Complex nr;
        nr.set_numar(0,0);
        Matrice_Complexa temp(a.nr_linii,b.nr_coloane,nr);


        for(int i=0; i<a.nr_linii; i++)
            for(int j=0; j<b.nr_coloane; j++)
                for(int k=0; k<a.nr_coloane; k++)
                    temp.mat[i][j] = temp.mat[i][j]+  a.mat[i][k]*b.mat[k][j];

        return temp;
    }

}

istream& operator >>(istream& input,Matrice_Complexa& ob)
{

    for(int i=0; i<ob.nr_linii; i++)
        for(int j=0; j<ob.nr_coloane; j++)
        input>>ob.mat[i][j];

}

ostream& operator << (ostream& output, Matrice_Complexa& ob)
{
    output<<"Matricea este:\n";
    for(int i=0; i<ob.nr_linii; i++)
    {
        for(int j=0; j<ob.nr_coloane; j++)
            output<<ob.mat[i][j];
        output<<endl;
    }
}
