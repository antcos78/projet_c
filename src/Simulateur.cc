
#include "../inc/Simulateur.h"
#include "../inc/Schema.h"



using namespace std;

void Simulateur::declaration_resultat(Schema sch)
{
  int i = 0;
  map<string,string>::iterator it = sch.begin();
  for(it=sch.begin(); it!=sch.end(); ++it)
  {
    resultat.insert (it, pair<string,string>(sch.lireElements_output(),"d");
    i++;
  }
}

int Simulateur::getNbElements_resultat()
{
  return resultat.size();
}

void Simulateur::ajouterElements_resultat(const string & nom,bool etat)
{
  resultat[nom] = resultat[nom] + etat;
}

string Simulateur::lireElements_resultat(const string & nom)
{
  return resultat[nom];
}
