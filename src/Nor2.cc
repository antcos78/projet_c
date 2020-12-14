
#include "../inc/Nor2.h"

using namespace std;


char Nor2::calculEtat()
{
  return !(getEtat(0)||getEtat(1));
}
