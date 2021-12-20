#ifndef MARKET_H
#define MARKET_H
#include "Joc.h"
#include <vector>
#include <cstring>
#include "Pagina.h"
using namespace std;

class Market:public Pagina
{
    private:
        bool admin; //vom prelucra diferit Marketul in functie de
                    //calitatea de admin/user pe care o are in momentul respectiv persoana
        std::vector <Joc> jocuri;
        int jocuriPerPagina;
        int nrPagini;
        char sortKey; //i=index a=alfabetic n=nr achizitii p=descrescator pret g=gen P=crescator pret

    public:
        Market();
        Market(const bool admin);
        Market(const bool admin,const char sortKey);
        Market(const Market& ob);
        ~Market();

        bool getAdmin();
        Joc getJoc(int i);  //al catelea joc din vector
        Joc* getJocS(int i);
        int getJocuriPerPagina();
        int getNrPagini();
        char getSortKey();
        int getNrJocuri();

        void setAdmin(bool valoare);
        void setJoc(int i,const Joc& ob);
        void setJocuriPerPagina(int valoare);
        void setSortKey(char cheie);

        friend std::ostream& operator<<(std::ostream& out, const Market& ob);
        friend std::istream& operator>>(std::istream& in, Market& ob);
        Market &operator=(const Market& ob);
        Market operator++();
        Market operator++(int);   //trece in mod admin
        Market operator--();
        Market operator--(int);     //trece in mod user
        Market operator+(const Joc& ob);
        Market operator-(const Joc& ob);
        bool operator==(const Market& ob);
        bool operator<(bool valoare); //compara admin cu valoare
        bool operator>(bool valoare);
        Joc operator[](int i);  //al i-ulea joc din market
        operator char();    //sortKey-ul

        int afisare_pagina(int i); // Pagina numarul i din market
        void sorteaza(char cheie);
        Market cauta(char* cuvant);
        int joc_random();
        Market filtreaza(string gen);

};

#endif // MARKET_H
