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

//  friend ostream& operator<<(ostream& out, const Zoo &z);


private:

  map<string,Items*> m;
  vector<string> v;

public:
  //////constructeur-destructeur///////
  Dot();

  ~Dot()
  {
      cout << "Destruction du Dot" << endl;
  }

  int getnbItems()const
  {
    return m.size();
  }


  void parsingDot();

  void addItems(const string & nom, Items *p_items);

  Items * trouverItemsParNom( const string & nom);

  Items * trouverItemsParNumero(int numero);



};


#endif
