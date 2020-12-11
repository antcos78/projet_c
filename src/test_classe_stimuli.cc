#include <iostream>

#include "../inc/Items.h"
#include "../inc/Porte.h"
#include "../inc/Not.h"
#include "../inc/And2.h"
#include "../inc/Or2.h"
#include "../inc/Stimuli.h"
#include "../inc/Input.h"
#include "../inc/Output.h"

using namespace std;



int main ()
{
  cout << "salut" << endl;

  Stimuli parsing;



  // parsing.addEntree("en", "1010");
  parsing.parsingStimuli(); 
  // cout << parsing.recupEntreeParNom("I1",0) << endl;
  // cout << parsingStimuli.recupEntreeParNumero(0,1) << endl;



  return 0;
}
