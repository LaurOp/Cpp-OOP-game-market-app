#ifndef JOC_JOC
#define JOC_JOC
#include<string>
#include "Collectible.h"
#include "Review.h"
#include "Item.h"
#include "Skin.h"
#include <list>
#include <vector>
#include <map>

using namespace std;
class Joc
{
private:
    const int idJoc;
    string nume;
    double pret;
    int nr_de_achizitii;
    string* genre;
    int nr_de_genres;
    char* descriere;
    std::list<Collectible*> items;
    std::vector<Review> reviews;
    std::map<char*,int> note;


public:
    static int contor;

    //constructori si destructor
    Joc();
    Joc(const string nume,const double pret);
    Joc(const string nume,const double pret,char* descrie);
    Joc(const Joc& ob);
    virtual ~Joc();

    //getteri si setteri
    string getNume() const;
    double getPret();
    string getGenre(int poz);//poz= al catelea genre il returneaza
    char* getDescriere();
    int getNrAchizitii();
    int getIdJoc() const;
    int getNrDeGenres();
    int getNrItems();
    Collectible* getItem(int i);

    void setNume(string numeNou);
    void setPret(double pretNou);
    void setGenre(int poz,string genreNou);//poz= al catelea genre il returneaza
    void setDescriere(char* descriereNoua);
    void setNrAchizitii(int nrNou);

    //operatori
    virtual ostream& AfisareVirtuala(ostream& out)const;     //virtualizarea operatorilor citire si afisare
    virtual istream& CitireVirtuala(istream& in);

    friend std::ostream& operator<<(std::ostream& out,const Joc& ob);
    friend std::istream& operator>>(std::istream& in, Joc& ob);
    Joc &operator=(const Joc& ob);
    Joc operator++();
    Joc operator++(int);
    Joc operator--();   //sterge primul genre
    Joc operator--(int);    //sterge ultimul genre
    Joc operator+(string gen);  //adauga gen la final de genres

    Joc operator-(string gen);  //sterge gen din genres
    bool operator==(const Joc& ob);
    bool operator<=(float fonduri);
    string operator[](int i);
    operator double();

    void adaugaRev(Review& rev);
    void adaugaNota(char* nume, int nota);
    void adaugaItem(Item& ob);
    void adaugaSkin(Skin& ob);
    void parcurgeItems();


    //functionalitate
    virtual int afisare_pagina();
};

#endif // JOC_JOC
