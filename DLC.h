#ifndef DLC_H
#define DLC_H
#include "Joc.h"
#include <string>

//DLC = Downloadable content;

class DLC:public Joc
{   private:
        string jocRespectiv;
        char* launchdate;   //data la care a fost lansat
        float sizeGB;       //marimea dlc-ului masurata in gigabytes

    public:
        DLC();
        DLC(const string numenou,const double pretnou);
        DLC(const DLC& ob);
        ~DLC();

        ostream& AfisareVirtuala(ostream& out)const;
        istream& CitireVirtuala(istream& in);

        DLC &operator=(const DLC& ob);

        int afisare_pagina();
        int zile_trecute();     //cate zile au trecut de la lansare

};

#endif // DLC_H
