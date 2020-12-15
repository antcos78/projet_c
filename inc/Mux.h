#ifndef _MUX_H_
#define _MUX_H_


#include <iostream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <iomanip>

#include "Porte.h"

using namespace std;


class Mux : public Porte {
private:
  string entree_sel;

public:
  //////constructeur-destructeur///////
  Mux(const string &nom, char type, char nbPorts,string entree_sel,char flag = 0):
  Porte(nom,type,nbPorts,flag)
  {
    this->entree_sel = entree_sel;
    cout << "constructeur" << endl;
  }


  ~Mux()
  {
    cout << "destruction" << endl;

  }

  ///////méthodes//////
  char calculEtat();

  string getEntreeSel() const{return this->entree_sel;}
  void setEntreeSel(const string & entree_sel){this->entree_sel = entree_sel; }

};


#endif
