#include "choixMotsDico.h"
#include <string>
#include <vector>
#include <fstream>

#include <algorithm>
#include <random>
#include <chrono>
#include "melangerLettres.h"

std::string choixMots()
{
    std::string mot, motMelange;
    std::ifstream listeMots("../dico_perso.txt");

    if(!listeMots)
    {
        std::cout << "Erreur d'ouverture du fichier" << std::endl;
    }
    std::vector<std::string> motDico;
    std::string ligne;
    while (getline(listeMots,ligne))
    {
        motDico.push_back(ligne);
    }
    listeMots.close();

   unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
   std::mt19937 generator (seed);
   unsigned valeur = generator();

   std::shuffle(motDico.begin(), motDico.end(), generator);

return motDico[0];

}

