#include <iostream>
#include <stdio.h>
#include "choixMaximumCoup.h"

unsigned int choixMaximumCoup (int choixCoup)
{
    int maximumCoup;
    if (choixCoup == 1)
    {
        std::cout << "Vous avez un nombre illimite de tentatives pour trouver le Mot Mystere" << std::endl;
    }

    else if (choixCoup==2)
    {
        std::cout << "Combien de coup souhaitez-vous" << std::endl;
        std::cin >> maximumCoup;
        while(std::cin.fail()) //si l'entrée est pas un int, ca fait le while
        {
            std::cout << "Erreur, il faut ecrire un nombre" << std::endl; //On signale l'erreur avec un cout
            std::cin.clear(); //On vide le flag qui indique qu'il y a une erreur
            std::cin.ignore(256,'\n'); //ignorer les prochains 256 caractère jusqu'a trouver le retour chariot
            std::cin >> maximumCoup; //On redemande l'entrée
        }

        std::cout << std::endl;
    }
    if (maximumCoup == 0)
    {
        std::cout << "Reponse invalide" << std::endl;
        exit(0);
    }
    return maximumCoup;
}
