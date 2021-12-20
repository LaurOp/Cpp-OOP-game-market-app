#include "DLC.h"
#include<cstring>
#include<iostream>
using namespace std;
DLC::DLC() : Joc()
{
    jocRespectiv="default_nume";
    launchdate= new char[11];
    strcpy(launchdate,"01/01/1900");
    sizeGB=0.0;
}

DLC::DLC(const string numenou,const double pretnou):Joc(numenou,pretnou)
{

    jocRespectiv="default_nume";
    launchdate= new char[11];
    strcpy(launchdate,"01/01/1900");
    sizeGB=0.0;

}

DLC::DLC(const DLC& ob):Joc(ob)
{

    jocRespectiv=ob.jocRespectiv;
    if(this->launchdate!=nullptr)
        delete[] this->launchdate;
    launchdate=new char[strlen(ob.launchdate)+1];
    strcpy(launchdate,ob.launchdate);
    sizeGB=ob.sizeGB;


}

DLC::~DLC()
{
    delete[] this->launchdate;
}

ostream& DLC::AfisareVirtuala(ostream& out)const
{
    Joc::AfisareVirtuala(out);
    out<<"\nDLC asociat jocului "<<jocRespectiv<<"\tlansat la "<<launchdate<<"\t si avand "<<sizeGB<<"GB";
    return out;
}

istream& DLC::CitireVirtuala(istream& in)
{
    Joc::CitireVirtuala(in);
    cout<<"Carui joc i se asociaza? ";
    in>>jocRespectiv;
    char aux[50];
    cout<<"La ce data s-a lansat? ";
    in>>aux;
    if(this->launchdate!=nullptr)
        delete[] launchdate;
    launchdate=new char[strlen(aux)+1];
    strcpy(launchdate,aux);
    cout<<"Cati GB are? ";
    in>>sizeGB;
    return in;
}

DLC &DLC::operator=(const DLC& ob)
{

    if(this!=&ob)
    {
        Joc::operator=(ob);
        this->jocRespectiv=ob.jocRespectiv;
        if(this->launchdate!=nullptr)
            delete[] launchdate;
        launchdate=new char[strlen(ob.launchdate)+1];
        strcpy(launchdate,ob.launchdate);
        sizeGB=ob.sizeGB;

    }
    return *this;
}


int DLC::afisare_pagina()
{
    system("cls");
    cout<<"\t"<<this->getNume()<<"\tPret: "<<this->getPret()<<endl;
    cout<<"cu indexul "<<this->getIdJoc()<<endl<<endl;
    cout<<"asociat jocului: "<<jocRespectiv<<"\t lansat la data de "<<launchdate;
    cout<<endl<<endl<<"Size: "<<sizeGB<<"GB"<<endl<<endl;
    cout<<"Achizitii: "<<this->getNrAchizitii()<<endl;
    cout<<"DLC-ul se incadreaza in categoriile: ";
    for(int i=0; i<this->getNrDeGenres(); i++)
        cout<<this->getGenre(i)<<", ";
    cout<<endl;
    for(int i=0; i<70; i++)
        cout<<'~';
    cout<<endl<<"111)CUMPARA DLC"<<endl<<"INAPOI LA: 101)MARKET\t102)COLECTIE\t\t0)EXIT"<<endl<<"Decizie: ";

    int x;
    cin>>x;
    return x;
}

int DLC::zile_trecute()
{
    int nrzile=0;

    int zicurenta,lunacurenta,ancurent;     //vom considera ca o luna are 30 de zile
    cout<<"zi curenta: ";
    cin>>zicurenta;
    cout<<"luna curenta: ";
    cin>>lunacurenta;
    cout<<"an curent: ";
    cin>>ancurent;

    int zijoc,lunajoc,anjoc;

    char* paux;
    paux=strtok(launchdate," ./\\-");
    zijoc=atoi(paux);
    paux=strtok(NULL," ./\\-");
    lunajoc=atoi(paux);
    paux=strtok(NULL," ./\\-");
    anjoc=atoi(paux);

    nrzile+=((ancurent-anjoc)*30*12);
    nrzile+=((lunacurenta-lunajoc)*30);
    nrzile+=(zicurenta-zijoc);

    return nrzile;
}
