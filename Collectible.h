#ifndef COLLECTIBLE_H
#define COLLECTIBLE_H
#include <string>
#include <iostream>
using namespace std;

//CLASA ABSTRACTA din care voi deriva  item , skin

class Collectible
{
protected:

    int cod;
    string culoare;
    float pret;
    string nume;


public:
    static int contor;
    Collectible();
    Collectible(string numenou,float pretnou,string culoarenou);
    Collectible(const Collectible& ob);
    virtual ~Collectible();

    virtual ostream& AfisareVirtuala(ostream& out)const;
    virtual istream& CitireVirtuala(istream& in);

    friend istream& operator>>(istream& in, Collectible& pr);
    friend ostream& operator<<(ostream& out,const Collectible& pr);
    Collectible &operator=(const Collectible& ob);

    virtual void afisare()=0;


};

#endif // COLLECTIBLE_H
