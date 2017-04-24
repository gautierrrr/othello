#ifndef IA_H_INCLUDED
#define IA_H_INCLUDED

#include <vector>
#include "interface.h"
#include "pions.h"
#include <string>


using namespace std;


int Min(Damier plateau, int profondeur);
int Max (Damier plateau, int profondeur);
Coordonne IA_jouer(Damier plateau, int profondeur);
void recherche_coup(vector < vector < Pion* > > jeu);
int eval (Damier jeu);
int gagnant (vector < vector < Pion* > > jeu);

#endif // IA_H_INCLUDED
