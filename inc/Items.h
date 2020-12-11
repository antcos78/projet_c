#ifndef _ITEMS_H_
#define _ITEMS_H_


#include <iostream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <iomanip>

#include "../inc/Stimuli.h"

using namespace std;

class Items{
private:
  string nom;
  char type;
  char nbPorts;

public:
  //////constructeur-destructeur///////

  Items(const string &nom, char type, char nbPorts);

  virtual ~Items()
  {
    cout << "destruction" << endl;
  }


  //////accesseur//////
  const string & getNom() const;

  const char getType() const;

  const char getNbPorts() const;


  virtual string getOutput(int numero_element) const = 0;

  virtual int getNbOutput() const = 0;

  virtual void ajoutOutput(string output_d) = 0;



  virtual char getEtat(int numero_etat) const =0 ;

  virtual int getNbEtat() const  =0 ;

  virtual void ajoutEtat(char etat, int numero_etat)  =0 ;



  virtual void setFlag(char flag) =0 ;

  virtual char getFlag()const =0 ;

  virtual char calculEtat() {return 0;}


  virtual char calculEtat(Stimuli sti, int numero_periode) {return 0;}



};


#endif
