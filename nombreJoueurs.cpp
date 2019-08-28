#include <iostream>
#include <stdio.h>
#include "nombreJoueurs.h"

    // permet de définier le nombre de joueur dans la partie

unsigned int nombreJoueur()
{
    unsigned int nb;
    std::cout<< "Combien de joueur dans cette partie"<<std::endl;
    std::cout << "1. 1 Joueur" << std::endl;
    std::cout << "2. 2 Joueurs" << std::endl;
    std::cin >> nb;
    while(std::cin.fail()) //si l'entrée est pas un int, ca fait le while
        {
            std::cout << "Erreur, choix le nombre de Joueur(s) : 1 ou 2" << std::endl; //On signale l'erreur avec un cout
            std::cin.clear(); //On vide le flag qui indique qu'il y a une erreur
            std::cin.ignore(256,'\n'); //ignorer les prochains 256 caractère jusqu'a trouver le retour chariot
            std::cin >> nb; //On redemande l'entrée
        }
    if ((nb == 0) || (nb > 2))
    {
        std::cout << "nombre de joueurs invalide" << std::endl;
        exit(0);
    }
    return nb;
}
