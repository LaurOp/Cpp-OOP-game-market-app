#ifndef USER_H
#define USER_H
#include<iostream>
#include "Colectie.h"
#include <set>
class User
{   private:
        const int indexUser;
        float wallet;
        bool admin;
        char* username;
        char* password;
        char gender;
        int age;
        int nr_of_games;
        Colectie colectie;
        std::set<string> prieteni;

    public:
        static int contorID;

        //constructori si destructor
        User();
        User(const char* usern, const char* pass, const int age, const char gen);
        User(const char* usern, const char* pass, const bool admin);
        User(const User& ob);
        ~User();

        //getteri si setteri
        int getIndex();
        float getWallet();
        bool getAdmin();
        char* getUsername();
        char* getPassword();
        char getGender();
        int getAge();
        int getNrGames();
        Colectie getColectie();
        Colectie* getColectieS();
        int getNrPrieteni();

        void setWallet(float val);
        void setAdmin(bool valoare);
        void setUsername(char* usernameNou);
        void setPassword(char* passwordNou);
        void setGender(char litera);
        void setAge(int ageNou);
        void setNrGames(int nr);
        void setColectie(const Colectie& ob);


        //overload de operatori
        friend std::ostream& operator<<(std::ostream& out, const User& ob);
        friend std::istream& operator>>(std::istream& in, User& ob);
        User &operator=(const User &ob);
        User operator++();
        User operator++(int);
        User operator--();
        User operator--(int);
        User operator+(float x);
        User operator-(float x);
        bool operator==(const User& ob);
        bool operator<=(float x);
        bool operator<(User& ob);
        char operator[](int i);
        operator float();


        void adaugaPrieten(string numePrieten);
        //functionalitate
        int afisare_profil();
        int add_funds();   //afiseaza pagina de adaugare fonduri

};

#endif // USER_H
