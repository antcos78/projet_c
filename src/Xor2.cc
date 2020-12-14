
#include "../inc/Xor2.h"

using namespace std;


char Xor2::calculEtat()
{
  return (getEtat(0))^(getEtat(1));
}
