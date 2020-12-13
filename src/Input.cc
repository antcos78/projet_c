
#include "../inc/Input.h"
#include "../inc/Stimuli.h"

using namespace std;


char Input::calculEtat(Stimuli sti, int numero_periode)
{
  char input = sti.recupEntreeParNom(getNom(),numero_periode) - 48;
  cout << "input ... : " << (int*)input <<endl;
  return input ;
}
