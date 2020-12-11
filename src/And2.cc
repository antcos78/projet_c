
#include "../inc/And2.h"

using namespace std;


bool And2::calculEtat()
{
  return (getEtat(0))&(getEtat(1));
}
