#ifndef COLECTIE_H
#define COLECTIE_H
#include "Joc.h"
#include <vector>
#include <iostream>
#include "Pagina.h"
using namespace std;

class Colectie:public Pagina
{
    private:
        std::vector <Joc> jocuri;
        float* playtime;
        int jocuriPerPagina;
        char sortKey;

    public:
        //constr si destr
        Colectie();
        Colectie(const char sortKey);
        Colectie(const int jocuriPerPagina,const char sortKey);
        Colectie(const Colectie& ob);
        ~Colectie();

        //setteri si getteri
        void setJoc(int i,const Joc& ob);
        void setPlaytime(int i,float valoare);
        void setJocuriPerPagina(int valoare);
        void setSortKey(char cheie);

        Joc getJoc(int i);
        Joc* getJocS(int i);
        float getPlaytime(int i);
        int getJocuriPerPagina();
        char getSortKey();
        int getNrJocuri();
        //operatori
        friend std::ostream& operator<<(std::ostream& out,const Colectie& ob);
        friend std::istream& operator>>(std::istream& in, Colectie& ob);
        Colectie &operator=(const Colectie& ob);
        Colectie operator++();
        Colectie operator++(int);
        Colectie operator--();
        Colectie operator--(int);
        Colectie operator*(const Joc& ob); //adauga joc in colectie
        Colectie operator/(const Joc& ob); //vinde joc din colectie
        bool operator==(const Colectie& ob);
        bool operator<(float valoare);
        Joc operator[](int i);  //al i-ulea joc din colectie
        operator char();

        //functionalitate
        int afisare_pagina(int i);
        Colectie sorteaza(char cheie);
        Colectie filtreaza(string gen);
        int joc_random();


};

#endif // COLECTIE_H
