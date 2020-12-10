#ifndef _SCHEMA_H_
#define _SCHEMA_H_


#include <iostream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <iomanip>

#include <vector>
#include <list>

#include "Dot.h"

using namespace std;

class Schema{
private:
  list <string> schema;
  vector <string> input;
  vector <string> output;

public:
  //////constructeur-destructeur///////

  Schema()
  {
    cout << "constructeur" << endl;
  }

  ~Schema()
  {
    cout << "destruction" << endl;
  }


  int getNbElements_schema();
  int getNbElements_input();
  int getNbElements_output();

  void ajouterElements_schema(const string & nom);
  void ajouterElements_input(const string & nom);
  void ajouterElements_output(const string & nom);

  string lireElements_schema(int numero);
  string lireElements_output(int numero);
  string lireElements_input(int numero);

  void construction_schema( Dot z );

};


#endif
