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
#include "Items.h"
#include "Porte.h"


using namespace std;

class Schema{
private:
  list <string> schema;
  vector <string> input;
  vector <string> output;
  vector <string> bascule;

public:
  //////constructeur-destructeur///////

  Schema(){;}

  ~Schema(){;}


  int getNbElements_schema();
  int getNbElements_input();
  int getNbElements_output();
  int getNbElements_bascule();


  void ajouterElements_schema(const string & nom);
  void ajouterElements_input(const string & nom);
  void ajouterElements_output(const string & nom);
  void ajouterElements_bascule(const string & nom);

  string lireElements_schema(int numero);
  string lireElements_output(int numero);
  string lireElements_input(int numero);
  string lireElements_bascule(int numero);

  void construction_schema( Dot z );

};


#endif
