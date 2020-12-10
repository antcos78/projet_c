#include <iostream>

#include "../inc/Items.h"
#include "../inc/Porte.h"
#include "../inc/Porte_1.h"
#include "../inc/Not.h"
#include "../inc/Porte_2.h"
#include "../inc/And2.h"
#include "../inc/Or2.h"
#include "../inc/Stimuli.h"

using namespace std;



int main ()
{
  cout << "salut" << endl;

  Stimuli parsingStimuli;



  parsingStimuli.addEntree("I1", "1010");
  cout << parsingStimuli.recupEntreeParNom("I1",1) << endl;
  cout << parsingStimuli.recupEntreeParNumero(0,2) << endl;



  return 0;
}
