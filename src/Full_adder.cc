
#include "../inc/Full_adder.h"

using namespace std;


char Full_adder::calculEtat()
{
  char etat = getEtat(0)&&getEtat(1);
  for(int i = 2; i < getNbPorts();i++)
  {
    etat = getEtat(i) && etat;
  }
  return etat;
}
