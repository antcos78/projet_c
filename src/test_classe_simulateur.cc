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

  string I1 = "I1";
  string I2 = "I2";
  string I3 = "I3";

  string I1_etat = "0011001100110011";
  string I2_etat = "0010101001010001";

  string I3_etat = "0101010101010101";

  s.addEntree(I1, I1_etat);
  s.addEntree(I2, I2_etat);
  s.addEntree(I3, I3_etat);

  parsingDot.parsingDot();

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

  // cout << "element ? :" <<at.getNbElements_schema() << endl;
  // for(int i = 0; i < at.getNbElements_schema() ; i ++)
  // {
  //   cout << at.lireElements_schema(i) << endl;
  // }
*/



  simu.declaration_resultat(at);
  cout << "nb output " << at.getNbElements_output() << endl;
  cout << "nb resultat = " << simu.getNbElements_resultat() << endl;
  cout << "taille " << simu.lireElements_resultat("O").size() << endl;
/*
  simu.ajouterElements_resultat("O",'0');
  simu.ajouterElements_resultat("O",'0');
  simu.ajouterElements_resultat("O",'0');
  simu.ajouterElements_resultat("O",'0');
  simu.ajouterElements_resultat("O",'0');
  simu.ajouterElements_resultat("O",'1');
  simu.ajouterElements_resultat("O",'0');
  simu.ajouterElements_resultat("O",'1');
*/

  cout << "nb resultat = " << simu.getNbElements_resultat() << endl;

  cout << "taille " << simu.lireElements_resultat("O").size() << endl;

  cout <<" resultat   : " << simu.lireElements_resultat("O") << endl;
  simu.calcul_delta_cycle(s, at);

  for(int l = 0; l < s.getnbPeriode(); l++)
  {
    cout << "delta_cycle : " << simu.getDelta_cycle(l) << endl;
  }


  simu.calcul_simulation(s.getnbPeriode(), at, parsingDot, s);



  cout << "nb resultat = " << simu.getNbElements_resultat() << endl;

  cout << "taille " << simu.lireElements_resultat("O").size() << endl;

  cout <<" resultat   : " << simu.lireElements_resultat("O") << endl;

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
