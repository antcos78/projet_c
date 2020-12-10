#ifndef _SCHEMA_H_
#define _SCHEMA_H_


#include <iostream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <iomanip>


#include <map>

#include "Schema.h"


using namespace std;

class Simulateur{
private:
  map <string,string> resultat;

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


  void calcul_simulation();

  void algo_simulation(int numero);

};


#endif
