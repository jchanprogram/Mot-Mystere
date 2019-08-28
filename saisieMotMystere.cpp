#include <iostream>
#include <stdio.h>
#include "saisieMotMystere.h"

    //Permet la saisie d'un mot par un joueur

std::string saisieMotMystere(std::string nomJoueur)
{
    std::string motMystere;
    std::cout << nomJoueur << " : Saisissez un mot" << std::endl;
    std::cin >> motMystere;
    std::cout << std::endl;

return motMystere;
}
