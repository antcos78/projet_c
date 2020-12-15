#ifndef _STIMULI_H_
#define _STIMULI_H_


#include <iostream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <iomanip>

#include <map>
#include <vector>

using namespace std;

class Stimuli{

//  friend ostream& operator<<(ostream& out, const Zoo &z);


private:

  int nbPeriode;
  map<string,string> m_stimuli;
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
    map<string,string>::const_iterator it=m_stimuli.begin();
    return it->second.size();
  }

  int getnbEntree()const
  {
    return m_stimuli.size();
  }


  void parsingStimuli(char *mon_fichier_stimuli);

  void addEntree(const string & nom, const string & etat);

  char recupEntreeParNom(const string & nom, int numero);

  char recupEntreeParNumero(int numeroEntree, int numeroBool);



};


#endif
