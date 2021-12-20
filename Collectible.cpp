#include "Collectible.h"
#include<iostream>
using namespace std;
Collectible::Collectible():cod(contor++),culoare("alb"),pret(0.0),nume("def")
{
}

Collectible::Collectible(string numenou,float pretnou,string culoarenou):cod(contor++)
{
    nume=numenou;
    pret=pretnou;
    culoare=culoarenou;
}

Collectible::Collectible(const Collectible& ob):cod(contor++)
{
    this->culoare=ob.culoare;
    this->nume=ob.nume;
    this->pret=ob.pret;
}

Collectible &Collectible::operator=(const Collectible& ob)
{
    if(this!=&ob)
    {
        this->cod=ob.cod;
        this->culoare=ob.culoare;
        this->nume=ob.nume;
        this->pret=ob.pret;

    }
    return *this;
}


istream& Collectible::CitireVirtuala(istream& in)
{
    cout<<"nume: ";
    in>>nume;
    cout<<"pret: ";
    in>>pret;
    cout<<"culoare: ";
    in>>culoare;

    return in;
}

istream& operator>>(istream& in, Collectible& ob)
{
    return ob.CitireVirtuala(in);
}

ostream& Collectible::AfisareVirtuala(ostream& out) const
{
    out<<"Collectible-ul cu id-ul "<<cod<<endl;
    out<<"Nume: "<<nume<<"\tPret: "<<pret<<"\tCuloare: "<<culoare;
    return out;
}

ostream& operator<<(ostream& out,const Collectible& ob)
{
    return ob.AfisareVirtuala(out);
}

Collectible::~Collectible()
{
}
