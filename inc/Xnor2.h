#ifndef _XNOR2_H_
#define _XNOR2_H_


#include <iostream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <iomanip>

#include "Porte.h"

using namespace std;


class Xnor2 : public Porte {


public:
  //////constructeur-destructeur///////
  Xnor2(const string &nom, char type, char nbPorts,char flag = 0):
  Porte(nom,type,nbPorts,flag)
  {
    cout << "constructeur" << endl;
  }


  ~Xnor2()
  {
    cout << "destruction" << endl;

  }

  ///////méthodes//////
  char calculEtat();


};


#endif
