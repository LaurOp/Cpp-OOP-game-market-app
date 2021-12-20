#ifndef SKIN_H
#define SKIN_H
#include <string>
#include "Collectible.h"
using namespace std;

class Skin:public Collectible
{
    private:
        string tip; //arma, personaj
        char* despre;
        string pattern;
        float conditie;
    public:
        Skin();
        ~Skin();

        ostream& AfisareVirtuala(ostream& out)const;
        istream& CitireVirtuala(istream& in);

        void afisare();
};

#endif // SKIN_H
