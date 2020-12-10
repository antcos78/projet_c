#include <iostream>

#include "../inc/Items.h"
#include "../inc/Porte.h"
#include "../inc/Porte_1.h"
#include "../inc/Not.h"
#include "../inc/Porte_2.h"
#include "../inc/And2.h"
#include "../inc/Or2.h"
#include "../inc/Schema.h"
using namespace std;



int main ()
{
  Schema at;
  cout << "Element schema : " << at.getNbElements_schema() << endl;
  at.ajouterElements_schema("salut");

  cout << "Element schema : " << at.getNbElements_schema() << endl;
  cout << "element 1 : " << at.lireElements_schema(0) << endl;

  cout << "Element schema : " << at.getNbElements_input() << endl;
  at.ajouterElements_input("trop");

  cout << "Element schema : " << at.getNbElements_input() << endl;
  cout << "element 1 : " << at.lireElements_input(0) << endl;

  cout << "Element schema : " << at.getNbElements_output() << endl;
  at.ajouterElements_output("bien");

  cout << "Element schema : " << at.getNbElements_output() << endl;
  cout << "element 1 : " << at.lireElements_output(0) << endl;



  return 0;
}
