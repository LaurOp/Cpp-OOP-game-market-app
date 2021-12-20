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

//constructori si destructor
Market::Market():admin(false),jocuriPerPagina(10),nrPagini(1),sortKey('a')
{

}

Market::Market(const bool admin):jocuriPerPagina(10),nrPagini(1),sortKey('a')
{
    this->admin=admin;
}

Market::Market(const bool admin,const char sortKey):jocuriPerPagina(10),nrPagini(1)
{
    this->admin=admin;
    this->sortKey=sortKey;
}

Market::Market(const Market& ob)
{
    this->admin=ob.admin;

    this->jocuri.clear();
    for(unsigned int i=0; i<ob.jocuri.size(); i++)
        this->jocuri.push_back(ob.jocuri[i]);

    this->jocuriPerPagina=ob.jocuriPerPagina;
    this->nrPagini=ob.nrPagini;


    this->sortKey=ob.sortKey;

}

Market::~Market()
{
    //jocuri.~vector();    eroare din ceva motiv
}

//setteri si getteri
void Market::setAdmin(bool valoare)
{
    this->admin=valoare;
}
void Market::setJoc(int i,const Joc& ob)
{
    this->jocuri[i]=ob;
}
void Market::setJocuriPerPagina(int valoare)
{
    this->jocuriPerPagina=valoare;
}
void Market::setSortKey(char cheie)
{
    this->sortKey=cheie;
}

bool Market::getAdmin()
{
    return this->admin;
}
Joc Market::getJoc(int i)
{
    return this->jocuri[i];
}
Joc* Market::getJocS(int i)
{
    return &jocuri[i];
}
int Market::getJocuriPerPagina()
{
    return this->jocuriPerPagina;
}
int Market::getNrPagini()
{
    return this->nrPagini;
}
char Market::getSortKey()
{
    return this->sortKey;
}
int Market::getNrJocuri()
{
    return this->jocuri.size();
}

//operatori
ostream& operator<<(ostream& out,const Market& ob)
{
    out<<"Market de tipul ";
    if(ob.admin)out<<"admin";
    else out<<"user";
    out<<endl<<"format: "<<ob.jocuriPerPagina<<" per pagina, cu "<<ob.nrPagini<<" jocuri/pagina";
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

istream& operator>>(std::istream& in, Market& ob)
{
    cout<<"admin? (0/1) ";
    cin>>ob.admin;
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
    return in;
}

Market &Market::operator=(const Market& ob)
{
    if(this!=&ob)
    {
        this->admin=ob.admin;
        this->jocuri.clear();
        for(unsigned int i=0; i<ob.jocuri.size(); i++)
            this->jocuri.push_back(ob.jocuri[i]);
        this->jocuriPerPagina=ob.jocuriPerPagina;
        this->nrPagini=ob.nrPagini;
        this->sortKey=ob.sortKey;

    }

    return *this;
}

Market Market::operator++()
{
    this->admin=true;
    return *this;
}

Market Market::operator++(int)
{
    Market aux=*this;
    this->admin=true;
    return aux;
}

Market Market::operator--()
{
    this->admin=true;
    return *this;
}

Market Market::operator--(int)
{
    Market aux=*this;
    this->admin=false;
    return aux;
}

Market Market::operator+(const Joc& ob)
{
    if(this->admin==false)
    {
        cout<<"sunteti in mod user!nu puteti adauga jocuri in market"<<endl;
        return *this;
    }

    this->jocuri.push_back(ob);
    return *this;
}

Market Market::operator-(const Joc& ob)
{
    if(this->admin==false)
    {
        cout<<"sunteti in mod user!nu puteti sterge jocuri din market"<<endl;
        return *this;
    }

    int poz=-1;
    for(unsigned int i=0; i<this->jocuri.size(); i++)
        if(this->jocuri[i]==ob)
        {
            poz=i;
            break;
        }

    if (poz!=-1)
        this->jocuri.erase(this->jocuri.begin()+poz);   //https://stackoverflow.com/questions/875103/how-do-i-erase-an-element-from-stdvector-by-index

    return *this;
}

bool Market::operator==(const Market& ob)
{
    if (this->admin!=ob.admin)
        return false;
    if (this->jocuriPerPagina!=ob.jocuriPerPagina)
        return false;
    if (this->nrPagini!=ob.nrPagini)
        return false;
    if(this->jocuri.size()!=ob.jocuri.size())
        return false;
    for(unsigned int i=0; i<ob.jocuri.size(); i++)
        if(not(this->jocuri[i]==ob.jocuri[i]))
            return false;
    return true;

}

bool Market::operator<(bool valoare)
{
    if (this->admin)
        return false;
    if (this->admin==0)
        if(valoare==0)
            return false;
    return true;
}

bool Market::operator>(bool valoare)
{
    if (this->admin)
        if(valoare)
            return false;
    if (this->admin==0)
        return false;
    return true;
}

Joc Market::operator[](int i)
{
    if (i>int(this->jocuri.size()))
        i=i%this->jocuri.size();
    return this->jocuri[i];
}

Market::operator char()
{
    return this->sortKey;
}

int Market::afisare_pagina(int i)
{
    i--;
    system("cls");
    cout<<"Market (";
    if(admin)cout<<"admin)"<<endl<<endl;
    else cout<<"user)"<<endl<<endl;
    cout<<"jocuri:\n";
    for(int j=i*this->jocuriPerPagina; j<(i+1)*this->jocuriPerPagina and j<int(this->jocuri.size()); j++)
        cout<<j+1<<")"<<jocuri[j].getNume()<<"\t\t"<<double(jocuri[j])<<endl;

    this->nrPagini=this->jocuri.size()/this->jocuriPerPagina;
    if(this->jocuri.size()%10!=0 or this->jocuri.size()<10)
        nrPagini++;
    cout<<endl<<"\t\t\t\tpagina "<<i+1<<" din "<<nrPagini<<endl;

    for(int j=0; j<120; j++)cout<<'~';
    cout<<endl;
    cout<<"100:MENIU\t106:SORTEAZA\t107:FILTER\t108:CAUTA\t109:JOC RANDOM\t116)Export in fisier\n";
    if(admin)
        cout<<"112:ADAUGA JOC\t113:ADAUGA DLC\t117)Import din fisier\t";
    if((i+1)!=nrPagini)
        cout<<"110:PAGINA URMATOARE"<<endl<<"Decizie: ";
    else cout<<endl<<"Decizie: ";
    int x;
    cin>>x;
    return x;
}

bool fctauxA(Joc j1, Joc j2)
{
    string s1,s2;
    s1=j1.getNume();
    s2=j2.getNume();
    if(s1<s2)
        return true;
    else return false;
}

bool fctauxG(Joc j1, Joc j2)
{
    string s1,s2;
    s1=j1.getGenre(0);
    s2=j2.getGenre(0);
    if(s1<=s2)
        return true;
    else return false;
}

bool fctauxI(Joc j1, Joc j2)
{
    int a,b;
    a=j1.getIdJoc();
    b=j2.getIdJoc();
    if(a<b)
        return true;
    else return false;
}

bool fctauxN(Joc j1, Joc j2)
{
    int a,b;
    a=j1.getNrAchizitii();
    b=j2.getNrAchizitii();
    if(a>=b)
        return true;
    else return false;
}

bool fctauxP1(Joc j1, Joc j2)
{
    double a,b;
    a=j1.getPret();
    b=j2.getPret();
    if(a>=b)
        return true;
    else return false;
}

bool fctauxP2(Joc j1, Joc j2)
{
    double a,b;
    a=j1.getPret();
    b=j2.getPret();
    if(a<=b)
        return true;
    else return false;
}

void Market::sorteaza(char cheie)
{
    if(not(strchr("aginpP",cheie)))
        cout<<"cheie incorecta";
    else
    {
        switch (cheie)
        {
        case 'a':
        {
            std::sort(this->jocuri.begin(),this->jocuri.end(),fctauxA);
            break;
        }
        case 'g':
        {
            std::sort(this->jocuri.begin(),this->jocuri.end(),fctauxG);
            break;
        }
        case 'i':
        {
            std::sort(this->jocuri.begin(),this->jocuri.end(),fctauxI);
            break;
        }
        case 'n':
        {
            std::sort(this->jocuri.begin(),this->jocuri.end(),fctauxN);
            break;
        }
        case 'p':
        {
            std::sort(this->jocuri.begin(),this->jocuri.end(),fctauxP1);
            break;
        }
        case 'P':
        {
            std::sort(this->jocuri.begin(),this->jocuri.end(),fctauxP2);
            break;
        }
        }
    }
}

Market Market::cauta(char* cuvant)
{
    cout<<cuvant;
    Market aux=*this;
    aux.jocuri.clear();

    for(unsigned int i=0; i<this->jocuri.size(); i++)
    {
        if(this->jocuri[i].getNume()==cuvant)
            aux.jocuri.push_back(this->jocuri[i]);
    }

    for(unsigned int i=0; i<this->jocuri.size(); i++)
    {
        if(this->jocuri[i].getNume().find(cuvant)!=string::npos)      //https://stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c
            aux.jocuri.push_back(this->jocuri[i]);
    }

    return aux;
}

int Market::joc_random()
{
    if(this->jocuri.size()==0)
    {
        cout<<"Nu sunt inca jocuri";
        return 0;
    }
    else
    {
        int i=rand()% this->jocuri.size();
        this->jocuri[i].afisare_pagina();
    }
    int x;
    cin>>x;
    return x;
}

Market Market::filtreaza(string gen)
{
    cin.get();
    Market aux=*this;
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
