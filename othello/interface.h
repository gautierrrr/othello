#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include "console.h"
#include "pions.h"

#include <windows.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>///bibliothèque pour les fichiers
#include <vector>
#include <conio.h> ///bibliothèque du getch

using namespace std;


class Damier
{
private:

    //Attributs
    Console* pConsole;
    // On met en place le vector 2D de pointeur sur pion
    vector < vector <Pion*> > Map;
    //compteur de tour
    int m_cmptour = 0 ;
    string m_tour;


public:

    // Constructeur
    Damier ();
    ~Damier();

    // Methode
    void affichage_damier();
    void ajouter(Coordonne ma_case);
    void affichage_pion();
    bool blindage_ajout(Coordonne ma_case);
    string getTour();
    void aleatoire(Coordonne ma_case);
    int verification(Coordonne ma_case);
    Coordonne curseur(); //methodes pour utiliser un curseur
    void menu_de_jeu();
    void affichage_regles();
    void sauvegarder();
    void charger();

    // Accesseurs

    void setMap (vector <int> map2, int i);
    vector < vector <Pion*> > getMap();
};

#endif // INTERFACE_H_INCLUDED
