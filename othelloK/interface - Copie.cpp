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

void Damier::aleatoire(Coordonne ma_case)   ///fonction d"ajout d"un pion sur le plateau de jeu
{
int affx = ma_case.x;
    int affy = ma_case.y;
    bool add = false;
    int n=1;
    vector<int> posx;
    vector<int> posy;
    vector<int> dirx;                                           ///  TOUT CA C'EST LE BLINDAGE
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
                    if (Map[i][j]->getType()!= " " && Map[i][j]->getType()!=c)         /// ENCORE LE BLINDAGE
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

    if (c=="N"){
    if(Map[affx][affy]->getType()==" " && !posx.empty())       //si la case est vide
    {



        for(int i=0; i<posx.size(); i++)
        {
            if(affx==posx[i]&&affy==posy[i])
            {
                add=true;
                for(int n=0;n<liste_n[i]+1;n++)
                    Map[affx-dirx[i]*n][affy-diry[i]*n]->setType(c);         /// CES DEUX LIGNES REPRESENTE LE JOUEUR


            }

        }
    }
    }
    else{


        int alea=rand()%posx.size();
        if(alea)
        {
            add=true;
            for(int n=0;n<liste_n[alea]+1;n++)
            Map[posx[alea]-dirx[alea]*n][posy[alea]-diry[alea]*n]->setType("B");  /// CES DEUX AUTRES LA PARTIE ALEATOIRE
        }


        }
    if(add==true)
        m_cmptour = (m_cmptour+1)%2;      //on incrémente le compteur de tour
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
