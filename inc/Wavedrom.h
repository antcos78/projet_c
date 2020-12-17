#ifndef _WAVEDROM_H_
#define _WAVEDROM_H_


#include <iostream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <iomanip>


#include <map>

#include "Schema.h"
#include "Stimuli.h"
#include "Simulateur.h"


using namespace std;

class Wavedrom{
private:

public:
  //////constructeur-destructeur///////

  Wavedrom()
  {
    cout << "constructeur" << endl;
  }

  ~Wavedrom()
  {
    cout << "destruction" << endl;
  }

  //Permet de générer le fichier .json
  void generation_Wavedrom(Simulateur simu, Schema sch, Stimuli stimu);

};


#endif
