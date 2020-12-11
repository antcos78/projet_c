
#include "../inc/Simulateur.h"
#include "../inc/Schema.h"



using namespace std;

void Simulateur::declaration_resultat(Schema sch)
{
  int i = 0;
  map<string,string>::iterator it = resultat.begin();
  for(it=resultat.begin(); it!=resultat.end(); ++it)
  {
    resultat[sch.lireElements_output(i)] = "d";
    i++;
  }
}

int Simulateur::getNbElements_resultat()
{
  return resultat.size();
}

void Simulateur::ajouterElements_resultat(const string & nom,char etat)
{
  resultat[nom] = resultat[nom] + etat;
}

string Simulateur::lireElements_resultat(const string & nom)
{
  return resultat[nom];
}

void algo_simulation(int numero, Schema sch, Dot d)
{
  char delta_etat;
  for(int i = 0; i < sch.getNbElements_schema()-1;i++ )
  {
    string element = sch.lireElements_schema(i);
    if(d.trouverItemsParNom(element)->getType() == 0)
    {
        resultat[element] = resultat[element] + d.trouverItemsParNom(element)->getEtat_1();
    }
    else if(d.trouverItemsParNom(element)->getType() == 1)
    {
      deltat_etat = d.trouverItemsParNom(element)->calculEtat();
    }
    else
    {
      deltat_etat = d.trouverItemsParNom(element)->calculEtat();
    }

    for(int j = 0; i < d.trouverItemsParNom(element)->getNbOutput()-1; j++)
    {
      string sortie = d.trouverItemsParNom(element)->getOutput(j);
      if(d.trouverItemsParNom(sortie)->getNbPorts() == 1)
      {
        d.trouverItemsParNom(sortie)->setEtat_1(deltat_etat);
      }
      else
      {
        if()
      }
    }

  }
}
