#ifndef _DOT_H_
#define _DOT_H_


#include <iostream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <iomanip>

#include <map>

using namespace std;

class Dot{

//  friend ostream& operator<<(ostream& out, const Zoo &z);


private:

  map<string,items*> m ;
  vector<string> v;

public:
  //////constructeur-destructeur///////
  Dot();

  virtual ~Dot();

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
