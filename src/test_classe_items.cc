#include <iostream>

#include "../inc/Items.h"
#include "../inc/Porte.h"
#include "../inc/Not.h"
#include "../inc/And2.h"
#include "../inc/Or2.h"
#include "../inc/Input.h"
#include "../inc/Nor2.h"
#include "../inc/Xnor2.h"
#include "../inc/Xor2.h"
#include "../inc/Nand2.h"

using namespace std;



int main ()
{
  cout << "salut" << endl;

  Xor2 salut("porte_AND2",2,26);
  Not notnot("not2",1,1);
  And2 tigre("porte",2,2);
  Items *lll = new Input ("input",2,2);

  salut.ajoutEtat(0,0);
  salut.ajoutEtat(0,1);
  cout << "etat 1 :"<< salut.calculEtat() <<endl;
  salut.ajoutEtat(1,0);
  salut.ajoutEtat(0,1);
  cout << "etat 2 :"<< salut.calculEtat() <<endl;
  salut.ajoutEtat(0,0);
  salut.ajoutEtat(1,1);
  cout << "etat 3 :"<< salut.calculEtat() <<endl;
  salut.ajoutEtat(1,0);
  salut.ajoutEtat(1,1);
  cout << "etat 4 :"<< salut.calculEtat() <<endl;

/*
  lll->ajoutOutput(notnot.getNom());
  lll->ajoutOutput(tigre.getNom());
  cout << "en sortie : " << lll->getOutput(0) << endl;
  cout << "en sortie : " << lll->getOutput(1) << endl;
  cout << "nb sortie : " << lll->getNbOutput() << endl;

  //cout << "en sortie : " << salut.getOutput(2) << endl;

  Or2  *tigrre = new Or2("porte_AND2",2,26);


  cout << "en sortie : " << tigrre->getEtat(0) << endl;

  cout << "en sortie : " << tigrre->getType() << endl;
  cout << "en sortie : " << tigrre->getNbPorts() << endl;
  */
  return 0;
}
