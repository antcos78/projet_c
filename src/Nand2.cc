
#include "../inc/Nand2.h"

using namespace std;


char Nand2::calculEtat()
{
  return !(getEtat(0)&&getEtat(1));
}
