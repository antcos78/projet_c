#ifndef _SIMULATEUR_H_
#define _SIMULATEUR_H_


#include <iostream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <iomanip>


#include <map>
#include <vector>


#include "Schema.h"
#include "Stimuli.h"


using namespace std;

class Simulateur{
private:
  map <string,string> resultat;
  vector <char> delta_cycle;

public:
  //////constructeur-destructeur///////

  Simulateur()
  {
    cout << "constructeur" << endl;
  }

  ~Simulateur()
  {
    cout << "destruction" << endl;
  }

  void declaration_resultat( Schema sch);


  int getNbElements_resultat();

  void ajouterElements_resultat(const string & nom,char etat);

  string lireElements_resultat(const string & nom);



  void calcul_simulation(int nb_periode, Schema sch, Dot d, Stimuli sti);

  void algo_simulation(int numero, Schema sch, Dot d, Stimuli sti);


  void calcul_delta_cycle(Stimuli sti, Schema sch);
  char getDelta_cycle(int periode);
  void setDelta_cycle(char value);

};


#endif
