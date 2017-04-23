#include "console.h"
#include "interface.h"
#include "time.h"
#include "IA.h"

using namespace std;

int main()
{
    Damier plateau;
    Console *pConsole;
    Coordonne ma_case;
    int tmp=1;
    int choix_menu;
    int COMPT;
    srand(time(NULL));
    do
    {
        // Menu principal
        system("cls");
        plateau.affichage_menu();
        choix_menu = getch() ;

        switch(choix_menu)
        {
        case '1':

            // On met la console en vert
            system("cls");
            pConsole->setColor(COLOR_GREEN);
            plateau.affichage_damier();
            plateau.menu_de_jeu1();

            do
            {
                ///boucle de jeu
                plateau.affichage_pion();//affiche les pions
                ma_case = plateau.curseur(); // lance le curseur
                //pConsole->gotoLigCol(15,40);
                //cout << plateau.getTour()<<" "<<endl;
                if((ma_case.x==1000)&&(ma_case.y==1000))
                {
                    plateau.sauvegarder();
                    break;
                }
                plateau.ajouter(ma_case); //ajoute un pion
                COMPT=plateau.verification(ma_case);
                if (COMPT==0)
                {
                    system("cls");
                    cout<<"Joueur a gagne"<<endl;
                }

             }
            while(tmp!=0);
            break;
        case '2':
            system("cls");
            pConsole->setColor(COLOR_GREEN);

            plateau.affichage_damier();
            plateau.menu_de_jeu2();

            do
            {
                ///boucle de jeu
                plateau.affichage_pion();//affiche les pions
                ma_case = plateau.curseur(); // lance le curseur
                plateau.aleatoire(ma_case); //ajoute un pion
                /*COMPT=plateau.verification(ma_case);

                if (COMPT==0)
                {
                    system("cls");
                    cout<<"Joueur a gagne"<<endl;
                }

*/


            }
            while(tmp!=0);
            break;
        case '3':
            {

                Coordonne ma_case_finale;
                Damier jeu;
                jeu.setMap(plateau.getMap());

            int compteur_IA=0;
            // On met la console en vert
            system("cls");
            pConsole->setColor(COLOR_GREEN);
            plateau.affichage_damier();
            plateau.menu_de_jeu();
            cout << plateau.getTour()<<" "<<endl;
            do
            {
                ///boucle de jeu
                plateau.affichage_pion();//affiche les pions
                ma_case = plateau.curseur(); // lance le curseur
                if((ma_case.x==1000)&&(ma_case.y==1000))
                {
                    plateau.sauvegarder();
                    break;
                }

                if (compteur_IA%2==0)
                {
                    plateau.ajouter(ma_case); //ajoute un pion
                    compteur_IA++;
                }

                else
                {
                    ma_case_finale=IA_jouer(jeu,3);
                    plateau.ajouter(ma_case_finale);
                    compteur_IA++;
                }

                /*COMPT=plateau.verification(ma_case);
                if (COMPT==0)
                {
                    system("cls");
                    cout<<"Joueur a gagne"<<endl;
                }*/

             }
            while(tmp!=0);

            }
            break;
        case '4':
             system("cls");
            plateau.affichage_regles();
            pConsole->gotoLigCol(20,0);
            system("PAUSE");
            break;
        case '0':
            system("cls");
            cout << "vous allez quitter le jeu";
             pConsole->gotoLigCol(20,20);
            system("PAUSE");
            break;
        default:
            system("cls");
            cout << "choix incorrect" << endl;
            system("PAUSE");
            break;

        }
    }
    while(choix_menu!= '0');

return 0;
}
