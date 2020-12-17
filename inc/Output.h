#ifndef _OUTPUT_H_
#define _OUTPUT_H_


#include <iostream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <iomanip>

#include "Porte.h"

using namespace std;


class Output : public  Items {

private :
  int a;
  vector <char> etat;
  int flag;


public:
  //////constructeur-destructeur///////
  Output(const string &nom, char type, char nbPorts):
  Items(nom,type,nbPorts)
  {
    etat.push_back(0);
    etat.push_back(0);
    etat.push_back(0);
  }


  ~Output(){;}

  ///////méthodes//////
  char calculEtat();

  //INUTILE
   string getOutput(int numero_element) const{return "0";}
   int getNbOutput() const  {return 0;}
   void ajoutOutput(string output_d) {this->a=0;}

   char getEtat(int numero_etat) const ;
   int getNbEtat() const ;
   void ajoutEtat(char etat, int numero_etat) ;

   void setFlag(char flag) {this->flag = flag;}
   char getFlag()const {return this->flag;}



   virtual bool element_present_entree_sel(string nom) {int a = 0;}
   virtual bool element_present_entree(string nom) {int a = 0;}

   virtual char getEntreeSel_par_nom(string nom) {return 0;}
   virtual char getEntreeSel_par_numero(int numero) {return 0;}

   virtual void setEntreeSel(const string & nom,char etat){int a = 0;}

   virtual char getEntree_par_nom(string nom){return 0;}
   virtual char getEntree_par_numero(int numero) {return 0;}

   virtual void setEntree(const string & nom,char etat){int a = 0;}


};


#endif
