#ifndef _STIMULI_H_
#define _STIMULI_H_


#include <iostream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <iomanip>

#include "../inc/Items.h"
#include <map>
#include <vector>

using namespace std;

class Stimuli{

//  friend ostream& operator<<(ostream& out, const Zoo &z);


private:

  int nbPeriode;
  map<string,bool[nbPeriode]> m_stimuli;
  vector<string> v_stimuli;

public:
  //////constructeur-destructeur///////
  Stimuli();

  ~Stimuli()
  {
      cout << "Destruction du Stimuli" << endl;
  }

  int getnbPeriode()const
  {
    return stimuli.size();
  }


  void parsingStimuli();

  void addEntree(const string & nom, bool[]);

  bool recupEntreeParNom( const string & nom);

  bool recupEntreeParNumero(int numeroEntree, int numeroBool);



};


#endif
