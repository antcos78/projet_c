#ifndef _PORTE_2_H_
#define _PORTE_2_H_


#include <iostream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <iomanip>

#include "Porte.h"



using namespace std;


class Porte_2 : public Porte {

protected:
  bool etat_1;
  bool etat_2;
  char flag;

public:
  //////constructeur-destructeur//////

  Porte_2(const string &nom, char type, char nbPorts,bool etat_1 = 0, bool etat_2 = 0, char flag = 0):
  Porte(nom,type,nbPorts)
  {
    this->etat_1 = etat_1;
    this->etat_2 = etat_2;
    this->flag = flag;
  }

  ~Porte_2()
  {
    cout << "destruction" << endl;
  }

  //////accesseur//////

  void setEtat_1(bool etat_1);

  bool getEtat_1();

  void setEtat_2(bool etat_2);

  bool getEtat_2();

  void setFlag(char flag);

  char getFlag()const;

};


#endif
