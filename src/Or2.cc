
#include "../inc/Or2.h"

using namespace std;


bool Or2::calculEtat()
{
  return (getEtat(0))|(getEtat(1));
}
