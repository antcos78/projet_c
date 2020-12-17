#ifndef _BASCULE_H_
#define _BASCULE_H_


#include <iostream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <iomanip>

#include "Porte.h"
#include "Stimuli.h"


using namespace std;


class Bascule : public  Porte {
private:
  char etat;

public:
  //////constructeur-destructeur///////
  Bascule(const string &nom, char type, char nbPorts,int flag = 0):
  Porte(nom,type,nbPorts,flag){;}


  ~Bascule(){;}
  ///////méthodes//////
  char calculEtat();


  //inutile
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
