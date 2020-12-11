#include <iostream>
#include "../inc/Stimuli.h"

#include "../inc/Items.h"
#include "../inc/Porte.h"
#include "../inc/Not.h"
#include "../inc/And2.h"
#include "../inc/Or2.h"
#include "../inc/Schema.h"
#include "../inc/Dot.h"
#include "../inc/Input.h"
#include "../inc/Output.h"

using namespace std;



int main ()
{

  Dot parsingDot;
  Stimuli s;
  Items *input1 = new Input("I1",0,0);
  Items *input2 = new Input("I2",0,0);
  Items *and1 = new And2("AND1",3,2);
  Items *and2 = new And2("AND2",3,2);
  Items *and3 = new And2("AND3",3,2);
  Items *and4 = new And2("AND4",3,2);

  //Items *output1 = new Output("O",1,1);


  input1->ajoutOutput("AND1");
  input1->ajoutOutput("AND3");
  input2->ajoutOutput("AND1");
  input2->ajoutOutput("AND2");

  and1->ajoutOutput("AND2");
  and1->ajoutOutput("AND3");
  and2->ajoutOutput("AND4");
  and3->ajoutOutput("AND4");

  //parsingDot.addItems("O",output1);
  parsingDot.addItems("AND4",and4);
  parsingDot.addItems("I1",input1);
  parsingDot.addItems("AND3",and3);
  parsingDot.addItems("AND2",and2);

  parsingDot.addItems("I2",input2);

  parsingDot.addItems("AND1",and1);
  Schema at;

  at.construction_schema( parsingDot );

  cout << "element ? :" <<at.getNbElements_schema() << endl;
  for(int i = 0; i < at.getNbElements_schema() ; i ++)
  {
    cout << at.lireElements_schema(i) << endl;
  }





/*
Schema at;

  cout << "Element schema : " << at.getNbElements_schema() << endl;
  at.ajouterElements_schema("salut");

  cout << "Element schema : " << at.getNbElements_schema() << endl;
  cout << "element 1 : " << at.lireElements_schema(0) << endl;

  cout << "Element schema : " << at.getNbElements_schema() << endl;
  at.ajouterElements_schema("salut1");

  cout << "Element schema : " << at.getNbElements_schema() << endl;
  cout << "element 1 : " << at.lireElements_schema(1) << endl;




  cout << "Element schema : " << at.getNbElements_input() << endl;
  at.ajouterElements_input("trop");

  cout << "Element schema : " << at.getNbElements_input() << endl;
  cout << "element 1 : " << at.lireElements_input(0) << endl;

  cout << "Element schema : " << at.getNbElements_output() << endl;
  at.ajouterElements_output("bien");

  cout << "Element schema : " << at.getNbElements_output() << endl;
  cout << "element 1 : " << at.lireElements_output(0) << endl;


*/



  return 0;
}
