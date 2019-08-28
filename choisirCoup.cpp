#include <iostream>
#include <stdio.h>
#include "choisirCoup.h"

unsigned int choisirCoup()
{
    int choixCoup;
    std::cout << "Nombre maximale de coup ?" << std::endl;
    std::cout << "1. Illimité" << std::endl;
    std::cout << "2. Limité" << std::endl;
    std::cin >> choixCoup;
    while(std::cin.fail()) //si l'entrée est pas un int, ca fait le while
        {
            std::cout << "Erreur, il faut ecrire un nombre" << std::endl; //On signale l'erreur avec un cout
            std::cin.clear(); //On vide le flag qui indique qu'il y a une erreur
            std::cin.ignore(256,'\n'); //ignorer les prochains 256 caractère jusqu'a trouver le retour chariot
            std::cin >> choixCoup; //On redemande l'entrée
        }
    std::cout << std::endl;

    if ((choixCoup == 0) || (choixCoup > 2))
    {
        std::cout << "Reponse invalide" << std::endl;
        exit(0);
    }

    return choixCoup;
}
