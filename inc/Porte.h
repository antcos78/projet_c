#ifndef _PORTE_H_
#define _PORTE_H_


#include <iostream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <iomanip>

#include "Items.h"

#include <vector>


using namespace std;


class Porte :  public Items{

private:
  vector <string> output;

public:
  //////constructeur-destructeur//////

  Porte(const string &nom, char type, char nbPorts):
  Items(nom,type,nbPorts)
  {
    cout << "constructeur" << endl;
  }

  ~Porte()
  {
    cout << "destruction" << endl;
  }

  //////accesseur//////
  string getOutput(int numero_element) const;

  int getNbOutput() const;

  void ajoutOutput(string output_d);




};


#endif
