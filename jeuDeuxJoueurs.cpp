#include "jeuDeuxJoueurs.h"
#include "choixMotsDico.h"
#include "melangerLettres.h"
#include "choisirCoup.h"
#include "choixMaximumCoup.h"
#include "recommencerPartie.h"
#include "trouverMot.h"
#include "saisieMotMystere.h"

#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>


void jeuDeuxJoueurs(std::string nomJoueurs1,std::string nomJoueurs2)

{
int nouvellePartie;

do
{
    // Choisir si l'on souhaite avoir un nombre de coup limité
    unsigned int choixCoup = choisirCoup();
    // Choisir le nombre de coup si on a decide d'un choix limite
    unsigned int maximumCoup = choixMaximumCoup(choixCoup);
    int tpmMaxCoup = maximumCoup; // permet de donner le meme nombre de tentative max au deux joueurs

    // le joueur 2 ecrit a mot a faire deviner au joueur 1 et ce dernier doit le trouver
    std::string motMystere = saisieMotMystere(nomJoueurs1);
    // Mélange de mot
    std::string motMelange = melangerLettres(motMystere);
    std::string motUtilisateur;
    bool comparaisonMot;


    do
    {
        comparaisonMot = trouverMot(nomJoueurs2, choixCoup, maximumCoup, motMelange, motUtilisateur, motMystere);
        maximumCoup--;
    }while (comparaisonMot);

    // le joueur 1 ecrit a mot a faire deviner au joueur 2 et ce dernier doit le trouver

    motMystere = saisieMotMystere(nomJoueurs2);
    // Mélange de mot
    motMelange = melangerLettres(motMystere);
    maximumCoup = tpmMaxCoup;
    do
    {
        comparaisonMot = trouverMot(nomJoueurs1, choixCoup, maximumCoup, motMelange, motUtilisateur, motMystere);
        maximumCoup--;
    }while (comparaisonMot);

    nouvellePartie = recommencerPartie();

}while(nouvellePartie != 2);

}

