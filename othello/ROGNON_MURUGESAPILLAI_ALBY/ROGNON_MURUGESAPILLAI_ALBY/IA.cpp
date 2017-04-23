#include "IA.h"

int Min(Damier plateau, int profondeur)
{
    Damier jeu;
    jeu.setMap(plateau.getMap());

    if (profondeur == 0 )
    {
        return eval(plateau);
    }

    // Initialisation des variables

    int Min=1000;
    int tmp;
    Coordonne ma_case;


    // Boucle de recherche du min

    // On parcourt tout le damier a la recherche de coups possibles

    for (int i=0; i<8; i++)
    {
        for( int j=0; j<8; j++)
        {
            // Si on trouve un pion adverse

            if (jeu.getMap()[i][j]->getType()=="B")
            {
                /*cout << endl <<"min" << endl;
                cout << "la profondeur est: " << profondeur << endl;
                system("PAUSE");*/
                // On cherche les coups possibles autour de ce pion

                /// Diagonnale haute gauche

                if (jeu.getMap()[i-1][j-1]->getType()==" " && (i-1)>=0 && (j-1>=0) && (i-1)<8 && (j-1)<8)
                {
                    /// Ajout d'un pion

                    //jeu[i-1][j-1]->setType("N");

                    ma_case.x=8+((j-1)*3);
                    ma_case.y=6+((i-1)*2);
                    if (jeu.getCompteur_tour()%2==1)
                    {
                        jeu.setCompteur_tour(jeu.getCompteur_tour()+1);
                    }
                    jeu.ajouter(ma_case);



                    tmp=Max(jeu,profondeur-1);

                    if (tmp < Min)
                    {
                        Min=tmp;
                    }

                    jeu.setMap(plateau.getMap());
                }

                /// En haut

                if (jeu.getMap()[i-1][j]->getType()==" " && (i-1)>=0 && (j>=0)&& (i-1)<8 && (j)<8)
                {

                    /// Ajout d'un pion

                    //jeu[i-1][j]->setType("B");

                    ma_case.x=8+((j)*3);
                    ma_case.y=6+((i-1)*2);
                    if (jeu.getCompteur_tour()%2==1)
                    {
                        jeu.setCompteur_tour(jeu.getCompteur_tour()+1);
                    }
                    jeu.ajouter(ma_case);

                    tmp=Max(jeu,profondeur-1);

                    if (tmp < Min)
                    {
                        Min=tmp;
                    }

                    jeu.setMap(plateau.getMap());
                }

                /// Diagonnale haute droite

                if (jeu.getMap()[i-1][j+1]->getType()==" " && (i-1)>=0 && (j+1>=0) && (i-1)<8 && (j+1)<8)
                {

                    /// Ajout d'un pion

                    //jeu[i-1][j+1]->setType("B");

                    ma_case.x=8+((j+1)*3);
                    ma_case.y=6+((i-1)*2);
                    if (jeu.getCompteur_tour()%2==1)
                    {
                        jeu.setCompteur_tour(jeu.getCompteur_tour()+1);
                    }
                    jeu.ajouter(ma_case);
                    tmp=Max(jeu,profondeur-1);

                    if (tmp < Min)
                    {
                        Min=tmp;
                    }

                    jeu.setMap(plateau.getMap());
                }

                /// Gauche

                if (jeu.getMap()[i][j-1]->getType()==" " && i>=0 && (j-1>=0) && (i)<8 && (j-1)<8)
                {

                    /// Ajout d'un pion

                    //jeu[i][j-1]->setType("B");

                   ma_case.x=8+((j-1)*3);
                    ma_case.y=6+((i)*2);
                    if (jeu.getCompteur_tour()%2==1)
                    {
                        jeu.setCompteur_tour(jeu.getCompteur_tour()+1);
                    }
                    jeu.ajouter(ma_case);

                    tmp=Max(jeu,profondeur-1);

                    if (tmp < Min)
                    {
                        Min=tmp;
                    }

                    jeu.setMap(plateau.getMap());

                }

                /// Droite

                if (jeu.getMap()[i][j+1]->getType()==" " && (i-1)>=0 && (j+1>=0) && (i)<8 && (j+1)<8)
                {

                    /// Ajout d'un pion

                   // jeu[i][j+1]->setType("B");

                    ma_case.x=8+((j+1)*3);
                    ma_case.y=6+((i)*2);
                    if (jeu.getCompteur_tour()%2==1)
                    {
                        jeu.setCompteur_tour(jeu.getCompteur_tour()+1);
                    }
                    jeu.ajouter(ma_case);

                    tmp=Max(jeu,profondeur-1);

                    if (tmp < Min)
                    {
                        Min=tmp;
                    }

                    jeu.setMap(plateau.getMap());

                }

                /// Diagonnale basse gauche

                if (jeu.getMap()[i+1][j-1]->getType()==" " && (i+1)>=0 && (j-1>=0) && (i+1)<8 && (j-1)<8)
                {

                    /// Ajout d'un pion

                    //jeu[i+1][j-1]->setType("B");

                    ma_case.x=8+((j-1)*3);
                    ma_case.y=6+((i+1)*2);
                    if (jeu.getCompteur_tour()%2==1)
                    {
                        jeu.setCompteur_tour(jeu.getCompteur_tour()+1);
                    }
                    jeu.ajouter(ma_case);

                    tmp=Max(jeu,profondeur-1);

                    if (tmp < Min)
                    {
                        Min=tmp;
                    }

                    jeu.setMap(plateau.getMap());

                }

                /// bas

                if (jeu.getMap()[i+1][j]->getType()==" " && (i+1)>=0 && (j>=0) && (i+1)<8 && (j)<8)
                {

                    /// Ajout d'un pion

                    //jeu[i+1][j]->setType("B");

                    ma_case.x=8+((j)*3);
                    ma_case.y=6+((i+1)*2);
                    if (jeu.getCompteur_tour()%2==1)
                    {
                        jeu.setCompteur_tour(jeu.getCompteur_tour()+1);
                    }
                    jeu.ajouter(ma_case);

                    tmp=Max(jeu,profondeur-1);

                    if (tmp < Min)
                    {
                        Min=tmp;
                    }

                    jeu.setMap(plateau.getMap());

                }

                /// Diagonnale basse droite

                if (jeu.getMap()[i+1][j+1]->getType()==" " && (i+1)>=0 && (j+1>=0) && (i+1)<8 && (j+1)<8)
                {

                    /// Ajout d'un pion

                   // jeu[i+1][j+1]->setType("B");

                    ma_case.x=8+((j+1)*3);
                    ma_case.y=6+((i+1)*2);
                    if (jeu.getCompteur_tour()%2==1)
                    {
                        jeu.setCompteur_tour(jeu.getCompteur_tour()+1);
                    }
                    jeu.ajouter(ma_case);

                    tmp=Max(jeu,profondeur-1);

                    if (tmp < Min)
                    {
                        Min=tmp;
                    }

                    jeu.setMap(plateau.getMap());

                }
            }


        }

    }


    return Min;
}

int Max(Damier plateau, int profondeur)
{
 Damier jeu;
    jeu.setMap(plateau.getMap());

    if (profondeur == 0)
    {
        return eval(plateau);
    }

    // Initialisation des variables

    int Max=-1000;
    int tmp;

    Coordonne ma_case;



    // Boucle de recherche du min

    // On parcourt tout le damier a la recherche de coups possibles

    for (int i=0; i<8; i++)
    {
        for( int j=0; j<8; j++)
        {
            // Si on trouve un pion adverse

            if (jeu.getMap()[i][j]->getType()=="N")
            {
                /*cout << endl <<"max" << endl;
                cout << "la profondeur est: " << profondeur << endl;
                system("PAUSE");*/

                // On cherche les coups possibles autour de ce pion

                /// Diagonnale haute gauche

                if (jeu.getMap()[i-1][j-1]->getType()==" " && (i-1)>=0 && (j-1>=0) && (i-1)<8 && (j-1)<8)
                {
                    /// Ajout d'un pion

                   // jeu[i-1][j-1]->setType("B");

                    ma_case.x=8+((j-1)*3);
                    ma_case.y=6+((i-1)*2);
                    if (jeu.getCompteur_tour()%2==0)
                    {
                        jeu.setCompteur_tour(jeu.getCompteur_tour()+1);
                    }
                    jeu.ajouter(ma_case);

                    tmp=Min(jeu,profondeur-1);

                    if (tmp > Max)
                    {
                        Max=tmp;
                    }

                    jeu.setMap(plateau.getMap());
                }

                /// En haut

                if (jeu.getMap()[i-1][j]->getType()==" " && (i-1)>=0 && (j>=0)&& (i-1)<8 && (j)<8)
                {

                    /// Ajout d'un pion

                    //jeu[i-1][j]->setType("B");

                    ma_case.x=8+((j)*3);
                    ma_case.y=6+((i-1)*2);
                    if (jeu.getCompteur_tour()%2==0)
                    {
                        jeu.setCompteur_tour(jeu.getCompteur_tour()+1);
                    }
                    jeu.ajouter(ma_case);

                    tmp= Min(jeu,profondeur-1);

                    if (tmp > Max)
                    {
                        Max=tmp;
                    }

                    jeu.setMap(plateau.getMap());
                }

                /// Diagonnale haute droite

                if (jeu.getMap()[i-1][j+1]->getType()==" " && (i-1)>=0 && (j+1>=0) && (i-1)<8 && (j+1)<8)
                {

                    /// Ajout d'un pion

                    //jeu[i-1][j+1]->setType("B");

                   ma_case.x=8+((j+1)*3);
                    ma_case.y=6+((i-1)*2);
                    if (jeu.getCompteur_tour()%2==0)
                    {
                        jeu.setCompteur_tour(jeu.getCompteur_tour()+1);
                    }
                    jeu.ajouter(ma_case);

                    tmp=Min(jeu,profondeur-1);

                    if (tmp > Max)
                    {
                        Max=tmp;
                    }

                    jeu.setMap(plateau.getMap());
                }

                /// Gauche

                if (jeu.getMap()[i][j-1]->getType()==" " && i>=0 && (j-1>=0) && (i)<8 && (j-1)<8)
                {

                    /// Ajout d'un pion

                    //jeu[i][j-1]->setType("B");

                    ma_case.x=8+((j-1)*3);
                    ma_case.y=6+((i)*2);
                    if (jeu.getCompteur_tour()%2==0)
                    {
                        jeu.setCompteur_tour(jeu.getCompteur_tour()+1);
                    }
                    jeu.ajouter(ma_case);

                    tmp=Min(jeu,profondeur-1);

                    if (tmp > Max)
                    {
                        Max=tmp;
                    }

                    jeu.setMap(plateau.getMap());

                }

                /// Droite

                if (jeu.getMap()[i][j+1]->getType()==" " && (i-1)>=0 && (j+1>=0) && (i)<8 && (j+1)<8)
                {

                    /// Ajout d'un pion

                   //jeu[i][j+1]->setType("B");

                    ma_case.x=8+((j+1)*3);
                    ma_case.y=6+((i)*2);
                    if (jeu.getCompteur_tour()%2==0)
                    {
                        jeu.setCompteur_tour(jeu.getCompteur_tour()+1);
                    }
                    jeu.ajouter(ma_case);

                    tmp=Min(jeu,profondeur-1);

                    if (tmp > Max)
                    {
                        Max=tmp;
                    }

                    jeu.setMap(plateau.getMap());
                }

                /// Diagonnale basse gauche

                if (jeu.getMap()[i+1][j-1]->getType()==" " && (i+1)>=0 && (j-1>=0) && (i+1)<8 && (j-1)<8)
                {

                    /// Ajout d'un pion

                    //jeu[i+1][j-1]->setType("B");

                    ma_case.x=8+((j-1)*3);
                    ma_case.y=6+((i+1)*2);
                    if (jeu.getCompteur_tour()%2==0)
                    {
                        jeu.setCompteur_tour(jeu.getCompteur_tour()+1);
                    }
                    jeu.ajouter(ma_case);

                    tmp=Min(jeu,profondeur-1);

                    if (tmp > Max)
                    {
                        Max=tmp;
                    }

                    jeu.setMap(plateau.getMap());
                }

                /// bas

                if (jeu.getMap()[i+1][j]->getType()==" " && (i+1)>=0 && (j>=0) && (i+1)<8 && (j)<8)
                {

                    /// Ajout d'un pion

                    //jeu[i+1][j]->setType("B");

                    ma_case.x=8+((j)*3);
                    ma_case.y=6+((i+1)*2);
                    if (jeu.getCompteur_tour()%2==0)
                    {
                        jeu.setCompteur_tour(jeu.getCompteur_tour()+1);
                    }
                    jeu.ajouter(ma_case);

                    tmp=Min(jeu,profondeur-1);

                    if (tmp > Max)
                    {
                        Max=tmp;
                    }

                    jeu.setMap(plateau.getMap());

                }

                /// Diagonnale basse droite

                if (jeu.getMap()[i+1][j+1]->getType()==" " && (i+1)>=0 && (j+1>=0) && (i+1)<8 && (j+1)<8)
                {

                    /// Ajout d'un pion

                    //jeu[i+1][j+1]->setType("B");

                    ma_case.x=8+((j+1)*3);
                    ma_case.y=6+((i+1)*2);
                    if (jeu.getCompteur_tour()%2==0)
                    {
                        jeu.setCompteur_tour(jeu.getCompteur_tour()+1);
                    }
                    jeu.ajouter(ma_case);

                    tmp=Min(jeu,profondeur-1);

                    if (tmp > Max)
                    {
                        Max=tmp;
                    }

                    jeu.setMap(plateau.getMap());

                }
            }
        }
    }

    return Max;
}

Coordonne IA_jouer(Damier plateau, int profondeur)
{
    // Variables

    Damier jeu;
    jeu.setMap(plateau.getMap());

    int Max=-1000;
    int tmp,maxi,maxj;
    Coordonne ma_case, ma_case_finale;

    // On parcourt tout le damier a la recherche de coups possibles

    for (int i=0; i<8; i++)
    {
        for( int j=0; j<8; j++)
        {
            // Si on trouve un pion adverse

            if (jeu.getMap()[i][j]->getType()=="N")
            {
                // On cherche les coups possibles autour de ce pion

                /// Diagonnale haute gauche

                if (jeu.getMap()[i-1][j-1]->getType()==" " && (i-1)>=0 && (j-1>=0))
                {
                    //jeu[i-1][j-1]->setType("B");

                    ma_case.x=8+((j-1)*3);
                    ma_case.y=6+((i-1)*2);
                    if (jeu.getCompteur_tour()%2==0)
                    {
                        jeu.setCompteur_tour(jeu.getCompteur_tour()+1);
                    }
                    jeu.ajouter(ma_case);

                    tmp=Min(jeu,profondeur-1);

                    if (tmp>Max)
                    {
                        Max=tmp;
                        maxi=i-1;
                        maxj=j-1;
                        ma_case_finale.x=8+((j-1)*3);
                        ma_case_finale.y=6+((i-1)*2);

                    }

                    jeu.setMap(plateau.getMap());

                }

                /// En haut

                if (jeu.getMap()[i-1][j]->getType()==" " && (i-1)>=0 && (j>=0))
                {

                    //jeu[i-1][j]->setType("B");

                    ma_case.x=8+((j)*3);
                    ma_case.y=6+((i-1)*2);
                    if (jeu.getCompteur_tour()%2==0)
                    {
                        jeu.setCompteur_tour(jeu.getCompteur_tour()+1);
                    }
                    jeu.ajouter(ma_case);

                    tmp=Min(jeu,profondeur-1);

                    if (tmp>Max)
                    {
                        Max=tmp;
                        maxi=i-1;
                        maxj=j;
                        ma_case_finale.x=8+((j)*3);
                        ma_case_finale.y=6+((i-1)*2);

                    }

                    jeu.setMap(plateau.getMap());

                }

                /// Diagonnale haute droite

                if (jeu.getMap()[i-1][j+1]->getType()==" "&& (i-1)>=0 && (j+1>=0))
                {
                    //jeu[i-1][j+1]->setType("B");

                    ma_case.x=8+((j+1)*3);
                    ma_case.y=6+((i-1)*2);
                    if (jeu.getCompteur_tour()%2==0)
                    {
                        jeu.setCompteur_tour(jeu.getCompteur_tour()+1);
                    }
                    jeu.ajouter(ma_case);

                    tmp=Min(jeu,profondeur-1);

                    if (tmp>Max)
                    {
                        Max=tmp;
                        maxi=i-1;
                        maxj=j+1;
                        ma_case_finale.x=8+((j+1)*3);
                        ma_case_finale.y=6+((i-1)*2);

                    }

                    jeu.setMap(plateau.getMap());

                }

                /// Gauche

                if (jeu.getMap()[i][j-1]->getType()==" " && i>=0 && (j-1>=0))
                {
                    //jeu[i][j-1]->setType("B");

                   ma_case.x=8+((j-1)*3);
                    ma_case.y=6+((i)*2);
                    if (jeu.getCompteur_tour()%2==0)
                    {
                        jeu.setCompteur_tour(jeu.getCompteur_tour()+1);
                    }
                    jeu.ajouter(ma_case);

                    tmp=Min(jeu,profondeur-1);

                    if (tmp>Max)
                    {
                        Max=tmp;
                        maxi=i;
                        maxj=j-1;
                        ma_case_finale.x=8+((j-1)*3);
                        ma_case_finale.y=6+((i)*2);

                    }

                    jeu.setMap(plateau.getMap());

                }

                /// Droite

                if (jeu.getMap()[i][j+1]->getType()==" " && (i)>=0 && (j+1>=0))
                {
                    //jeu[i][j+1]->setType("B");

                   ma_case.x=8+((j+1)*3);
                    ma_case.y=6+((i)*2);
                    if (jeu.getCompteur_tour()%2==0)
                    {
                        jeu.setCompteur_tour(jeu.getCompteur_tour()+1);
                    }
                    jeu.ajouter(ma_case);

                    tmp=Min(jeu,profondeur-1);

                    if (tmp>Max)
                    {
                        Max=tmp;
                        maxi=i;
                        maxj=j+1;
                        ma_case_finale.x=8+((j+1)*3);
                        ma_case_finale.y=6+((i)*2);

                    }

                    jeu.setMap(plateau.getMap());
                }

                /// Diagonnale basse gauche

                if (jeu.getMap()[i+1][j-1]->getType()==" " && (i+1)>=0 && (j-1>=0))
                {
                    //jeu[i+1][j-1]->setType("B");

                    ma_case.x=8+((j-1)*3);
                    ma_case.y=6+((i+1)*2);
                    if (jeu.getCompteur_tour()%2==0)
                    {
                        jeu.setCompteur_tour(jeu.getCompteur_tour()+1);
                    }
                    jeu.ajouter(ma_case);

                    tmp=Min(jeu,profondeur-1);

                    if (tmp>Max)
                    {
                        Max=tmp;
                        maxi=i+1;
                        maxj=j-1;
                        ma_case_finale.x=8+((j-1)*3);
                        ma_case_finale.y=6+((i+1)*2);

                    }

                    jeu.setMap(plateau.getMap());

                }

                /// bas

                if (jeu.getMap()[i+1][j]->getType()==" " && (i+1)>=0 && (j>=0))
                {
                    //jeu[i+1][j]->setType("B");

                    ma_case.x=8+((j)*3);
                    ma_case.y=6+((i+1)*2);
                    if (jeu.getCompteur_tour()%2==0)
                    {
                        jeu.setCompteur_tour(jeu.getCompteur_tour()+1);
                    }
                    jeu.ajouter(ma_case);

                    tmp=Min(jeu,profondeur-1);

                    if (tmp>Max)
                    {
                        Max=tmp;
                        maxi=i+1;
                        maxj=j;
                        ma_case_finale.x=8+((j)*3);
                        ma_case_finale.y=6+((i+1)*2);
                    }

                    jeu.setMap(plateau.getMap());

                }

                /// Diagonnale basse droite

                if (jeu.getMap()[i+1][j+1]->getType()==" " && (i+1)>=0 && (j+1>=0))
                {
                    //jeu[i+1][j+1]->setType("B");

                    ma_case.x=8+((j+1)*3);
                    ma_case.y=6+((i+1)*2);
                    if (jeu.getCompteur_tour()%2==0)
                    {
                        jeu.setCompteur_tour(jeu.getCompteur_tour()+1);
                    }
                    jeu.ajouter(ma_case);

                    tmp=Min(jeu,profondeur-1);

                    if (tmp>Max)
                    {
                        Max=tmp;
                        maxi=i+1;
                        maxj=j+1;
                        ma_case_finale.x=8+((j+1)*3);
                        ma_case_finale.y=6+((i+1)*2);
                    }

                    jeu.setMap(plateau.getMap());

                }
            }


        }

    }

  return ma_case_finale;
    //plateau.setCompteur_tour(plateau.getCompteur_tour()+1);

}


int eval (Damier jeu)
{
    // Variables

    int compteur_IA=0;
    int compteur_joueur=0;
    int vainqueur;

    // On parcourt tout le damier

    for(int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            if (jeu.getMap()[i][j]->getType()=="B")
            {
                compteur_IA++;
            }
            if (jeu.getMap()[i][j]->getType()=="N")
            {
                compteur_joueur++;
            }
        }
    }

    // On renvoie le nombre de pion de l'IA

    return compteur_IA;

   /* // On retourne le vainqueur

    if(compteur_joueur1>compteur_joueur2)
    {
        vainqueur=1;
    }
    else
    {
        vainqueur=2;
    }

    return vainqueur;

    */


}

int gagnant (vector < vector < Pion* > > jeu)
{

}

