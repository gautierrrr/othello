#include "interface.h"
#include "pions.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>///bibliothèque pour les fichiers
#include <vector>
#include <conio.h>

using namespace std;

// Class Damier
vector < vector <Pion*> > Damier::getMap()
{
    return(Map);
}

Damier::Damier()
{


    // Alloue la mémoire du pointeur
    pConsole = pConsole->getInstance();
    // Creation du vecteur 2D

    Map.resize(8);
    for(size_t i=0; i<8; i++)
    {
        Map[i].resize(8);
    }
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            Map[i][j]=new Pion(" ",i,j);
        }
    }

    // Ajout des pions de départs
    ///en haut à gauche
    Map[3][3]= new Pion("B",3,3);
    ///en bas à gauche
    Map[4][3]= new Pion("N",4,3);
    ///en bas à droite
    Map[4][4]= new Pion("B",4,4);
    ///en haut à gauche
    Map[3][4]= new Pion("N",3,4);

}

Damier:: ~Damier()
{

}

void Damier::affichage_damier() //Affichage du damier et des pions
{

//fonction qui affiche le damier dans la console
    pConsole= pConsole->getInstance();
    int lig=5;
    int col=7;
    //affichage du damier

    // ordonnee

    // Case A

    pConsole->gotoLigCol(5,0);

    cout << char(201)<<char(205)<<char(205)<<char(187)<< endl;

    cout << char(186)<<"A"<<" "<<char(186)<< endl;

    cout << char(204)<<char(205)<< char(205)<< char(185) <<endl;

    // Case B

    cout << char(186)<<"B"<<" "<<char(186) <<endl;

    cout << char(204)<<char(205)<< char(205)<< char(185) << endl;

    // Case C

    cout << char(186)<<"C"<<" "<<char(186)<< endl;

    cout << char(204)<<char(205)<< char(205)<< char(185) << endl;

    // Case D

    cout << char(186)<<"D"<<" "<<char(186)<< endl;

    cout << char(204)<<char(205)<< char(205)<< char(185) << endl;

    // Case E

    cout << char(186)<<"E"<<" "<<char(186) <<endl;

    cout << char(204)<<char(205)<<char(205)<<char(185) << endl;

    //Case F

    cout << char(186)<<"F"<<" "<<char(186) <<endl;

    cout << char(204)<<char(205)<<char(205)<<char(185) << endl;

    //Case G

    cout << char(186)<<"G"<<" "<<char(186) <<endl;

    cout << char(204)<<char(205)<<char(205)<<char(185) << endl;

    //Case H

    cout << char(186)<<"H"<<" "<<char(186) <<endl;

    cout << char(200)<<char(205)<<char(205)<<char(188) << endl;


    // Abscisse

    pConsole->gotoLigCol(2,7);

    cout<<char(201)<<char(205)<<char(205)<<char(203)<<char(205)<<char(205)<<char(203)<<char(205)<<char(205)<<char(203)<<char(205)<<char(205)<<char(203)<<char(205)<<char(205)<<char(203)
        <<char(205)<<char(205)<<char(203)<<char(205)<<char(205)<<char(203)<<char(205)<<char(205)<<char(187);


    pConsole->gotoLigCol(3,7);

    cout<<char(186)<<"1"<<" "<<char(186)<<"2"<<" "<<char(186)<<"3"<<" "<<char(186)<<"4"<<" "<<char(186)<<"5"<<" "<<char(186)
        <<"6"<<" "<<char(186)<<"7"<<" "<<char(186)<<"8"<<" "<<char(186);


    pConsole->gotoLigCol(4,7);

    cout<<char(200)<<char(205)<<char(205)<<char(202)<<char(205)<<char(205)<<char(202)<<char(205)<<char(205)<<char(202)<<char(205)<<char(205)<<char(202)
        <<char(205)<<char(205)<<char(202)<<char(205)<<char(205)<<char(202)<<char(205)<<char(205)<<char(202)<<char(205)<<char(205)<<char(188);


    //ligne du haut

    pConsole->gotoLigCol(lig,col);
    cout<<char(201)<<char(205)<<char(205)<<char(203)<<char(205)<<char(205)<<char(203)<<char(205)<<char(205)<<char(203)<<char(205)<<char(205)<<char(203)<<char(205)<<char(205)<<char(203)<<char(205)<<char(205)<<char(203)<<char(205)<<char(205)<<char(203)<<char(205)<<char(205)<<char(187) << endl;



    //ligne 2,3,4,5,6,7 et 8 haut

    for(int i=0; i<7 ; i++)
    {
        lig=lig+1;
        pConsole->gotoLigCol(lig,col);
        cout<<char(186)<<" "<<" "<<char(186)<<" "<<" "<<char(186)<<" "<<" "<<char(186)<<" "<<" "<<char(186)<<" "<<" "<<char(186)<<" "<<" "<<char(186)<<" "<<" "<<char(186)<<" "<<" "<<char(186)<<endl;
        lig=lig+1;
        pConsole->gotoLigCol(lig,col);
        cout<<char(204)<<char(205)<<char(205)<<char(206)<<char(205)<<char(205)<<char(206)<<char(205)<<char(205)<<char(206)<<char(205)<<char(205)<<char(206)<<char(205)<<char(205)<<char(206)<<char(205)<<char(205)<<char(206)<<char(205)<<char(205)<<char(206)<<char(205)<<char(205)<<char(185)<<endl;
    }

    //ligne 8 bas

    lig=lig+1;
    pConsole->gotoLigCol(lig,col);
    cout<<char(186)<<" "<<" "<<char(186)<<" "<<" "<<char(186)<<" "<<" "<<char(186)<<" "<<" "<<char(186)<<" "<<" "<<char(186)<<" "<<" "<<char(186)<<" "<<" "<<char(186)<<" "<<" "<<char(186)<<endl;
    lig=lig+1;
    pConsole->gotoLigCol(lig,col);
    cout<<char(200)<<char(205)<<char(205)<<char(202)<<char(205)<<char(205)<<char(202)<<char(205)<<char(205)<<char(202)<<char(205)<<char(205)<<char(202)<<char(205)<<char(205)<<char(202)<<char(205)<<char(205)<<char(202)<<char(205)<<char(205)<<char(202)<<char(205)<<char(205)<<char(188)<<endl;



}

void Damier::affichage_pion()
{
    for(int i=0 ; i<8 ; i++)
    {
        for(int j=0 ; j<8 ; j++)
        {
            Map[i][j]->affichage_pion();

        }

    }
}

void Damier::ajouter(Coordonne ma_case)   ///fonction d"ajout d"un pion sur le plateau de jeu
{
    int affx = ma_case.x;
    int affy = ma_case.y;
    bool add = false;
    int n=1;
    vector<int> posx;
    vector<int> posy;
    vector<int> dirx;
    vector<int> diry;
    vector<int> liste_n;


    affx = ((affx/3)-(8/3));
    affy = ((0.5*affy)-3);
    string c =  (m_cmptour%2 == 0 ? "N" : "B");

    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            for(int dx=-1; dx<=1; dx++)
            {
                for(int dy=-1; dy<=1; dy++)
                {
                    if (Map[i][j]->getType()!= " " && Map[i][j]->getType()!=c)
                    {
                        if(i+dx>=0&&i+dx<=7 && j+dy>=0&&j+dy<=7)
                        {
                            if(Map[i+dx][j+dy]->getType()==" ")
                            {
                                n = 1;
                                while(i-dx*n>=0&&i-dx*n<=7 && j-dy*n>=0&&j-dy*n<=7)
                                {
                                    if(Map[i-dx*n][j-dy*n]->getType()==c)
                                    {
                                        posx.push_back(i+dx);
                                        posy.push_back(j+dy);
                                        dirx.push_back(dx);
                                        diry.push_back(dy);
                                        liste_n.push_back(n);
                                        break;
                                    }
                                    else if(Map[i-dx*n][j-dy*n]->getType()==" ")
                                        break;
                                    else n++;
                                }


                            }

                        }

                    }
                }
            }
        }
    }
    cout << endl;
    if(Map[affx][affy]->getType()==" " && !posx.empty())       //si la case est vide
    {
        for(int i=0; i<posx.size(); i++)
        {
            if(affx==posx[i]&&affy==posy[i])
            {
                add=true;
                for(int n=0;n<liste_n[i]+1;n++)
                    Map[affx-dirx[i]*n][affy-diry[i]*n]->setType(c);

            }
        }
    }
    if(add==true)
        m_cmptour = (m_cmptour+1)%2;      //on incrémente le compteur de tour
}

string Damier::getTour()
{
    return m_tour;
}




Coordonne Damier::curseur()
{
    Coordonne ma_case;


    int lig=6;
    int col=8;
    pConsole->gotoLigCol(lig,col);
    int key=0;
    do
    {
        ///si on appuye sur une touche
        if(pConsole->isKeyboardPressed())
        {
            ///on lit la valeur de la touche
            key=pConsole->getInputKey();
            if(key=='z')
            {
                if(lig>6)
                {
                    lig=lig-2;
                    pConsole->gotoLigCol(lig,col);
                }
            }
            if(key=='q')
            {
                if(col>8)
                {
                    col=col-3;
                    pConsole->gotoLigCol(lig,col);
                }
            }
            if(key=='s')
            {
                if(lig<20)
                {
                    lig=lig+2;
                    pConsole->gotoLigCol(lig,col);
                }
            }
            if(key=='d')
            {
                if(col<29)
                {
                    col=col+3;
                    pConsole->gotoLigCol(lig,col);

                }
            }
            if(key==13) ///touche entrée
            {
                ///on renvoie la position du curseur

                ma_case.x = col;
                ma_case.y = lig;
                return ma_case;
            }

        }

    }
    while((key!=13));  ///tant qu"on appuye pas sur entrée


}
