#include "jeuUnJoueur.h"
#include "choixMotsDico.h"
#include "melangerLettres.h"
#include "choisirCoup.h"
#include "choixMaximumCoup.h"
#include "recommencerPartie.h"
#include "trouverMot.h"

#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>
void jeuUnJoueur(std::string nomJoueurs)
{

int nouvellePartie;

do
{
    // Choisir si l'on souhaite avoir un nombre de coup limité
    unsigned int choixCoup = choisirCoup();
    // Choisir le nombre de coup si on a decide d'un choix limite
    unsigned int maximumCoup = choixMaximumCoup(choixCoup);

    // Jouer seul
    //Sélection du mot dans le Dico
    std::string motDico = choixMots();

    // Mot mystère
    std::string motMystere = motDico;

    // Mélange de mot
    std::string motMelange = melangerLettres(motMystere);

    std::string motUtilisateur;
    bool comparaisonMot;

    // le joueur recherche le mot
    do
    {
        comparaisonMot = trouverMot(nomJoueurs, choixCoup, maximumCoup, motMelange, motUtilisateur, motMystere);
        maximumCoup--;
    }while (comparaisonMot);

    nouvellePartie = recommencerPartie();

}while(nouvellePartie != 2);

}
