#ifndef _MUX_H_
#define _MUX_H_


#include <iostream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include <map>
#include <vector>

#include "Porte.h"

using namespace std;


class Mux : public Porte {
private:
  map <string,char> m_entree_sel;
  vector <string> v_entree_sel;
  map <string,char> m_entree;
  vector <string> v_entree;


public:
  //////constructeur-destructeur///////
  Mux(const string &nom, char type, char nbPorts,char flag = 0):
  Porte(nom,type,nbPorts,flag)
  {
    cout << "constructeur" << endl;
  }


  ~Mux()
  {
    cout << "destruction" << endl;

  }

  ///////méthodes//////
  char calculEtat();

  //Récupère présence élément dans les map//
  bool element_present_entree_sel(string nom);
  bool element_present_entree(string nom);

  //Accesseurs entrée sel
  char getEntreeSel_par_nom(string nom) const;
  char getEntreeSel_par_numero(int numero) const;

  //modifieur SEL
  void setEntreeSel(const string & nom,char etat){m_entree_sel[nom] = etat;
                                                  v_entree_sel.push_back(nom);}

  //Accesseurs entrée
  char getEntree_par_nom(string nom) const;
  char getEntree_par_numero(int numero) const;
  //Modifieur entréé
  void setEntree(const string & nom,char etat){m_entree[nom] = etat;
                                                v_entree.push_back(nom);}

};


#endif
