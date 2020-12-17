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

  int enter = 0;
  cout << endl << endl << endl << endl;
  cout << "SIMULATEUR D'UN CIRCUIT NUMERIQUE" << endl;
  cout << "Les fichiers acceptés pour le schéma sont au format DOT" << endl;
  cout << "Pour le stimuli, les fichiers sont au format json" << endl;


  //NOM ET EMPLACEMENT DES FICHIERS
  char *mon_fichier_dot = "/home/phelma/Documents/Examen/circuits/full_adder.dot";
  char *mon_fichier_stimuli = "/home/phelma/Documents/Examen/stimuli/full_adder.json";

  char *mon_fichier_de_sorti = "resultat.dot";

  cout << "Début du parsing du .DOT" << endl;
  //PARSING du DOT
  dov.parsingDot(mon_fichier_dot);

  cout << "Début du parsing du stimuli" << endl;
  //PARSING du STIMULI
  sti.parsingStimuli(mon_fichier_stimuli);

  cout << "Reconstruction du schéma" << endl;
  cout << "Eléments du schema dans l'ordre : " << endl << endl;

  //PARSING du SCHEMA
  sch.construction_schema( dov );

  for(int i = 0; i < sch.getNbElements_schema() ; i ++)
  {
    cout << sch.lireElements_schema(i) << endl;
  }

  cout <<endl<<endl<< "Schéma reconstruit" << endl;

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
    cout << "Erreur nombre entrées stimuli et dot" << endl;
    exit(1);
  }


  cout << "Début de la simulation" << endl<< endl;

  //DECLARATION DES ELEMENTS DE SORTIE
  simu.declaration_resultat(sch);
  //CALCUL DU DELTA CYCLE
  simu.calcul_delta_cycle(sti, sch);
  //SIMULATION COMPLETE
  simu.calcul_simulation(sti.getnbPeriode(), sch, dov,sti);

  cout << "La simulation est terminée" << endl<< endl;

  //AFFICHAGE DES ELEMENTS DE SIMULATION
  cout << "Les résultats de la simulation sont disponibles ci-dessous : " << endl;
  for(int j = 0; j < simu.getNbElements_resultat(); j++ )
  {
    cout << "Sortie " << sch.lireElements_output(j) << ": ";
    for(int i = 0; i < sti.getnbPeriode()+1; i++)
    {
      cout<< simu.lireElements_resultat(sch.lireElements_output(j))[i] ;
    }
    cout << endl;

  }

  cout <<endl<<endl<< "Le fichier de sortie va être fabriqué...." << endl;
  //GENERATION DU CHRONOGRAMME DE SORTIE
  wave.generation_Wavedrom( simu, sch, sti,mon_fichier_de_sorti);

  cout << "...le voici livré à l'emplacement voulu sour le nom de : "<< mon_fichier_de_sorti<< endl;


  return 0;
}
