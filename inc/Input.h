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
  string getEntreeSel() const{cout << "voila";}
  void setEntreeSel(const string & entree_sel) {cout << "voila";}


};


#endif
