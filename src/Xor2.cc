
#include "../inc/Xor2.h"

using namespace std;


char Xor2::calculEtat()
{
  char etat = (getEtat(0)^getEtat(1));
  for(int i = 2; i < getNbPorts();i++)
  {
    etat = (getEtat(i) ^ etat);
  }
  return etat;
}
