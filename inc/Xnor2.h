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
  Porte(nom,type,nbPorts,flag){;}

  ~Xnor2(){;}

  ///////méthodes//////
  char calculEtat();

  //Inutile
  virtual bool element_present_entree_sel(string nom) {int a = 0;}
  virtual bool element_present_entree(string nom) {int a = 0;}

  virtual char getEntreeSel_par_nom(string nom) {return 0;}
  virtual char getEntreeSel_par_numero(int numero) {return 0;}

  virtual void setEntreeSel(const string & nom,char etat){int a = 0;}

  virtual char getEntree_par_nom(string nom){return 0;}
  virtual char getEntree_par_numero(int numero) {return 0;}

  virtual void setEntree(const string & nom,char etat){int a = 0;}

};


#endif
