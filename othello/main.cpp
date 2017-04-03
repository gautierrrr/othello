#include "console.h"
#include "interface.h"
#include "time.h"


using namespace std;

int main()
{
    Damier plateau;
    Console *pConsole;
    int choix_menu;
    do
    {
        // Menu principal
        system("cls");
        cout << "Menu principal" << endl;
        cout << "1 : 2 joueur" << endl;
        cout << "2 : niveau 1" << endl;
        cout << "3 : niveau 2" << endl;
        cout << "4 : regles" << endl;
        cout << "0 : quitter le jeu" << endl;
        choix_menu = getch() ;

        switch(choix_menu)
        {
        case '1':

            // On met la console en vert
            system("cls");
            pConsole->setColor(COLOR_GREEN);
            plateau.affichage_damier();
            do
            {
                ///boucle de jeu
                plateau.affichage_pion();//affiche les pions

             }
            while(tmp!=0);
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
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

