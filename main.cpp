#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <typeinfo>
#include "User.h"
#include "Joc.h"
#include "Market.h"
#include "Colectie.h"
#include "DLC.h"
#include "Pagina.h"
#include "Collectible.h"
#include "Review.h"
#include "Critic.h"
#include "Item.h"
#include "Skin.h"
using namespace std;

ifstream fin("input.in");
ofstream fout("output.out");

int welcome()
{
    system("cls");
    cout<<"Bun venit pe eMarket!\n\n";
    cout<<"1)Intrati in mod ADMIN\n2)Intrati in mod USER"<<endl;
    cout<<endl<<"0)EXIT\t\t\tDecizie: ";
    int x;
    cin>>x;
    return x;
}

void terminate_app()
{
    system("cls");
    cout<<"La revedere!";
    exit(0);

}

void verificare_iesire()
{
    cout<<"\nConfirmati iesirea din aplicatie? (1=DA, 0=NU)\nDecizie:";
    bool conditie;
    cin>>conditie;
    if(conditie)
        terminate_app();
    //else ne intoarcem la pagina precedenta
}

int main_menu(User ob)
{
    system("cls");
    cout<<ob<<endl<<endl;
    cout<<"Meniu principal"<<endl<<endl;
    cout<<"101)MARKET\n102)COLECTIE (Useri)\n103)Profil"<<endl;
    cout<<"\t\t\t\tFonduri curente: "<<ob.getWallet()<<endl;
    cout<<"0)EXIT\t\t104)ADAUGA FONDURI\t\t105)LOG-OUT"<<endl<<endl<<"Decizie: ";
    int x;
    cin>>x;
    return x;
}

int pagina_items(Joc ob)
{
    system("cls");
    ob.parcurgeItems();

    cout<<endl<<endl;
    cout<<"119:ADAUGA ITEM(admin!)\t\t0:EXIT\nDecizie:";
    int x;
    cin>>x;
    return x;

}

int User::contorID=-2; //index -1 pentru admin , de la 0 in sus pt Useri
int Joc::contor=0;
int Collectible::contor=0;

User useraux;

int main()
{


    /**/

    int conditie;
    conditie=welcome();
    if(conditie==0)
        terminate_app();


    User admin("admin","123",true); //declaram adminul
    Critic crit;
    std::vector <User> useri;
    int index_user=0;
    int user_curent=0;
    int ultimu=101;


    Market market(true,'a');
    int x=0;        //pe x il vom folosi drept input de decizie in meniul interactiv
    int auxi;

    bool cond1=0;

    while(conditie)
    {
        bool cond2=1;
        if(conditie==1)
        {
            market.setAdmin(true);
            if(cond2)
            {
                if(x==0)
                    x=main_menu(admin);
                int imeniu=1;
                int icolectie=1;
                switch(x)
                {
                case 0:
                {
                    verificare_iesire();
                    break;
                }
                case 105:
                {
                    cond2=0;
                    break;
                }
                case 101:
                {
                    x=market.afisare_pagina(imeniu);
                    if(x==100)
                    {
                        x=0;
                        break;
                    }
                    if(x==106)
                    {
                        cout<<"dupa ce sortam?(a=alfabetic, g=alfabetic dupa primul gen, i=index, n=nr achizitii, p=descrescator pret, P=crescator pret\nDecizie: ";
                        char cheie;
                        cin.get();
                        cin>>cheie;
                        market.sorteaza(cheie);
                        x=101;
                        break;
                    }
                    if(x==107)
                    {
                        cout<<"dupa ce gen filtram?\nDecizie: ";
                        string decizie;
                        cin>>decizie;
                        x=(market.filtreaza(decizie)).afisare_pagina(imeniu);
                        x=101;
                        break;
                    }
                    if(x==108)
                    {
                        cout<<"cauta:";
                        char cuv[50];
                        cin>>cuv;
                        x=(market.cauta(cuv)).afisare_pagina(imeniu);
                        x=101;
                        break;
                    }
                    if(x==109)
                    {
                        x=market.joc_random();
                        if(x==100)x=0;
                        break;
                    }
                    if(x==110)
                    {
                        ++imeniu;
                        x=market.afisare_pagina(imeniu);
                        break;
                    }
                    if(x==112)
                    {
                        if(market.getAdmin())
                        {
                            cout<<"cate jocuri introduceti? ";
                            int nrjocuri;
                            cin>>nrjocuri;
                            for(int iter=0; iter<nrjocuri; iter++)
                            {
                                Joc jocdeadaugat;
                                cin>>jocdeadaugat;
                                market+jocdeadaugat;

                            }
                        }
                        x=101;
                        break;
                    }
                    if(x==113)
                    {
                        if(market.getAdmin())
                        {
                            cout<<"cate DLC-uri introduceti? ";
                            int nrdlc;
                            cin>>nrdlc;
                            for(int iter=0; iter<nrdlc; iter++)
                            {
                                DLC dlcDeAdaugat;
                                cin>>dlcDeAdaugat;
                                market+dlcDeAdaugat;

                            }
                        }
                        x=101;
                        break;
                    }
                    if(x==116)
                    {
                        fout<<market;
                        fout<<endl;
                        for(int i=0; i<80; i++)
                            fout<<"~";
                        fout<<endl;
                        x=101;
                        break;
                    }

                    if(x==117)
                    {
                        int nrjocuri=0;

                        Joc jaux;

                        while(fin>>jaux)
                            market+jaux;

                        x=101;
                        break;
                    }
                    break;
                }
                case 104:
                {
                    auxi=admin.add_funds();
                    if(auxi==0)
                    {
                        x=0;
                        break;
                    }
                    else
                    {
                        while(auxi)
                        {
                            switch(auxi)
                            {
                            case 1:
                            {
                                admin+1.00;
                                break;
                            }
                            case 2:
                            {
                                admin+2.50;
                                break;
                            }
                            case 3:
                            {
                                admin+5.00;
                                break;
                            }
                            case 4:
                            {
                                admin+10.00;
                                break;
                            }
                            case 5:
                            {
                                admin+25.00;
                                break;
                            }
                            case 6:
                            {
                                admin+50.00;
                                break;
                            }
                            case 100:
                            {
                                x=0;
                                break;
                            }
                            case 101:
                            {
                                x=101;
                                break;
                            }
                            default:
                            {
                                x=0;
                                break;
                            }
                            }
                            if(x==0 or x==101)
                            {
                                break;
                            }
                            else
                                auxi=admin.add_funds();
                        }
                    }
                    break;
                }
                case 103:
                {
                    int auxprofil;
                    auxprofil=admin.afisare_profil();
                    switch (auxprofil)
                    {
                    case 0:
                    {
                        verificare_iesire();
                        x=0;
                        break;
                    }
                    case 100:
                    {
                        x=0;
                        break;
                    }
                    case 104:
                    {
                        x=104;
                        break;
                    }
                    case 116:
                    {
                        fout<<admin;
                        for(int i=0; i<60; i++)
                            fout<<"~";
                        x=103;
                        break;
                    }
                    case 120:
                    {

                        cout<<"Cum il cheama pe prieten?: ";
                        string numeaux;
                        cin>>numeaux;
                        admin.adaugaPrieten(numeaux);
                        x=103;

                        break;
                    }
                    default:
                    {
                        x=103;
                        break;
                    }

                    }
                    break;
                }
                case 102:
                {
                    x=(admin.getColectie()).afisare_pagina(icolectie);
                    if(x==100)
                    {
                        x=0;
                        break;
                    }
                    if(x==106)
                    {
                        cout<<"dupa ce sortam?(a=alfabetic, g=alfabetic dupa primul gen, i=index, n=nr achizitii, p=descrescator pret, P=crescator pret\nDecizie: ";
                        char cheiecolectie;
                        cin>>cheiecolectie;
                        admin.setColectie((admin.getColectie()).sorteaza(cheiecolectie));
                        x=102;
                        break;
                    }
                    if(x==107)
                    {
                        cout<<"dupa ce gen filtram colectia?";
                        char cautare[50];
                        cin>>cautare;
                        x=(admin.getColectie().filtreaza(cautare)).afisare_pagina(icolectie);
                        x=102;
                        break;
                    }
                    if(x==109)
                    {
                        x=admin.getColectie().joc_random();
                        x=102;
                        break;
                    }
                    if(x==116)
                    {
                        fout<<admin.getColectie();
                        fout<<endl;
                        for(int i=0; i<80; i++)
                            fout<<"~";
                        fout<<endl;
                        x=102;
                        break;
                    }



                    break;
                }

                default:
                {
                    int memo=x-1;
                    x=market.getJoc(x-1).afisare_pagina();
                    if(x==111)
                    {
                        if (admin<float(market.getJoc(memo)))
                            x=0;
                        else
                        {
                            admin.setColectie(admin.getColectie()*market.getJoc(memo));
                            admin-float(market.getJoc(memo));
                            market.getJoc(memo)++;
                            x=102;
                        }

                    }
                    if(x==116)
                    {
                        fout<<market.getJoc(memo);
                        for(int i=0; i<40; i++)
                            fout<<"~";
                        x=memo+1;
                    }
                    if(x==118)
                    {
                        x=pagina_items(market.getJoc(memo));
                        if(x==119)
                        {
                            cout<<"Item(1) sau Skin(2)?";
                            int auxIt;
                            cin>>auxIt;

                            if(auxIt==1)
                            {
                                Item it;
                                cin>>it;
                                market.getJocS(memo)->adaugaItem(it);
                            }
                            if(auxIt==2)
                            {
                                Skin sk;
                                cin>>sk;
                                market.getJocS(memo)->adaugaSkin(sk);
                            }
                            x=0;
                        }
                        else
                            x=0;
                    }
                    break;
                }
                }

            }
        }
        if(conditie==2)
        {
            if(cond1==0)
            {
                system("cls");
                market.setAdmin(false);
                cout<<"1)User nou\n2)Log-in\n\nDecizie: ";
                int xuser;
                cin>>xuser;
                system("cls");

                if(xuser==1)
                {
                    User ob;
                    cin>>ob;
                    useri.push_back(ob);
                    index_user++;
                    user_curent=useri.size()-1;
                    cond1=1;
                }
                if(xuser==2)
                {
                    char user_verif[50];
                    char pass_verif[50];
                    cout<<"username: ";
                    cin>>user_verif;
                    cout<<"parola: ";
                    cin>>pass_verif;
                    useraux.setPassword(pass_verif);
                    useraux.setUsername(user_verif);

                    bool conditie_login=false;
                    for(int i=0; i<useri.size(); i++)
                        if(useri[i]==useraux)
                        {
                            conditie_login=true;
                            user_curent=i;
                            cond1=1;
                            break;
                        }

                    if(conditie_login==false)cond2=0;
                }
            }


            if(cond2)
            {
                cout<<useri[user_curent];
                if(x==0)
                    x=main_menu(useri[user_curent]);
                int imeniu=1;
                int icolectie=1;
                int auxx=0;

                switch(x)
                {
                case 0:
                {
                    verificare_iesire();
                    break;
                }
                case 105:
                {
                    cond2=0;
                    break;
                }
                case 101:
                {
                    ultimu=101;
                    x=market.afisare_pagina(imeniu);
                    if(x==100)
                    {
                        x=0;
                        break;
                    }
                    if(x==106)
                    {
                        cout<<"dupa ce sortam?(a=alfabetic, g=alfabetic dupa primul gen, i=index, n=nr achizitii, p=descrescator pret, P=crescator pret\nDecizie: ";
                        char cheie;
                        cin.get();
                        cin>>cheie;
                        market.sorteaza(cheie);
                        x=101;
                        break;
                    }
                    if(x==107)
                    {
                        cout<<"dupa ce gen filtram?\nDecizie: ";
                        string decizie;
                        cin>>decizie;
                        x=(market.filtreaza(decizie)).afisare_pagina(imeniu);
                        x=101;
                        break;
                    }
                    if(x==108)
                    {
                        cout<<"cauta:";
                        char cuv[50];
                        cin>>cuv;
                        x=(market.cauta(cuv)).afisare_pagina(imeniu);
                        x=101;
                        break;
                    }
                    if(x==109)
                    {
                        x=market.joc_random();
                        if(x==100)x=0;
                        break;
                    }
                    if(x==110)
                    {
                        ++imeniu;
                        x=market.afisare_pagina(imeniu);
                        break;
                    }
                    if(x==116)
                    {
                        fout<<market;
                        fout<<endl;
                        for(int i=0; i<80; i++)
                            fout<<"~";
                        fout<<endl;
                        x=101;
                        break;
                    }

                    break;
                }
                case 104:
                {
                    auxi=useri[user_curent].add_funds();
                    if(auxi==0)
                    {
                        x=0;
                        break;
                    }
                    else
                    {
                        while(auxi)
                        {
                            switch(auxi)
                            {
                            case 1:
                            {
                                useri[user_curent]+1.00;
                                break;
                            }
                            case 2:
                            {
                                useri[user_curent]+2.50;
                                break;
                            }
                            case 3:
                            {
                                useri[user_curent]+5.00;
                                break;
                            }
                            case 4:
                            {
                                useri[user_curent]+10.00;
                                break;
                            }
                            case 5:
                            {
                                useri[user_curent]+25.00;
                                break;
                            }
                            case 6:
                            {
                                useri[user_curent]+50.00;
                                break;
                            }
                            case 100:
                            {
                                x=0;
                                break;
                            }
                            case 101:
                            {
                                x=101;
                                break;
                            }
                            default:
                            {
                                x=0;
                                break;
                            }
                            }
                            if(x==0 or x==101)
                            {
                                break;
                            }
                            else
                                auxi=useri[user_curent].add_funds();
                        }
                    }
                    break;
                }
                case 103:
                {
                    int auxprofil;
                    auxprofil=useri[user_curent].afisare_profil();
                    switch (auxprofil)
                    {
                    case 0:
                    {
                        verificare_iesire();
                        x=0;
                        break;
                    }
                    case 100:
                    {
                        x=0;
                        break;
                    }
                    case 104:
                    {
                        x=104;
                        break;
                    }
                    case 116:
                    {   fout<<endl;
                        fout<<useri[user_curent];
                        for(int i=0; i<60; i++)
                            fout<<"~";
                        x=103;
                        break;
                    }
                    case 120:
                    {

                        cout<<"Cum il cheama pe prieten?: ";
                        string numeaux;
                        cin>>numeaux;
                        useri[user_curent].adaugaPrieten(numeaux);
                        x=103;

                        break;
                    }

                    default:
                    {
                        x=103;
                        break;
                    }
                    }
                    break;
                }
                case 102:
                {
                    ultimu=102;
                    x=(useri[user_curent].getColectie()).afisare_pagina(icolectie);
                    if(x==100)
                    {
                        x=0;
                        break;
                    }
                    if(x==106)
                    {
                        cout<<"dupa ce sortam?(a=alfabetic, g=alfabetic dupa primul gen, i=index, n=nr achizitii, p=descrescator pret, P=crescator pret\nDecizie: ";
                        char cheiecolectie;
                        cin>>cheiecolectie;
                        useri[user_curent].setColectie((useri[user_curent].getColectie()).sorteaza(cheiecolectie));
                        x=102;
                        break;
                    }
                    if(x==107)
                    {
                        cout<<"dupa ce gen filtram colectia?";
                        char cautare[50];
                        cin>>cautare;
                        x=(useri[user_curent].getColectie().filtreaza(cautare)).afisare_pagina(icolectie);
                        x=102;
                        break;
                    }
                    if(x==109)
                    {
                        x=useri[user_curent].getColectie().joc_random();
                        x=102;
                        break;
                    }
                    if(x==116)
                    {
                        fout<<useri[user_curent].getColectie();
                        fout<<endl;
                        for(int i=0; i<80; i++)
                            fout<<"~";
                        fout<<endl;
                        x=102;
                        break;
                    }



                    break;
                }
                default:
                {
                    int memoreaza=x-1;

                    if(ultimu==101)
                    {
                        x=market.getJoc(x-1).afisare_pagina();
                        if(x==111)
                        {
                            if (useri[user_curent]<float(market.getJoc(memoreaza)))
                                x=0;
                            else
                            {
                                useri[user_curent].setColectie(useri[user_curent].getColectie()*market.getJoc(memoreaza));
                                useri[user_curent]-float(market.getJoc(memoreaza));
                                market.getJoc(memoreaza)++;
                                x=102;
                            }
                        }

                        if(x==114)
                        {
                            char text[500];
                            cout<<"\nReview: ";
                            cin.get();
                            cin.get(text,500);
                            Review rev(text);
                            market.getJocS(memoreaza)->adaugaRev(rev);
                            x=102;
                        }

                        if(x==115)
                        {
                            cout<<"\nNota(1-10): ";
                            int nota;
                            cin>>nota;
                            market.getJocS(memoreaza)->adaugaNota(useri[user_curent].getUsername(),nota);
                            x=102;
                        }
                        if(x==116)
                        {
                            fout<<market.getJoc(memoreaza);
                            for(int i=0; i<40; i++)
                                fout<<"~";
                            x=memoreaza+1;
                        }
                        if(x==118)
                        {
                            x=pagina_items(market.getJoc(memoreaza));
                            x=0;
                        }

                    }
                    if(ultimu==102)
                    {
                        x=useri[user_curent].getColectie().getJoc(memoreaza).afisare_pagina();

                        if(x==111)
                            x=102;

                        if(x==114)
                        {
                            char text[500];
                            cout<<"\nReview: ";
                            cin.get();
                            cin.get(text,500);
                            Review rev(text);
                            useri[user_curent].getColectieS()->getJocS(memoreaza)->adaugaRev(rev);
                            x=102;
                        }

                        if(x==115)
                        {
                            cout<<"\nNota(1-10): ";
                            int nota;
                            cin>>nota;
                            useri[user_curent].getColectieS()->getJocS(memoreaza)->adaugaNota(useri[user_curent].getUsername(),nota);
                            x=102;
                        }
                        if(x==116)
                        {
                            fout<<useri[user_curent].getColectie().getJoc(memoreaza);
                            for(int i=0; i<40; i++)
                                fout<<"~";
                            x=memoreaza+1;
                        }
                        if(x==118)
                        {
                            x=pagina_items(useri[user_curent].getColectie().getJoc(memoreaza));
                            x=0;
                        }
                    }
                    auxx=memoreaza;
                    break;
                }
                }

            }
        }

        if(conditie!=1 && conditie!=2)
            terminate_app();
        if(cond2==0)
        {
            conditie=welcome();
            cond1=0;
            x=0;
        }
    }


    fout.close();
    fin.close();


}
