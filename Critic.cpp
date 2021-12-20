#include "Critic.h"
#include <iostream>
#include <vector>
using namespace std;
Critic::Critic():User()
{
}

Critic::Critic(const Critic& ob):User(ob)
{
    reviewuri.clear();
    for(int i=0; i<ob.reviewuri.size(); i++)
        reviewuri.push_back(ob.reviewuri[i]);

}

Critic &Critic::operator=(const Critic& ob)
{

    if(this!=&ob)
    {
        User::operator=(ob);
        reviewuri.clear();
        for(int i=0; i<ob.reviewuri.size(); i++)
            reviewuri.push_back(ob.reviewuri[i]);
    }
    return *this;

}

Critic::~Critic()
{
    //reviewuri.~vector();
}

Critic Critic::operator+(const Review& rev)
{
    reviewuri.push_back(rev);
    return *this;
}

int Critic::afisare_pagina(int i)
{
    i--;
    system("cls");
    cout<<"Critic"<<endl<<endl;
    cout<<"reviewuri:\n";
    for(int j=0; j<this->reviewuri.size(); j++)
    {
        cout<<j+1<<")";
        reviewuri[j].afisare_pagina();
        cout<<endl<<endl;
    }


    for(int j=0; j<80; j++)cout<<'~';
    cout<<endl;
    cout<<"100:MENIU\t\t106:SORTEAZA\t\t107:FILTER\t";

    cout<<endl<<"Decizie: ";

    int x;
    cin>>x;
    return x;
}
