#ifndef _INPUT_H_
#define _INPUT_H_


#include <iostream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <iomanip>

#include "Porte.h"
#include "Stimuli.h"


using namespace std;


class Input : public  Porte {


public:
  //////constructeur-destructeur///////
  Input(const string &nom, char type, char nbPorts,int flag = 0):
  Porte(nom,type,nbPorts,flag)
  {
    cout << "constructeur" << endl;
  }


  ~Input()
  {
    cout << "destruction" << endl;
  }

  ///////méthodes//////
  char calculEtat(Stimuli sti, int numero_periode);



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
