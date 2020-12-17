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
  const string & getNom() const;   //attribut NOM

  const char getType() const;      //attribut type

  const char getNbPorts() const;   //attribut port

  /////OUTPUT/////
  virtual string getOutput(int numero_element) const = 0;
  virtual int getNbOutput() const = 0;
  virtual void ajoutOutput(string output_d) = 0;


  //////INPUT/////
  virtual char getEtat(int numero_etat) const =0 ;
  virtual int getNbEtat() const  = 0 ;
  virtual void ajoutEtat(char etat, int numero_etat)  =0 ;


  //////FLAG/////
  virtual void setFlag(char flag) =0 ;
  virtual char getFlag()const =0 ;

  //////CALCUL ETAT//////
  virtual char calculEtat() {return 0;}
  virtual char calculEtat(Stimuli sti, int numero_periode) {return 0;}


  /////ELEMENT MUX///////
  virtual bool element_present_entree_sel(string nom) = 0;
  virtual bool element_present_entree(string nom) = 0;
  virtual char getEntreeSel_par_nom(string nom) {return 0;}
  virtual char getEntreeSel_par_numero(int numero) {return 0;}
  virtual void setEntreeSel(const string & nom,char etat)=0;
  virtual char getEntree_par_nom(string nom) {return 0;}
  virtual char getEntree_par_numero(int numero) {return 0;}
  virtual void setEntree(const string & nom,char etat)=0;
};


#endif
