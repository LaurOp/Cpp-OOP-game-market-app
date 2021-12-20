#ifndef REVIEW_H
#define REVIEW_H
using namespace std;
#include<iostream>

class Review
{   private:
        char* continut;
        int nrlikes;
        int nrdislikes;

    public:
        Review();
        Review(char* text);
        Review(const Review& ob);
        Review &operator=(const Review& ob);

        friend ostream& operator<<(ostream& out, const Review& ob);
        ~Review();

        void afisare_pagina();

};

#endif // REVIEW_H
