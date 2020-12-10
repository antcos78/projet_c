#include <iostream>

#include "../inc/Items.h"
#include "../inc/Porte.h"
#include "../inc/Porte_1.h"
#include "../inc/Not.h"
#include "../inc/Porte_2.h"
#include "../inc/And2.h"
#include "../inc/Or2.h"
using namespace std;



int main ()
{
  cout << "salut" << endl;

  Or2 salut("porte_AND2",2,26);
  Not notnot("not2",1,1);
  And2 tigre("porte",2,2);

  salut.setEtat_1(0);
  salut.setEtat_2(0);
  cout << "Etat avec etat_1 " << salut.getEtat_1() << " et etat2 " << salut.getEtat_2() <<": " << salut.calculEtat() << endl;
  salut.setEtat_1(0);
  salut.setEtat_2(1);
  cout << "Etat avec etat_1 0 et etat2 1: " << salut.calculEtat() << endl;
  salut.setEtat_1(1);
  salut.setEtat_2(0);
  cout << "Etat avec etat_1 1 et etat2 0: " << salut.calculEtat() << endl;
  salut.setEtat_1(1);
  salut.setEtat_2(1);
  cout << "Etat avec etat_1 1 et etat2 1: " << salut.calculEtat() << endl;


  salut.ajoutOutput(notnot.getNom());
  salut.ajoutOutput(tigre.getNom());
  cout << "en sortie : " << salut.getOutput(0) << endl;
  cout << "en sortie : " << salut.getOutput(1) << endl;
  cout << "en sortie : " << salut.getNbOutput() << endl;

  cout << "en sortie : " << salut.getOutput(2) << endl;


  return 0;
}
