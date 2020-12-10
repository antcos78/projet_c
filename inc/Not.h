#ifndef _NOT_H_
#define _NOT_H_


#include <iostream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <iomanip>

#include "Porte_1.h"

using namespace std;


class Not : public Porte_1 {


public:
  //////constructeur-destructeur///////
  Not(const string &nom, char type, char nbPorts,bool etat_1 = 0):
  Porte_1(nom,type,nbPorts,etat_1)
  {
    cout << "constructeur" << endl;
  }


  ~Not()
  {
    cout << "destruction" << endl;

  }

  ///////méthodes//////
  bool calculEtat();


};


#endif
