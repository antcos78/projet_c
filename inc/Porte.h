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
  vector <char> etat;
  int flag;

public:
  //////constructeur-destructeur//////

  Porte(const string &nom, char type, char nbPorts, int flag=0):
  Items(nom,type,nbPorts)
  {
    this->flag = flag;
    etat.push_back(0);
    etat.push_back(0);
    etat.push_back(0);
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


  char getEtat(int numero_etat) const;

  int getNbEtat() const;

  void ajoutEtat(char etat, int numero_etat);


  void setFlag(char flag);

  char getFlag()const;



};


#endif
