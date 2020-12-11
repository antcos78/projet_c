
#include "../inc/Simulateur.h"
#include "../inc/Schema.h"
#include "../inc/Items.h"



using namespace std;

void Simulateur::declaration_resultat(Schema sch)
{
  int i = 0;
  map<string,string>::iterator it = resultat.begin();
  for(i=0; i < sch.getNbElements_output(); i++)
  {
    resultat[sch.lireElements_output(i)] = "d";
    ++it;
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
  cout << "element schema " <<sch.getNbElements_schema() << endl;
  for(int i = 0; i < sch.getNbElements_schema();i++ )
  {
    element = sch.lireElements_schema(i);
    cout << "type" << d.trouverItemsParNom(element)->getType() +1<< "9" << endl;
    if(d.trouverItemsParNom(element)->getType() == 1) //OUTPUT
    {
        resultat.at(element) = resultat.at(element) + d.trouverItemsParNom(element)->getEtat(0);
    }
    else if(d.trouverItemsParNom(element)->getType() == 0) //INPUT
    {
      delta_etat = d.trouverItemsParNom(element)->calculEtat();
      delta_etat += 1;
    }
    else
    {
      delta_etat = d.trouverItemsParNom(element)->calculEtat();
    }
    cout << "etat" << delta_etat << endl;


    if(d.trouverItemsParNom(element)->getType() != 1) //Si pas output
    {
      cout << "nb output " << d.trouverItemsParNom(element)->getNbOutput();
      for(int j = 0; i < d.trouverItemsParNom(element)->getNbOutput(); j++) //Pour chaque sortie
      {
        string sortie = d.trouverItemsParNom(element)->getOutput(j);
        cout << "sortie : " << sortie << endl;
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

            cout << "tout va bien"  <<endl;
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
