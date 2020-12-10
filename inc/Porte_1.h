#ifndef _PORTE_1_H_
#define _PORTE_1_H_


#include <iostream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <iomanip>

#include "Porte.h"



using namespace std;


class Porte_1 : public Porte {

protected:
  bool etat_1;

public:
  //////constructeur-destructeur//////

  Porte_1(const string &nom, char type, char nbPorts,bool etat_1 = 0):
  Porte(nom,type,nbPorts)
  {
    this->etat_1 = etat_1;
  }

  ~Porte_1()
  {
    cout << "destruction" << endl;
  }

  //////accesseur//////

  void setEtat_1(const bool & etat_1);

  bool getEtat_1();


};


#endif
