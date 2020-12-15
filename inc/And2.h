#ifndef _AN2_H_
#define _AN2_H_


#include <iostream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <iomanip>

#include "Porte.h"

using namespace std;


class And2 : public Porte {


public:
  //////constructeur-destructeur///////
  And2(const string &nom, char type, char nbPorts,char flag = 0):
  Porte(nom,type,nbPorts,flag)
  {
    cout << "constructeur" << endl;
  }


  ~And2()
  {
    cout << "destruction" << endl;

  }

  ///////méthodes//////
  char calculEtat();
  string getEntreeSel() const{cout << "voila";}
  void setEntreeSel(const string & entree_sel) {cout << "voila";}


};


#endif
