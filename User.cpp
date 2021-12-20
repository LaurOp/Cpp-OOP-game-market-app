#include "User.h"
#include<cstring>
#include<iostream>
#include <cstdlib>
using namespace std;
//constructor fara parametrii
User::User():indexUser(contorID++),wallet(0.0),admin(false),gender('M'),age(0),nr_of_games(0)
{
    this->username=new char[1];
    this->password=new char[1];
    strcpy(this->username,"");
    strcpy(this->password,"");
}

//constructori cu parametrii
User::User(const char* usern, const char* pass, const int age, const char gen):indexUser(contorID++),wallet(0.0),admin(false),nr_of_games(0)
{
    this->username=new char[strlen(usern)+1];
    strcpy(this->username,usern);

    this->password=new char[strlen(pass)+1];
    strcpy(this->password,pass);

    this->age=age;
    this->gender=gen;
}

User::User(const char* usern, const char* pass, const bool admin):indexUser(contorID++),wallet(0.0),gender('-'),age(0),nr_of_games(0)
{
    this->username=new char[strlen(usern)+1];
    strcpy(this->username,usern);

    this->password=new char[strlen(pass)+1];
    strcpy(this->password,pass);

    this->admin=admin;
}

//copy constructor
User::User(const User& ob):indexUser(contorID++)
{
    this->username=new char[strlen(ob.username)+1];
    strcpy(this->username,ob.username);

    this->password=new char[strlen(ob.password)+1];
    strcpy(this->password,ob.password);

    this->admin=ob.admin;
    this->age=ob.age;
    this->gender=ob.gender;
    this->wallet=ob.wallet;
    this->nr_of_games=ob.nr_of_games;

    this->prieteni.clear();
    for (std::set<string>::iterator it=ob.prieteni.begin(); it!=ob.prieteni.end(); ++it)
        this->prieteni.insert(*it);
}

//destructor
User::~User()
{
    if (this->username!=NULL)
        delete[] this->username;
    if (this->password!=NULL)
        delete[] this->password;
}


//getteri
bool User::getAdmin()
{
    return this->admin;
}
int User::getIndex()
{
    return this->indexUser;
}
char* User::getUsername()
{
    return this->username;
}
char* User::getPassword()
{
    return this->password;
}
int User::getAge()
{
    return this->age;
}
char User::getGender()
{
    return this->gender;
}
float User::getWallet()
{
    return this->wallet;
}
int User::getNrGames()
{
    return this->nr_of_games;
}
Colectie User::getColectie()
{
    return this->colectie;
}
Colectie* User::getColectieS()
{
    return &colectie;
}
int User::getNrPrieteni()
{
    return this->prieteni.size();
}

//setteri
void User::setAdmin(bool valoare)
{
    this->admin=valoare;
}
void User::setAge(int ageNou)
{
    this->age=ageNou;
}
void User::setGender(char litera)
{
    this->gender=litera;
}

void User::setPassword(char* passwordNou)
{
    if (this->password!=nullptr)
        delete[] this->password;
    this->password=new char[strlen(passwordNou)+1];
    strcpy(this->password,passwordNou);
}

void User::setUsername(char* usernameNou)
{
    if(this->username!=nullptr)
        delete[] this->username;
    this->username=new char[strlen(usernameNou)+1];
    strcpy(this->username,usernameNou);
}

void User::setWallet(float val)
{
    this->wallet=val;
}

void User::setNrGames(int nr)
{
    this->nr_of_games=nr;
}

void User::setColectie(const Colectie& ob)
{
    this->colectie=ob;
}

//operatori
ostream& operator<<(ostream& out, const User& ob)
{
    out<<endl<<"sunteti logat pe contul "<<ob.username<<", avand calitatea de ";
    if (ob.admin)
        out<<"admin";
    else
        out<<"user";
    out<<endl;

    return out;
}

istream& operator>>(istream& in, User& ob)
{
    //se va folosi la crearea unui nou cont, nu la log-in

    cout<<"username: ";
    char aux[50];
    in>>aux;

    if (ob.username!=nullptr)
        delete[] ob.username;
    ob.username=new char[strlen(aux)+1];
    strcpy(ob.username,aux);

    cout<<"parola: ";
    strcpy(aux,"");
    in>>aux;

    if(ob.password!=nullptr)
        delete[] ob.password;
    ob.password=new char[strlen(aux)+1];
    strcpy(ob.password,aux);

    cout<<"gen(M/F): ";
    char auxx;
    cin>>auxx;
    ob.setGender(auxx);

    cout<<"varsta: ";
    int varsta;
    cin>>varsta;
    ob.setAge(varsta);

    return in;
}

User &User::operator=(const User &ob)
{
    if(this!=&ob)
    {
        if (this->username!=NULL)
            delete[] this->username;
        this->username=new char[strlen(ob.username)+1];
        strcpy(this->username,ob.username);

        if (this->password!=NULL)
            delete[] this->password;
        this->password=new char[strlen(ob.password)+1];
        strcpy(this->password,ob.password);

        this->admin=ob.admin;
        this->age=ob.age;
        this->gender=ob.gender;
        this->wallet=ob.wallet;
        this->nr_of_games=ob.nr_of_games;
    }

    return *this;
}

User User::operator++()
{
    this->nr_of_games++;
    return *this;
}

User User::operator++(int)  //inspirat din laborator
{
    User aux(*this);
    this->nr_of_games++;

    return aux;
}

User User::operator--()
{
    if(this->nr_of_games==0)
        cout<<"Nu exista inca jocuri pe cont";
    else this->nr_of_games--;
    return *this;
}

User User::operator--(int)
{
    User aux(*this);
    if(this->nr_of_games==0)
        cout<<"Nu exista inca jocuri pe cont";
    else this->nr_of_games--;
    return aux;
}

User User::operator+(float x)
{
    this->wallet+=x;
    return *this;
}

User User::operator-(float x)
{
    this->wallet-=x;
    return *this;
}

bool User::operator==(const User& ob)
{
    //verifica doar user si parola
    if (strcmp(username,ob.username)!=0)
        return false;
    if (strcmp(password,ob.password)!=0)
        return false;

    return true;
}

bool User::operator<=(float x)
{
    if (this->wallet<=x)
        return true;
    return false;
}

bool User::operator<(User& ob)
{
    if(*username<=ob.getUsername()[0])
        return true;
    if(*username==ob.getUsername()[0])
        if(*(username+1)<=ob.getUsername()[1])
            return true;
    return false;
}

char User::operator[](int i)    //inspirat de pe https://www.tutorialspoint.com/cplusplus/subscripting_operator_overloading.htm
{
    if ((unsigned int)(i)>=strlen(username))
    {
        cout<<"out of bounds";
        return username[0];
    }
    else
        return username[i];
}

User::operator float()
{
    return this->wallet;
}

int User::afisare_profil()
{
    system("cls");
    cout<<"Profilul lui "<<this->username<<" (";
    if (admin)
        cout<<"admin)";
    else
        cout<<"user)";
    cout<<endl;
    cout<<"\tcu indexul "<<this->indexUser<<endl<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"Gender: "<<gender<<endl;
    cout<<"Numar de jocuri: "<<nr_of_games<<"\t\tFonduri: "<<wallet<<endl;
    cout<<"Prieteni: ";
    for (std::set<string>::iterator it=prieteni.begin(); it!=prieteni.end(); ++it)
        cout << ' ' << (*it);
    cout<<endl;
    for(int i=0; i<120; i++)cout<<'~';
    cout<<endl<<"100)MENIU PRINCIPAL\t\t104)ADAUGA FONDURI\t\t116)Export in fisier\t\t120:Adauga prieten\t\t0)EXIT"<<endl<<"Decizie: ";
    int x;
    cin>>x;
    return x;
}

int User::add_funds()
{
    system("cls");
    cout<<"Adauga fonduri pe contul "<<this->username<<endl<<endl;
    cout<<"1)+1.00\t\t4)+10.00\n2)+2.50\t\t5)+25.00\n3)+5.00\t\t6)+50.00"<<endl;
    cout<<endl<<"Cont curent: "<<this->wallet<<endl<<endl;

    for(int i=0; i<66; i++)cout<<'~';
    cout<<endl<<"0:EXIT\t100:MENIU\t101:MARKET\t\tDecizie: ";
    int x;
    cin>>x;
    return x;
}

void User::adaugaPrieten(string numePrieten)
{
    this->prieteni.insert(numePrieten);
}
