#ifndef _ITEMS_H_
#define _ITEMS_H_


#include <iostream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <iomanip>


using namespace std;

class Items{
private:
  string nom;
  char type;
  char nbPorts;

public:
  //////constructeur-destructeur///////

  Items(const string &nom, char type, char nbPorts);

  ~Items()
  {
    cout << "destruction" << endl;
  }


  //////accesseur//////
  const string & getNom() const;

  const char getType() const;

  const char getNbPorts() const;



};


#endif
