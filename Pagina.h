#ifndef PAGINA_H
#define PAGINA_H

//interfata care obliga clasele Market si Colectie sa
//aiba functie de afisare pagina si de generare joc random

class Pagina
{
    public:
        virtual int afisare_pagina(int i) = 0;
        virtual int joc_random() = 0;
        virtual ~Pagina() {}

};

#endif // PAGINA_H
