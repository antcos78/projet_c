
#include "../inc/Xnor2.h"

using namespace std;


char Xnor2::calculEtat()
{
  char etat = (getEtat(0)^getEtat(1));
  for(int i = 2; i < getNbPorts();i++)
  {
    etat = !(getEtat(i) ^ etat);
  }
  return etat;
}
