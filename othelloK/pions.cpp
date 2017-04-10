#include "pions.h"
#include "console.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>///bibliothèque pour les fichiers
#include <vector>
#include <conio.h>

// Classe pion

/// Constructeur

Pion::Pion(string _type, int _posx,int _posy)
    :m_posx(_posx),m_posy(_posy),m_type( _type)

{

}


/// Destructeur

Pion::~Pion()
{

}

/// Accesseurs

void Pion::setPosx(int posx)
{
    m_posx=posx;
}

int Pion::getPosx()
{
    return m_posx;
}

void Pion::setPosy(int posy)
{
    m_posy=posy;
}

int Pion::getPosy()
{
    return m_posy;
}

void Pion::setType(string type)
{
    m_type=type;
}

string Pion::getType()
{
    return m_type;
}



void Pion::affichage_pion()
{

    int posx = ((3*m_posx)+8);
    int posy = ((2*m_posy)+6);
    pConsole->gotoLigCol(posy,posx);
    cout <<m_type;
}
