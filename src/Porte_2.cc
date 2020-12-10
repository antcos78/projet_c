#include "../inc/Porte_2.h"

using namespace std;




void Porte_2::setEtat_1(bool etat_1)
{
  this->etat_1 = etat_1;
}

void Porte_2::setEtat_2(bool etat_2)
{
  this->etat_2 = etat_2;
}

void Porte_2::setFlag(char flag)
{
  this->flag = flag;
}

bool Porte_2::getEtat_1()
{
  return this->etat_1;
}

bool Porte_2::getEtat_2()
{
  return this->etat_2;
}

char Porte_2::getFlag()const
{
  return this->flag;
}
