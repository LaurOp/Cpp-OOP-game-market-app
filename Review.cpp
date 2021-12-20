#include "Review.h"
#include<iostream>
#include<cstring>
#include <stdlib.h>
using namespace std;
Review::Review():nrlikes(0),nrdislikes(0)
{
    continut=new char[8];
    strcpy(continut,"default");
}

Review::Review(char* text):nrlikes(0),nrdislikes(0)
{
    continut=new char[strlen(text)];
    strcpy(continut,text);
}

Review::Review(const Review& ob)
{
    if(this->continut!= NULL)
        delete[] continut;
    continut=new char[strlen(ob.continut)+1];
    strcpy(continut,ob.continut);

    nrlikes=ob.nrlikes;
    nrdislikes=ob.nrdislikes;
}

ostream& operator<<(ostream& out, const Review& ob)
{
    out<<ob.continut;
    return out;
}

Review &Review::operator=(const Review& ob)
{
    if(this!=&ob)
    {
        if(this->continut!=nullptr)
            delete[] continut;
        continut=new char[strlen(ob.continut)+1];
        strcpy(continut,ob.continut);

        nrlikes=ob.nrlikes;
        nrdislikes=ob.nrdislikes;
    }
    return *this;
}


Review::~Review()
{
    //if(this->continut != NULL)
    //  delete[] continut;
}

void Review::afisare_pagina()
{
    cout<<continut<<endl;
    cout<<"like-uri: "<<nrlikes<<"\t\tdislike-uri: "<<nrdislikes;
}
