#ifndef _DOT_H_
#define _DOT_H_


#include <iostream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <iomanip>

#include "../inc/Items.h"

#include <map>
#include <vector>

using namespace std;

class Dot{
private:

  map<string,Items*> m;
  vector<string> v;

public:
  //////constructeur-destructeur///////
  Dot();

  ~Dot(){;}

  int getnbItems()const
  {
    return m.size();
  }


  void parsingDot(char *mon_fichier);  //parsing

  void addItems(const string & nom, Items *p_items);  //Ajoute élément map

  Items * trouverItemsParNom( const string & nom);  //Récupère élement map à l'aide d'un nom

  Items * trouverItemsParNumero(int numero);  //Récupère élement map à l'aide d'un numéro
};


#endif
