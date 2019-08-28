#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "melangerLettres.h"
#include "choixMotsDico.h"
#include "jeuUnJoueur.h"
#include "jeuDeuxJoueurs.h"
#include "nombreJoueurs.h"


int main()
{
    std::cout << "Bienvenue dans le jeu Mot Mystere"<<std::endl;


    // Nombre des joueurs
    unsigned int nb = nombreJoueur();

    // On demande le mot de joueurs
    // ceci n'est pas fait en fonction avec une fonction ne peut pas retourner un tableau
    std::string listeNomJoueurs[nb];

    for (int i = 0; i< nb; i++)
    {
        std::cout << "Entrez le nom du Joueur " << i+1<< ": " << std::endl;
        std::cin >> listeNomJoueurs[i];
        while(std::cin.fail()) //si l'entrée est pas un int, ca fait le while
        {
            std::cout << "Erreur, choix le nombre de Joueur(s) : 1 ou 2" << std::endl; //On signale l'erreur avec un cout
            std::cin.clear(); //On vide le flag qui indique qu'il y a une erreur
            std::cin.ignore(256,'\n'); //ignorer les prochains 256 caractère jusqu'a trouver le retour chariot
            std::cin >> listeNomJoueurs[i]; //On redemande l'entrée
        }
        std::cout << listeNomJoueurs[i] <<" est le Joueur "<< i+1 << std::endl;
    }

    if(nb == 1)
    {
        jeuUnJoueur(listeNomJoueurs[0]);
    }
    else
    {
        jeuDeuxJoueurs(listeNomJoueurs[0],listeNomJoueurs[1]);
    }

    return 0;
}
