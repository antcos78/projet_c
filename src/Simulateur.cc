
#include "../inc/Simulateur.h"
#include "../inc/Schema.h"
#include "../inc/Items.h"



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

void Simulateur::algo_simulation(int numero, Schema sch, Dot d)
{
  char delta_etat;
  string element ;
  for(int i = 0; i < sch.getNbElements_schema()-1;i++ )
  {
    element = sch.lireElements_schema(i);
    if(d.trouverItemsParNom(element)->getType() == 0) //INPUT
    {
        resultat.at(element) = resultat.at(element) + d.trouverItemsParNom(element)->getEtat(0);
    }
    else if(d.trouverItemsParNom(element)->getType() == 1) //OUTPUT
    {
      delta_etat = d.trouverItemsParNom(element)->calculEtat();
    }
    else
    {
      delta_etat = d.trouverItemsParNom(element)->calculEtat();
    }


    if(d.trouverItemsParNom(element)->getType() != 1) //Si pas output
    {
      for(int j = 0; i < d.trouverItemsParNom(element)->getNbOutput(); j++) //Pour chaque sortie
      {
        string sortie = d.trouverItemsParNom(element)->getOutput(j);
        if(d.trouverItemsParNom(sortie)->getNbPorts() == 1)
        {
          d.trouverItemsParNom(sortie)->ajoutEtat(delta_etat, numero);
        }
        else
        {
          if(d.trouverItemsParNom(sortie)->getType() == 5) //MUX
          {

          }
          if(d.trouverItemsParNom(sortie)->getFlag() != 1 )
          {
            d.trouverItemsParNom(sortie)->ajoutEtat( delta_etat,  0);
            d.trouverItemsParNom(sortie)->setFlag(1);
          }
          else
          {
            d.trouverItemsParNom(sortie)->ajoutEtat( delta_etat,  1);
          }
        }
      }
    }


  }
}
