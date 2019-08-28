#include "melangerLettres.h"
#include <string>
#include <algorithm>
#include <random>
#include <chrono>
//#include <algorithm>

std::string melangerLettres(std::string mot)
{
   std::string melange, tmp;
   int position(0);

   //Tant qu'on n'a pas extrait toutes les lettres du mot
   while (mot.size() != 0)
   {
        //On choisit un numéro de lettre au hasard dans le mot
        position = rand() % mot.size();

        melange += mot[position];

        mot.erase(position, 1);
    }
    return melange;
}


