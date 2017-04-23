#ifndef PIONS_H_INCLUDED
#define PIONS_H_INCLUDED

#include "console.h"


#include <windows.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>///bibliothèque pour les fichiers
#include <vector>
#include <conio.h> ///bibliothèque du getch


using namespace std;


class Pion
{
private:

    // Attributs
    Console* pConsole;
    string m_type;   ///type du pion (Noir/Blanc)
    int m_posx;
    int m_posy;
    bool poser_pion;


public:

    // Constructeur / Destructeur

    Pion(string _type, int _posx ,int _posy);
    virtual ~Pion();

    //Méthodes
    void affichage_pion();

    // Accesseurs

    void setPosx(int posx);
    int getPosx();
    void setPosy(int posy);
    int getPosy();
    void setType(string type);
    string getType();


};



#endif // PIONS_H_INCLUDED
