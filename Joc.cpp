#include "Joc.h"
#include<cstring>
#include<iostream>
#include <cstdlib>
#include <stdlib.h>
#include "Review.h"
#include <vector>
#include <list>
#include <map>
#include <string>
using namespace std;

//constructori
Joc::Joc():idJoc(contor++),nume(""),pret(0.00),nr_de_achizitii(0),nr_de_genres(1)
{
    this->genre=new string;
    genre[0]="casual";
    this->descriere=new char[8];
    strcpy(this->descriere,"default");
}

Joc::Joc(const string nume,const double pret):idJoc(contor++),nr_de_achizitii(0),nr_de_genres(1)
{
    this->nume=nume;
    this->pret=pret;
    this->genre=new string;
    *genre="casual";
    this->descriere=new char[8];
    strcpy(this->descriere,"default");
}

Joc::Joc(const string nume,const double pret,char* descrie):idJoc(contor++),nr_de_achizitii(0),nr_de_genres(1)
{
    this->nume=nume;
    this->pret=pret;
    this->descriere=new char[strlen(descrie)+1];
    strcpy(this->descriere,descrie);
    this->genre=new string;
    *genre="casual";
    this->descriere=new char[strlen(descrie)+1];
    strcpy(this->descriere,descrie);
}

Joc::Joc(const Joc& ob):idJoc(contor++)
{
    this->genre=new string[ob.nr_de_genres];
    for(int i=0; i<ob.nr_de_genres; i++)
        genre[i]=ob.genre[i];


    descriere=new char[strlen(ob.descriere)+1];
    strcpy(this->descriere,ob.descriere);

    this->nume=ob.nume;
    this->pret=ob.pret;
    this->nr_de_genres=ob.nr_de_genres;
    this->nr_de_achizitii=ob.nr_de_achizitii;

    this->note.clear();
    this->items.clear();
    this->reviews.clear();

    for(Review elem : ob.reviews)
        reviews.push_back(elem);

    for(Collectible* elem : ob.items)
        items.push_back(elem);

    for(pair<char*,int> elem : ob.note)
        note.insert(elem);
}

//destructor
Joc::~Joc()
{
    if(this->descriere!=nullptr)
        delete[] descriere;
    if(nr_de_genres==1)
        delete genre;
    else if(this->genre!=nullptr)
        delete[] genre;
}

//getteri si setteri
char* Joc::getDescriere()
{
    return descriere;
}
string Joc::getGenre(int poz)
{
    return genre[poz];
}
int Joc::getIdJoc() const
{
    return idJoc;
}
int Joc::getNrAchizitii()
{
    return nr_de_achizitii;
}
int Joc::getNrDeGenres()
{
    return nr_de_genres;
}
string Joc::getNume() const
{
    return nume;
}
double Joc::getPret()
{
    return pret;
}

void Joc::setDescriere(char* descriereNoua)
{
    if(this->descriere!=nullptr)
        delete[] descriere;
    descriere=new char[strlen(descriereNoua)+1];
    strcpy(this->descriere,descriereNoua);
}
void Joc::setGenre(int poz,string genreNou)
{
    this->genre[poz]=genreNou;
}
void Joc::setNrAchizitii(int nrNou)
{
    this->nr_de_achizitii=nrNou;
}
void Joc::setNume(string numeNou)
{
    this->nume=numeNou;
}
void Joc::setPret(double pretNou)
{
    this->pret=pretNou;
}

//operatori

ostream& Joc::AfisareVirtuala(ostream &out) const
{

    out<<"Jocul "<<nume<<" cu id "<<idJoc<<" si pretul "<<pret<<endl;
    out<<"nr achizitii:"<<nr_de_achizitii<<"\tnr genuri:"<<nr_de_genres<<endl;
    out<<"Descriere: "<<descriere<<endl<<"genuri: ";
    for(int i=0; i<nr_de_genres; i++)
        out<<genre[i]<<" ";
    out<<endl<<endl;
    out<<"Reviews:\n";
    for(int i=0; i<reviews.size(); i++)
        out<<i+1<<")"<<reviews[i]<<endl;
    out<<endl<<"Note: \n";
    for(std::map<char*,int>::const_iterator it=note.begin(); it!=note.end(); it++)
        out<<it->first<<" : "<<it->second<<endl;
    out<<endl;
    return out;

}

ostream& operator<<(ostream& out,const Joc& ob)
{
    return ob.AfisareVirtuala(out);
}

istream& Joc::CitireVirtuala(istream& in)
{

    cout<<"Nume(un cuvant): ";
    in>>nume;

    cout<<"Pret: ";
    in>>pret;

    if(nr_de_genres == 1)
        delete genre;
    else
        delete[] genre;

    cout<<"Numar genuri: ";
    in>>nr_de_genres;

    genre=new string[nr_de_genres];

    cout<<"Genuri(Diferite, cu Enter dupa fiecare): ";
    for(int i=0; i<nr_de_genres; i++)
        in>>genre[i];

    //Nu pot implementa citirea descrierii (char*) pt ca in.get() imi citeste doar pana la spatii, nu pana la null

    return in;

}

istream& operator>>(std::istream& in, Joc& ob)  //NU CITESTE DESCRIEREA
{
    return ob.CitireVirtuala(in);
}

Joc &Joc::operator=(const Joc &ob)
{
    if(this!=&ob)
    {
        this->nume=ob.nume;
        this->pret=ob.pret;
        this->nr_de_achizitii=ob.nr_de_achizitii;
        this->nr_de_genres=ob.nr_de_genres;

        if (this->descriere!=nullptr)
            delete[] this->descriere;
        this->descriere=new char[strlen(ob.descriere)+1];
        strcpy(this->descriere,ob.descriere);

        if(this->genre!=nullptr)
            delete[] this->genre;
        this->genre=new string[ob.nr_de_genres];
        for(int i=0; i<ob.nr_de_genres; i++)
            this->genre[i]=ob.genre[i];
    }
    return *this;
}

Joc Joc::operator++()
{
    this->nr_de_achizitii++;
    return *this;
}

Joc Joc::operator++(int)
{
    Joc aux(*this);
    this->nr_de_achizitii++;
    return aux;
}

Joc Joc::operator--()
{
    string* aux;
    aux=new string[this->nr_de_genres-1];
    for(int i=1; i<this->nr_de_genres; i++)
        aux[i-1]=genre[i];
    delete[] this->genre;
    this->nr_de_genres--;
    this->genre=new string[this->nr_de_genres];
    for(int i=0; i<this->nr_de_genres; i++)
        this->genre[i]=aux[i];

    return *this;
}

Joc Joc::operator--(int)
{
    Joc aux(*this);

    string* auxx;
    auxx=new string[this->nr_de_genres-1];
    for(int i=0; i<this->nr_de_genres-1; i++)
        auxx[i]=genre[i];
    delete[] this->genre;
    this->nr_de_genres--;
    this->genre=new string[this->nr_de_genres];
    for(int i=0; i<this->nr_de_genres; i++)
        this->genre[i]=auxx[i];

    return aux;
}

Joc Joc::operator+(string gen)
{
    string* aux;
    aux=new string[this->nr_de_genres];
    for(int i=0; i<this->nr_de_genres; i++)
        aux[i]=genre[i];
    delete[] this->genre;
    this->nr_de_genres++;
    this->genre=new string[this->nr_de_genres];
    for(int i=0; i<this->nr_de_genres-1; i++)
        this->genre[i]=aux[i];
    this->genre[this->nr_de_genres-1]=gen;

    return *this;
}



Joc Joc::operator-(string gen)  //Genre-urile sunt UNICE, nu trb verificat daca apare de 2 ori 'gen'
{
    bool conditie=0;
    for(int i=0; i<this->nr_de_genres; i++)
        if(this->genre[i]==gen)
            conditie=1;
    if(conditie==0)
        return *this;
    else
    {
        string* aux;
        aux=new string[this->nr_de_genres-1];
        int j=0;
        for(int i=0; i<this->nr_de_genres; i++)
            if(this->genre[i]!=gen)
            {
                aux[j]=genre[i];
                j++;
            }
        this->nr_de_genres--;
        delete[] this->genre;
        this->genre=new string[this->nr_de_genres];
        for(int i=0; i<this->nr_de_genres; i++)
            this->genre[i]=aux[i];
        return *this;
    }
}

bool Joc::operator==(const Joc& ob)
{
    //verifica daca numele pretul si genurile(indiferent de ordine) sunt aceleasi
    if(this->nume!=ob.nume)
        return false;
    if(this->pret!=ob.pret)
        return false;
    if(this->nr_de_genres!=ob.nr_de_genres)
        return false;
    for(int i=0; i<this->nr_de_genres; i++)
    {
        bool conditie=0;
        for(int j=0; j<ob.nr_de_genres; j++)
            if(this->genre[i]==ob.genre[j])
            {
                conditie=1;
                break;
            }
        if(conditie==0)
            return false;
    }
    return true;
}

bool Joc::operator<=(float fonduri)
{
    if(this->pret<=fonduri)
        return true;
    return false;

}

string Joc::operator[](int i)
{
    if(i<0)
    {
        i*=-1;
        i%=nr_de_genres;
    }
    else
    {
        if(i>=nr_de_genres)
            i%=nr_de_genres;
    }
    return genre[i];
}

Joc::operator double()
{
    return this->pret;
}

int Joc::afisare_pagina()
{
    system("cls");
    cout<<"\t"<<this->nume<<"\tPret: "<<this->pret<<endl;
    cout<<"cu indexul "<<this->idJoc<<endl<<endl;
    cout<<this->descriere<<endl<<endl;
    cout<<"Achizitii: "<<this->nr_de_achizitii<<endl;
    cout<<"Se incadreaza in categoriile: ";
    for(int i=0; i<this->nr_de_genres; i++)
        cout<<this->genre[i]<<", ";
    cout<<endl;
    cout<<"\nAre "<<reviews.size()<<" reviewuri\n";
    cout<<"Reviews:\n";
    for(int i=0; i<reviews.size(); i++)
        cout<<i+1<<")"<<reviews[i]<<endl;
    cout<<endl<<endl<<"Note: \n";
    for(std::map<char*,int>::iterator it=note.begin(); it!=note.end(); it++)
        cout<<it->first<<" : "<<it->second<<endl;
    cout<<endl;
    for(int i=0; i<105; i++)
        cout<<'~';
    cout<<endl<<"111)CUMPARA"<<endl<<"INAPOI LA: 101)MARKET\t102)COLECTIE\t114)Review\t115)Da o nota\t116)Export in fisier\t0)EXIT";
    cout<<endl<<"\t118)Items";
    cout<<endl<<"Decizie: ";
    int x;
    cin>>x;
    return x;
}

void Joc::adaugaRev(Review& rev)
{
    this->reviews.push_back(rev);
}

void Joc::adaugaNota(char* nume, int nota)
{
    this->note[nume]=nota;
}

void Joc::adaugaItem(Item& ob)
{
    this->items.push_back(&ob);
}

void Joc::adaugaSkin(Skin& ob)
{
    this->items.push_back(&ob);
}

int Joc::getNrItems()
{
    return this->items.size();
}

Collectible* Joc::getItem(int i)
{
    std::list<Collectible*>::iterator ptr;
    int k;
    //https://stackoverflow.com/questions/5733842/how-to-get-a-certain-element-in-a-list-given-the-position
    for( k = 0, ptr = items.begin() ; k < i && ptr != items.end() ; k++, ptr++ );
    return *ptr;
}

void Joc::parcurgeItems()
{
    int i;
    std::list<Collectible*>::iterator it;
    for (it = items.begin(),i=1; it != items.end(); ++it,++i)
    {
        std::cout <<i<<")"<< **it<<endl;
    }
}
