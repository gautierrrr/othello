#include "interface.h"
#include "pions.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>///bibliothèque pour les fichiers
#include <vector>
#include <conio.h>
#include "time.h"

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

void Damier::affichage_regles()   //permet de lire un fichier txt contenant les règles du jeu
{
    ifstream regle("regle.txt"); //on ouvre le fichier en indiquant le chemin

    if(regle)
    {
        string ligne;  //chaine qui va stocker la chaine lu (ici on lit le fichier ligne par ligne)

        while(getline(regle,ligne))   //tant qu'on est pas a la fin du fichier
        {
            cout << ligne << endl;    //on affiche la ligne
        }

    }
    else    //on test l'ouverture
    {
        cout << "ouverture impossible" << endl;

    }

}





void Damier::menu_de_jeu()  //affichage du menu pendant les tours de jeu
{
    pConsole->gotoLigCol(5,40);
    cout << "----------------  menu  ---------------" << endl;
    pConsole->gotoLigCol(6,40);
    cout << "---    z,q,s,d pour se deplacer     ---" << endl;
    pConsole->gotoLigCol(7,40);
    cout << "---   entree pour ajouter un pion   ---" << endl;
    pConsole->gotoLigCol(8,40);
    cout << "---echap pour sauvegarder et quitter---" << endl;
    pConsole->gotoLigCol(9,40);
    cout << "---------------------------------------" << endl;
    pConsole->gotoLigCol(11,40);
    if(m_cmptour%2==0)
    {
        cout << "noir";
    }
    if(m_cmptour%2==1)
    {
        cout << "blanc";
    }
}


Coordonne Damier::curseur()
{
    Coordonne ma_case;
    int lig=6;
    int col=8;
    int key=0;
    pConsole->gotoLigCol(lig,col);
    do
    {
        //si on appuye sur une touche
        if(pConsole->isKeyboardPressed())
        {
            //on lit la valeur de la touche
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
            if(key==13) //touche entrée
            {
                //on renvoie la position du curseur

                ma_case.x = col;
                ma_case.y = lig;
                return ma_case;
            }
            if(key==27) //touche échap
            {
                // on renvoie la position du curseur
                ma_case.x  = 1000;
                ma_case.y = 1000;
                return  ma_case;
            }

        }

    }
    while((key!=13)&&(key!=27));  //tant qu'on appuye pas sur entrée ou sur échap


}


