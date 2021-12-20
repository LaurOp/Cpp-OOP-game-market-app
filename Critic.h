#ifndef CRITIC_H
#define CRITIC_H
#include "User.h"
#include<string>
#include "Review.h"
#include <vector>
class Critic:public User
{   private:
        std::vector <Review> reviewuri;
    public:
        Critic();
        Critic(const Critic& ob);
        Critic &operator=(const Critic& ob);
        ~Critic();

        Critic operator+(const Review& rev);

        int afisare_pagina(int i);
};

#endif // CRITIC_H
