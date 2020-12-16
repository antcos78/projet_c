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
#include "../inc/Wavedrom.h"
#include "../inc/Bascule.h"


using namespace std;



int main ()
{
  Dot dov;
  Simulateur simu;
  Schema sch;
  Wavedrom wave;
  Stimuli sti;



  char *mon_fichier = "/home/phelma/Documents/AND.gv";
  char *mon_fichier_stimuli = "/home/phelma/Documents/Inputs.json";

  dov.parsingDot(mon_fichier);

  sti.parsingStimuli(mon_fichier_stimuli);

  //Ajouter controle taille sti et dot

  sch.construction_schema( dov );
  cout << "schema ok" << endl;
  for(int i = 0; i < sch.getNbElements_schema() ; i ++)
  {
    cout << sch.lireElements_schema(i) << endl;
  }

  simu.declaration_resultat(sch);
  cout << "delcaration ok" << endl;
  simu.calcul_delta_cycle(sti, sch);
  cout << "delta_cycle ok" << endl;
  simu.calcul_simulation(sti.getnbPeriode(), sch, dov,sti);


  for(int j = 0; j < simu.getNbElements_resultat(); j++ )
  {
    cout << " sortie : " << sch.lireElements_output(j) << endl;
    for(int i =0; i < sti.getnbPeriode()+1; i++)
    {
      cout <<" resultat   : " << i << " : " << simu.lireElements_resultat(sch.lireElements_output(j))[i] << endl;
    }
  }

  wave.generation_Wavedrom( simu, sch, sti);

  return 0;
}
