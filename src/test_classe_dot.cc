#include <iostream>

#include "../inc/Items.h"
#include "../inc/Porte.h"
#include "../inc/Porte_1.h"
#include "../inc/Not.h"
#include "../inc/Porte_2.h"
#include "../inc/And2.h"
#include "../inc/Or2.h"
#include "../inc/Dot.h"

using namespace std;



int main ()
{
  cout << "salut" << endl;

  Dot parsingDot;

  Not salut("porte",1,1);

  parsingDot.addItems("porte", &salut);
  cout << parsingDot.trouverItemsParNom("porte")->getNom() << endl;
  cout << parsingDot.trouverItemsParNumero(0)->getNom() << endl;



  return 0;
}
