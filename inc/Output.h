#ifndef _OUTPUT_H_
#define _OUTPUT_H_


#include <iostream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <iomanip>

#include "Porte.h"

using namespace std;


class Output : public  Items {


public:
  //////constructeur-destructeur///////
  Output(const string &nom, char type, char nbPorts):
  Items(nom,type,nbPorts)
  {
    cout << "constructeur" << endl;
  }


  ~Output()
  {
    cout << "destruction" << endl;

  }

  ///////méthodes//////
  char calculEtat();


};


#endif
