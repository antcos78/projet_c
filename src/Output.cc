
#include "../inc/Output.h"

using namespace std;


char Output::calculEtat()
{
  return getEtat(0);
}


char Output::getEtat(int numero_etat) const
{
  return etat[numero_etat];
}

int Output::getNbEtat() const
{
  return etat.size();
}

void Output::ajoutEtat(char etat_s, int numero_etat)
{
  etat[numero_etat] = etat_s;
}
