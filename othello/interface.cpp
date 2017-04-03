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





