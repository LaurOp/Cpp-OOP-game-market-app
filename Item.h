#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "Collectible.h"
using namespace std;

class Item: public Collectible
{
    private:
        string tip; //arma, card, deco
        char* despre;

    public:
        Item();
        ~Item();
        ostream& AfisareVirtuala(ostream& out)const;
        istream& CitireVirtuala(istream& in);

        void afisare();

};

#endif
