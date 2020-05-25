#pupici de la 131.


#include <Numar_Complex.h>
#include <Matrice_Complexa.h>
#include <fstream>

ifstream fin ("matrice_Complexa.in");
///In fisierul de intrare numerele din matrice sunt de forma: parte reala parte imaginara
using namespace std;


int main()
{

    Numar_Complex ob;
    ob.set_numar(1,1);

    Matrice_Complexa A(4,2,ob),B(2,3),C(2,3); ///Se apeleaza cei doi constructori de initializare
    Matrice_Complexa Z=A; ///Constructorul de copiere

    cout<<B;  ///Matricea B primeste by default elemente de 0
    cout<<"\n";

    cout<<Z;  ///In Z este copiata matricea A, care a fost initializata cu elemente de 1+i
    cout<<"\n";
    fin>>B;
    fin>>C;

    Matrice_Complexa D=B+C;
    cout<<D;
    cout<<"\n";

    Matrice_Complexa E=A*C;
    cout<<E;
    cout<<"\n";

}
