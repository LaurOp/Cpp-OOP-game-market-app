#include "Skin.h"
#include <string>
#include <cstring>
#include "Collectible.h"
using namespace std;

Skin::Skin():Collectible(),tip("personaj"),pattern("safari"),conditie(1.00)
{
    despre=new char[8];
    strcpy(despre, "default");
}

Skin::~Skin()
{
    delete[] despre;
}

ostream& Skin::AfisareVirtuala(ostream& out) const
{
    Collectible::AfisareVirtuala(out);
    out<<" de tip "<<tip<<", pattern: "<<pattern<<", conditie: "<<conditie<<", descriere: "<<despre;
    return out;
}

istream& Skin::CitireVirtuala(istream& in)
{
    Collectible::CitireVirtuala(in);
    cout<<"tip: ";
    in>>tip;

    cout<<"pattern: ";
    in>>pattern;
    cout<<"conditie(0->1): ";
    in>>conditie;

    cout<<"descriere: ";
    delete[] this->despre;
    char aux[500];
    cin.get();
    cin.get(aux,500);
    this->despre=new char[strlen(aux)+1];
    strcpy(despre, aux);


    return in;
}

void Skin::afisare()
{
    cout<<nume<<"("<<tip<<","<<pattern<<")";
}
