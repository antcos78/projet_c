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
public:
  //////constructeur-destructeur///////
  Output(const string &nom, char type, char nbPorts):
  Items(nom,type,nbPorts)
  {
    cout << "constructeur" << endl;
  }


  ~Output()
  {
    cout << "destruction" << endl;

  }

  ///////méthodes//////
  char calculEtat();




   string getOutput(int numero_element) const{return "0";}

   int getNbOutput() const  {return 0;}

   void ajoutOutput(string output_d) {this->a=0;}



   char getEtat(int numero_etat) const {return 0;}

   int getNbEtat() const {return 0;}

   void ajoutEtat(char etat, int numero_etat)  {this->a=0;}



   void setFlag(char flag) {this->a=0;}

   char getFlag()const {return 0;}



};


#endif
