#include "Item.h"
#include <string>
#include <cstring>
#include "Collectible.h"
using namespace std;


Item::Item():Collectible(),tip("arma")
{
    despre=new char[8];
    strcpy(despre, "default");
}

Item::~Item()
{
    delete[] despre;
}

ostream& Item::AfisareVirtuala(ostream& out) const
{
    Collectible::AfisareVirtuala(out);
    cout<<" de tip "<<tip<<", descriere: "<<despre;
    return out;
}

istream& Item::CitireVirtuala(istream& in)
{
    Collectible::CitireVirtuala(in);
    cout<<"tip: ";
    in>>tip;
    cout<<"descriere: ";
    delete[] this->despre;
    char aux[500];
    cin.get();
    cin.get(aux,500);
    this->despre=new char[strlen(aux)+1];
    strcpy(despre, aux);

    return in;
}

void Item::afisare()
{
    cout<<nume<<"("<<tip<<")";
}
