
#include "../inc/Full_adder_cout.h"

using namespace std;


char Full_adder_cout::calculEtat()
{
  char etat = getEtat(0)&&getEtat(1);
  for(int i = 2; i < getNbPorts();i++)
  {
    etat = getEtat(i) && etat;
  }
  return etat;
}
