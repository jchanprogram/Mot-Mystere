#include <iostream>
#include <stdio.h>
#include "trouverMot.h"

// fonction qui compare le mot tapé par un joueur par rapport au mot mystere en fonction du nombre de tentative demandée


bool trouverMot(std::string nomJoueurs, int choixCoup, int maximumCoup, std::string motMelange,std::string motUtilisateur, std::string motMystere)
{
    bool comparaison(false);

    std::cout << nomJoueurs << " : Quel est ce mot ? "<< std::endl;
    std::cout  << motMelange << std::endl;
    if (choixCoup==2)
    {
        std::cout << std::endl << "Tu as "<< maximumCoup <<" tentative(s) rentantes" << std::endl;
    }
    std::cin >> motUtilisateur;
    while(std::cin.fail()) //si l'entrée est pas un int, ca fait le while
    {
        std::cout << "Erreur, il faut ecrire un mot" << std::endl; //On signale l'erreur avec un cout
        std::cin.clear(); //On vide le flag qui indique qu'il y a une erreur
        std::cin.ignore(256,'\n'); //ignorer les prochains 256 caractère jusqu'a trouver le retour chariot
        std::cin >> motUtilisateur; //On redemande l'entrée
    }

    std::cout << std::endl;

    if (motUtilisateur == motMystere)
    {
        std::cout << "Bravo !" << std::endl;
    }
    else
    {
        std::cout << "Ce n'est pas le mot !" << std::endl;
        if(choixCoup == 1)
        {
            maximumCoup = 2; //Permet de rendre le nombre de coup constant et donc illimité
        }
    }
    if ((motUtilisateur != motMystere) && (maximumCoup!=1))
    {
        comparaison = true;
    }

    if (maximumCoup == 1)
    {
        std::cout << "Tu n'as pas reussi a trouve le mot avec le nombre de tentative(s) demandees." << std::endl << std::endl;
    }
    return comparaison;
}
