#include <iostream>

#include "../inc/Items.h"
#include "../inc/Porte.h"

#include "../inc/Not.h"
#include "../inc/And2.h"
#include "../inc/Or2.h"
#include "../inc/Dot.h"

using namespace std;



int main ()
{
  cout << "salut" << endl;

  Dot parsingDot;
  Items *salut = new Not("porte",1,1);

  //Not porte_not("porte_1",1,1);


  //parsingDot.parsingDot();
  parsingDot.addItems("porte",salut);

  cout << (salut)->getNbOutput()  << endl;
  //parsingDot.recupEntreeParNom("porte") << endl;
  //parsingDot.recupEntreeParNumero(0) << endl;

  // Items * forme[2];
  // forme[0] = new Not ("porte", 1,1);
  //
  // parsingDot.addItems("porte", &salut);
  // parsingDot.addItems("porte", forme[0]);
  //
  // cout << parsingDot.trouverItemsParNom("porte")->getNom() << endl;
  //
  // cout << forme[0]->getNbOutput()  << endl;



  return 0;
}
