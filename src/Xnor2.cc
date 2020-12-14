
#include "../inc/Xnor2.h"

using namespace std;


char Xnor2::calculEtat()
{
  return !(getEtat(0))^(getEtat(1));
}
