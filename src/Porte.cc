
#include "../inc/Porte.h"

using namespace std;


string Porte::getOutput(int numero_element) const
{
  if(numero_element<=(getNbOutput()-1))
  {
    return output[numero_element];
  }
  else
  {
    cout << "erreur porte";
    exit(1);
  }
}

int Porte::getNbOutput() const
{
  return output.size();
}

void Porte::ajoutOutput(string output_d)
{
  output.push_back(output_d);
}


void Porte::setFlag(char flag)
{
  this->flag = flag;
}

char Porte::getFlag()const
{
  return this->flag;
}


char Porte::getEtat(int numero_etat) const
{
  return etat[numero_etat];
}

int Porte::getNbEtat() const
{
  return etat.size();
}

void Porte::ajoutEtat(char etat_s, int numero_etat)
{
  etat[numero_etat] = etat_s;
}
