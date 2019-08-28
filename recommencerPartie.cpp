#include <iostream>
#include <stdio.h>
#include "recommencerPartie.h"

    //Permet de demande si l'on souhaiter recommencer une partie

int recommencerPartie()
{
    int nouvellePartie;
    std::cout << "Voulez-vous recommencer une partie ?" << std::endl;
    std::cout << "1. Oui" << std::endl;
    std::cout << "2. Non" << std::endl;
    std::cin >> nouvellePartie;
    // on teste si le cin est bien un entier, sinon le programme plante
    while(std::cin.fail()) //si l'entrée est pas un int, ca fait le while
    {
        std::cout << "Erreur, choisi entre 1 et 2 pour recommencer ou non une partie" << std::endl; //On signale l'erreur avec un cout
        std::cin.clear(); //On vide le flag qui indique qu'il y a une erreur
        std::cin.ignore(256,'\n'); //ignorer les prochains 256 caractère jusqu'a trouver le retour chariot
        std::cin >> nouvellePartie; //On redemande l'entrée
    }
    std::cout << std::endl;

    if ((nouvellePartie == 0) || (nouvellePartie > 2))
    {
        std::cout << "Reponse invalide" << std::endl;
        exit(0);
    }
    return nouvellePartie;
}

