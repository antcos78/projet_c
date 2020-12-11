#ifndef _NOT_H_
#define _NOT_H_


#include <iostream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <iomanip>

#include "Porte.h"

using namespace std;


class Not : public  Porte {


public:
  //////constructeur-destructeur///////
  Not(const string &nom, char type, char nbPorts,int flag = 0):
  Porte(nom,type,nbPorts,flag)
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
