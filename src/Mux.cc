
#include "../inc/Mux.h"

using namespace std;


char Mux::calculEtat()
{
  cout << "etat I1  " << getEtat(0) << endl;
  cout << "etat I2  " << getEtat(1) << endl;
  cout << "etat I3  " << getEtat(2) << endl;

  if(getEtat(2)==0)
  {
    cout << "etat 1";

    return (getEtat(0));
  }
  else
  {
    cout << "etat 2";
    return (getEtat(1));
  }
}
