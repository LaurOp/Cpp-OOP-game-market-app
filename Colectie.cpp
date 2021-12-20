#include "Colectie.h"
#include "Market.h"
#include "Joc.h"
#include "User.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
//constr si destr
Colectie::Colectie():jocuriPerPagina(10),sortKey('a')
{
    this->playtime=new float[this->jocuri.size()];
    for(unsigned int i=0; i<this->jocuri.size(); i++)
        this->playtime[i]=0;
}

Colectie::Colectie(const char sortKey):jocuriPerPagina(10)
{
    this->sortKey=sortKey;
    this->playtime=new float[this->jocuri.size()];
    for(unsigned int i=0; i<this->jocuri.size(); i++)
        this->playtime[i]=0;
}

Colectie::Colectie(const int jocuriPerPagina, const char sortKey)
{
    this->jocuriPerPagina=jocuriPerPagina;
    this->sortKey=sortKey;
    this->playtime=new float[this->jocuri.size()];
    for(unsigned int i=0; i<this->jocuri.size(); i++)
        this->playtime[i]=0;
}

Colectie::Colectie(const Colectie& ob)
{
    this->jocuriPerPagina=ob.jocuriPerPagina;
    this->sortKey=ob.sortKey;
    this->jocuri.clear();
    for(unsigned int i=0; i<ob.jocuri.size(); i++)
        this->jocuri.push_back(ob.jocuri[i]);
    this->playtime=new float[ob.jocuri.size()];
    for(unsigned int i=0; i<ob.jocuri.size(); i++)
        this->playtime[i]=ob.playtime[i];
}

Colectie::~Colectie()
{
    if(this->playtime!=nullptr)
        delete[] this->playtime;

    //  jocuri.~vector();   da eroare
}

//setteri si getteri
void Colectie::setJoc(int i,const Joc& ob)
{
    this->jocuri[i]=ob;
}
void Colectie::setJocuriPerPagina(int valoare)
{
    this->jocuriPerPagina=valoare;
}
void Colectie::setPlaytime(int i, float valoare)
{
    this->playtime[i]=valoare;
}
void Colectie::setSortKey(char cheie)
{
    this->sortKey=cheie;
}

Joc Colectie::getJoc(int i)
{
    return this->jocuri[i];
}
Joc* Colectie::getJocS(int i)
{
    return &jocuri[i];
}
float Colectie::getPlaytime(int i)
{
    return this->playtime[i];
}
int Colectie::getJocuriPerPagina()
{
    return this->jocuriPerPagina;
}
char Colectie::getSortKey()
{
    return this->sortKey;
}
int Colectie::getNrJocuri()
{
    return jocuri.size();
}
//operatori

ostream& operator<<(ostream& out,const Colectie& ob)
{
    out<<"Colectie";
    out<<endl<<"format: "<<ob.jocuriPerPagina<<" per pagina";
    out<<endl<<"sortare: ";
    if(ob.sortKey=='a')out<<"alfabetica"<<endl;
    if(ob.sortKey=='g')out<<"dupa gen"<<endl;
    if(ob.sortKey=='n')out<<"dupa nr de achizitii"<<endl;
    if(ob.sortKey=='i')out<<"dupa indice"<<endl;
    if(ob.sortKey=='p')out<<"descrescatoare dupa pret"<<endl;
    if(ob.sortKey=='P')out<<"crescatoare dupa pret"<<endl;
    out<<"jocuri:";
    for(unsigned int i=0; i<ob.jocuri.size(); i++)
        out<<i+1<<")"<<ob.jocuri[i].getNume()<<" ";

    return out;
}


istream& operator>>(std::istream& in, Colectie& ob)
{
    cout<<"Jocuri per pagina ";
    cin>>ob.jocuriPerPagina;
    cout<<"Sortare dupa (a,g,i,n,p,P) ";
    cin>>ob.sortKey;
    cout<<"cate jocuri introduceti? ";
    int x;
    cin>>x;
    for(int i=0; i<x; i++)
    {
        system("cls");
        Joc joc;
        cin>>joc;
        ob.jocuri.push_back(joc);
    }
    ob.playtime=new float[x];
    for(int i=0; i<x; i++)
        ob.playtime[i]=0.00;
    return in;
}

Colectie &Colectie::operator=(const Colectie& ob)
{
    if(this!=&ob)
    {
        this->jocuriPerPagina=ob.jocuriPerPagina;
        this->sortKey=ob.sortKey;
        this->jocuri.clear();
        if(this->playtime!=NULL)
            delete[] playtime;
        for(unsigned int i=0; i<ob.jocuri.size(); i++)
            this->jocuri.push_back(ob.jocuri[i]);
        for(unsigned int i=0; i<ob.jocuri.size(); i++)
            this->playtime[i]=ob.playtime[i];
    }

    return *this;
}

Colectie Colectie::operator++()
{
    for(unsigned int i=0; i<this->jocuri.size(); i++)
        this->playtime[i]+=0.1;
    return *this;
}

Colectie Colectie::operator++(int)
{
    Colectie aux=*this;
    for(unsigned int i=0; i<this->jocuri.size(); i++)
        this->playtime[i]+=0.1;
    return aux;
}

Colectie Colectie::operator--()
{
    for(unsigned int i=0; i<this->jocuri.size(); i++)
        this->playtime[i]-=0.1;
    return *this;
}

Colectie Colectie::operator--(int)
{
    Colectie aux=*this;
    for(unsigned int i=0; i<this->jocuri.size(); i++)
        this->playtime[i]+=0.1;
    return aux;
}

Colectie Colectie::operator*(const Joc& ob)
{
    this->jocuri.push_back(ob);
    if(this->playtime!=NULL)
    {
        delete[] this->playtime;

        float aux[this->jocuri.size()-1];
        for(unsigned int i=0; i<this->jocuri.size()-1; i++)
            aux[i]=this->playtime[i];
        this->playtime=new float[this->jocuri.size()];
        for(unsigned int i=0; i<this->jocuri.size()-1; i++)
            this->playtime[i]=aux[i];
        playtime[this->jocuri.size()-1]=0.00;
    }
    else
    {
        this->playtime=new float[1];
        this->playtime[0]=0.00;
    }

    return *this;
}

Colectie Colectie::operator/(const Joc& ob)
{
    int poz=-1;
    for(unsigned int i=0; i<this->jocuri.size(); i++)
        if(this->jocuri[i]==ob)
        {
            poz=i;
            break;
        }

    if (poz!=-1)
    {
        int j=0;
        this->jocuri.erase(this->jocuri.begin()+poz);
        float aux[this->jocuri.size()-1-poz];
        for(unsigned int i=0; i<this->jocuri.size(); i++)
            if(not(this->jocuri[i]==ob))
            {
                aux[j]=this->playtime[i];
                j++;
            }
        delete[] this->playtime;
        this->playtime=new float[this->jocuri.size()];
        for(unsigned int i=0; i<this->jocuri.size(); i++)
            this->playtime[i]=aux[i];
    }

    return *this;
}

bool Colectie::operator==(const Colectie& ob)
{
    //doar pe 2 colectii sortate cu aceasi cheie !
    if (this->sortKey!=ob.sortKey)
        return false;
    if (this->jocuri.size()!=ob.jocuri.size())
        return false;
    for(unsigned int i=0; i<this->jocuri.size(); i++)
        if(not(this->jocuri[i]==ob.jocuri[i]))
            return false;
    return true;
}

bool Colectie::operator<(float valoare)
{
    float sum=0;
    for(unsigned int i=0; i<this->jocuri.size(); i++)
        sum+=playtime[i];
    if (sum<valoare)
        return true;
    return false;
}

Joc Colectie::operator[](int i)
{
    i=i%this->jocuri.size();
    return this->jocuri[i];
}

Colectie::operator char()
{
    return this->sortKey;
}

//functionalitate

int Colectie::afisare_pagina(int i)
{
    i--;
    system("cls");
    cout<<"Colectie"<<endl<<endl;
    cout<<"jocuri:\n";
    for(int j=i*this->jocuriPerPagina; j<(i+1)*this->jocuriPerPagina and j<int(this->jocuri.size()); j++)
        cout<<j+1<<")"<<jocuri[j].getNume()<<endl;

    int nrPagini=this->jocuri.size()/this->jocuriPerPagina;
    if(this->jocuri.size()%10!=0 or this->jocuri.size()<10)
        nrPagini++;
    cout<<endl<<"\t\t\t\tpagina "<<i+1<<" din "<<nrPagini<<endl;

    for(int j=0; j<100; j++)cout<<'~';
    cout<<endl;
    cout<<"100:MENIU\t\t106:SORTEAZA\t\t107:FILTER\t\t109:JOC RANDOM\t116)Export in fisier\t";
    if((i+1)!=nrPagini)
        cout<<"110:PAGINA URMATOARE"<<endl<<"Decizie: ";
    else cout<<endl<<"Decizie: ";

    int x;
    cin>>x;
    return x;
}

bool fctauxA2(Joc j1, Joc j2)
{
    string s1,s2;
    s1=j1.getNume();
    s2=j2.getNume();
    if(s1<s2)
        return true;
    else return false;
}

bool fctauxG2(Joc j1, Joc j2)
{
    string s1,s2;
    s1=j1.getGenre(0);
    s2=j2.getGenre(0);
    if(s1<=s2)
        return true;
    else return false;
}

bool fctauxI2(Joc j1, Joc j2)
{
    int a,b;
    a=j1.getIdJoc();
    b=j2.getIdJoc();
    if(a<b)
        return true;
    else return false;
}

bool fctauxN2(Joc j1, Joc j2)
{
    int a,b;
    a=j1.getNrAchizitii();
    b=j2.getNrAchizitii();
    if(a>=b)
        return true;
    else return false;
}

bool fctauxP12(Joc j1, Joc j2)
{
    double a,b;
    a=j1.getPret();
    b=j2.getPret();
    if(a>=b)
        return true;
    else return false;
}

bool fctauxP22(Joc j1, Joc j2)
{
    double a,b;
    a=j1.getPret();
    b=j2.getPret();
    if(a<=b)
        return true;
    else return false;
}

Colectie Colectie::sorteaza(char cheie)
{
    if(not(strchr("aginpP",cheie)))
        cout<<"cheie incorecta";
    else
    {
        switch (cheie)
        {
        case 'a':
        {
            std::sort(this->jocuri.begin(),this->jocuri.end(),fctauxA2);
            break;
        }
        case 'g':
        {
            std::sort(this->jocuri.begin(),this->jocuri.end(),fctauxG2);
            break;
        }
        case 'i':
        {
            std::sort(this->jocuri.begin(),this->jocuri.end(),fctauxI2);
            break;
        }
        case 'n':
        {
            std::sort(this->jocuri.begin(),this->jocuri.end(),fctauxN2);
            break;
        }
        case 'p':
        {
            std::sort(this->jocuri.begin(),this->jocuri.end(),fctauxP12);
            break;
        }
        case 'P':
        {
            std::sort(this->jocuri.begin(),this->jocuri.end(),fctauxP22);
            break;
        }
        }
    }
    return *this;
}

Colectie Colectie::filtreaza(string gen)
{
    Colectie aux=*this;
    aux.jocuri.clear();

    for(unsigned int i=0; i<this->jocuri.size(); i++)
    {
        bool conditie=false;
        for(int j=0; j<this->jocuri[i].getNrDeGenres(); j++)
            if(this->jocuri[i].getGenre(j)==gen)
            {
                conditie=true;
            }

        if(conditie)
            aux.jocuri.push_back(this->jocuri[i]);
    }
    return aux;
}

int Colectie::joc_random()
{
    int x;
    if(this->jocuri.size()==0)
    {
        cout<<"Nu sunt inca jocuri";
        return 0;
    }
    else
    {
        int i=rand()% this->jocuri.size();
        x=this->jocuri[i].afisare_pagina();
    }
    return x;
}

