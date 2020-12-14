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
#include "../inc/Simulateur.h"


using namespace std;



int main ()
{

  Dot parsingDot;
  Stimuli s;


  parsingDot.parsingDot();

  s.parsingStimuli();

  Schema at;

  at.construction_schema( parsingDot );

  Simulateur simu;


/*
  cout << "element ? :" <<at.getNbElements_schema() << endl;
  for(int i = 0; i < at.getNbElements_schema() ; i ++)
  {
    cout << at.lireElements_schema(i) << endl;
  }
    cout << "nom " << at.lireElements_schema(0);
    cout << "type" <<  parsingDot.trouverItemsParNom(at.lireElements_schema(0));

  simu.algo_simulation(0, at, parsingDot);


  cout << "resultat : " << simu.lireElements_resultat("O");
*/
  cout << "element ? :" <<at.getNbElements_schema() << endl;
  for(int i = 0; i < at.getNbElements_schema() ; i ++)
  {
    cout << at.lireElements_schema(i) << endl;
  }




  simu.declaration_resultat(at);
  cout << "nb output " << at.getNbElements_output() << endl;
  cout << "nb resultat = " << simu.getNbElements_resultat() << endl;
  //cout << "taille " << simu.lireElements_resultat("O").size() << endl;


  cout << "nb resultat = " << simu.getNbElements_resultat() << endl;

//  cout << "taille " << simu.lireElements_resultat("O").size() << endl;

  //cout <<" resultat   : " << simu.lireElements_resultat("O") << endl;
  simu.calcul_delta_cycle(s, at);

  for(int l = 0; l < s.getnbPeriode(); l++)
  {
    cout << "delta_cycle : " << simu.getDelta_cycle(l) << endl;
  }


  simu.calcul_simulation(s.getnbPeriode(), at, parsingDot, s);


  cout << "nb output : " << at.getNbElements_output()<<endl;

  cout << "nb resultat = " << simu.getNbElements_resultat() << endl;

//  cout << "taille " << simu.lireElements_resultat("O").size() << endl;

  //cout <<" resultat   : " << simu.lireElements_resultat("O") << endl;

  for(int j = 0; j < simu.getNbElements_resultat(); j++ )
  {
    cout << " sortie : " << at.lireElements_output(j) << endl;
    for(int i =0; i < s.getnbPeriode()+1; i++)
    {
      cout <<" resultat   : " << i << " : " << simu.lireElements_resultat(at.lireElements_output(j))[i] << endl;
    }
  }



  return 0;
}
