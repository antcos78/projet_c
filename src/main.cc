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


  //NOM ET EMPLACEMENT DES FICHIERS
  char *mon_fichier_dot = "/home/phelma/Documents/Examen/structure_ok/register.dot";
  char *mon_fichier_stimuli = "/home/phelma/Documents/Examen/stimuli/three_inputs.json";

  //PARSING du DOT
  dov.parsingDot(mon_fichier_dot);

  //PARSING du STIMULI
  sti.parsingStimuli(mon_fichier_stimuli);

  //PARSING du SCHEMA
  sch.construction_schema( dov );


  //Verification des données entre Stimuli et DOT
  if(sch.getNbElements_input() == sti.getnbEntree())
  {
    for(int i = 0; i < sch.getNbElements_input(); i++)
    {
      sti.recupEntreeParNom(dov.trouverItemsParNumero(i)->getNom(),0);
    }
  }
  else
  {
    cout << "erreur nombre entree stimuli et dot" << endl;
    exit(1);
  }



  //DECLARATION DES ELEMENTS DE SORTIE
  simu.declaration_resultat(sch);
  //CALCUL DU DELTA CYCLE
  simu.calcul_delta_cycle(sti, sch);
  //SIMULATION COMPLETE
  simu.calcul_simulation(sti.getnbPeriode(), sch, dov,sti);

  //AFFICHAGE DES ELEMENTS DE SIMULATION
  for(int j = 0; j < simu.getNbElements_resultat(); j++ )
  {
    cout << " sortie : " << sch.lireElements_output(j) << endl;
    for(int i = 0; i < sti.getnbPeriode()+1; i++)
    {
      cout <<" resultat   : " << i << " : " << simu.lireElements_resultat(sch.lireElements_output(j))[i] << endl;
    }
  }

  //GENERATION DU CHRONOGRAMME DE SORTIE
  wave.generation_Wavedrom( simu, sch, sti);

  return 0;
}
