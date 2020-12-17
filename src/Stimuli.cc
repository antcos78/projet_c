#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "../inc/Items.h"
#include "../inc/Porte.h"
#include "../inc/Not.h"
#include "../inc/And2.h"
#include "../inc/Or2.h"
#include "../inc/Stimuli.h"
#include "../inc/Input.h"
#include "../inc/Output.h"
#include "../inc/Schema.h"

Stimuli::Stimuli()
{
  cout << "construction du Stimuli" << endl;
}

void Stimuli::parsingStimuli(char *mon_fichier_stimuli)
{

  char tab[3000];
  char a;
  int i = 0;
  int b;
  int d;
  int f;
  int periode;
  int line = 0;
  int flag;
  ifstream monFlux(mon_fichier_stimuli);

  char signal [10] = {'{','s','i','g','n','a','l',':',' ','['};
  char name [5] = {'n','a','m','e',':'};
  char wave [6] = {'w','a','v','e',':',' '};

  string nom;
  string etat;

  if (monFlux.is_open()!=true) //Vérification si le fichier est bien ouvert
  {
    cout << "Problème de fichier" << endl;
    exit(3);
  }
  cout << "Fichier ouvert" << endl;


  while(monFlux.get(a)) //Récupération des données
  {
    tab[i] = a; //On transfère la donnée
    i++;
  }

  // Vérification de la première ligne
  for(i=0;i<10;i++)
  {
    if(tab[i]!=signal[i])
    {
      cout << "Erreur : la première ligne n'est pas bonne" << endl;
      exit(1);
    }
  }


  while(tab[i]!='}') //Permet de parcourir le fichier jusqu'à la fin
  {
    while(tab[i]!=']')
    {
      while(tab[i]=='\n')
      {
        i++;
      }

      //Récupération des élements d'entrées
      while(tab[i] != '{')
      {
        i++;
        if(tab[i] == ']')
        {
          cout << "Erreur pour le crochet de fin" << endl;
          exit(1);
        }
        if(tab[i]=='n')
        {
          cout << "Erreur : manque accolade de début" << endl;
          exit(1);
        }
      }

        if(tab[i] == '{')
        {
          i++;

          if(tab[i] == ' ')
          {
            cout << "Espace en trop après l'accolade de début de ligne" << endl;
            exit(1);
          }

          if(tab[i] == '}')
          {
            continue;
          }

          b = i;
          for(int c = 0;i<b+5;i++,c++)
          {
            if(tab[i]!=name[c]) //Vérification de la forme avant de récupérérer le nom de l'entrée
            {
              cout << "Erreur dans le name " << endl;
              exit(1);
            }
          }

          while(tab[i]==' ')
          {
            i++;
          }

          //Récupération du nom de l'entrée
          if(tab[i] == 39)
          {
            i++;
            while(tab[i]!=39)
            {
              nom += tab[i];
              if(tab[i] == ',')
              {
                cout << "Erreur sur l'apostrophe après le nom" << endl;
                exit(1);
              }
              i++;
            }
            cout << "Nom : " << nom << endl;
          }
          else
          {
            cout << "Erreur pour l'apostrophe avant le nom" << endl;
            exit(1);
          }
          i++;
          if(tab[i]!=',')
          {
            cout << "Erreur il doit y avoir une virgule" << endl;
            exit(1);
          }
          i++;
          if(nom.size() == 0)
          {
            cout <<"pas de nom d'entrée" << endl;
            exit(5);
          }
          while(tab[i]==' ')
          {
            i++;
          }

          //Récupération de l'état de l'entrée
          d = i;
          for(int e = 0;i<d+6;i++,e++)
          {
            if(tab[i]!=wave[e])
            {
              cout << "Erreur dans le wave" << endl;
              exit(1);
            }
          }
          if(tab[i] == 39)
          {
            i++;
            f = i;
            while(tab[i]!=39)
            {
              if(tab[f] == 46)
              {
                cout << "Erreur : premier état est un point" << endl;
                exit(1);
              }

              if(tab[i] == 46) // Quand l'état est un point alors il prend la valeur du bit précédent
              {
                tab[i] = tab[i-1];
              }

              etat += tab[i];
              if(tab[i] == '}')
              {
                cout << "Erreur : il manque l'apostrophe après l'état" << endl;
                exit(1);
              }
              if((tab[i]!='0')&&(tab[i]!='1')&&(tab[i]!='.')) //Prise en compte si l'état n'est ni un 1, ni un 0, ni un point
              {
                cout << "Erreur dans les valeurs d'état" << endl;
                exit(1);
              }
              i++;
            }
            cout << "Etat : " << etat << endl;
          }
          else
          {
            cout << "Erreur avant l'apostrophe avant l'état" << endl;
            exit(1);
          }
          if(etat.size() == 0)
          {
            cout << "pas d'état" << endl;
            exit(5);
          }
          if(line == 0) //Vérification si les états ont tous le même nombre de période
          {
            periode = etat.size();
          }
          else if(line != 0)
          {
            if(periode != etat.size())
            {
              cout << "Erreur : nb période différent" << endl;
              exit(1);
            }
          }
          line ++;

          i++;
          if(tab[i] == ' ')
          {
            cout << "Espace en trop avant l'accolade de fin" << endl;
            exit(1);
          }
          if(tab[i]!='}')
          {
            cout << "Erreur à l'accolade de fin" << endl;
            exit(1);
          }
          i++;
          if(tab[i] == ' ')
          {
            cout << "Espace en trop avant la virgule" << endl;
            exit(1);
          }

          if((tab[i]!=',')&&((tab[i+1] != ']')&&(tab[i+1] != '}')))
          {
            cout << "Erreur : il doit y avoir une virgule" << endl;
            exit(1);
          }
          else if(tab[i]==',')
          {
            i++;
          }

          if(tab[i]!='\n')
          {
            cout << "Erreur après la fin de ligne" << endl;
            exit(1);
          }

          i++;


          addEntree(nom, etat); //On associe l'état à son entrée correspondante

          nom.clear();
          etat.clear();

          cout << "Ligne finie" << endl;
        }
        else
        {
          cout << "Manque accolade de début" << endl;
          exit (4);
        }
        if(tab[i]=='\n')
        {
          i++;
        }
    }
    i++;

    if(tab[i]!='}')
    {
      cout << "Erreur avant l'accolade de fin de programme" << endl;
      exit(1);
    }
  }

  cout << "fin du Stimuli" << endl;

}

void Stimuli::addEntree(const string & nom, const string & etat)
{
  if(m_stimuli.count(nom) > 0)
  {
    cout << "L'entree existe déjà" << endl;
    exit(1);
  }

  m_stimuli[nom] = etat;

  v_stimuli.push_back(nom);

  cout << "l'entrée est ajoutée" << nom << endl;
}

char Stimuli::recupEntreeParNom(const string & nom, int numero)
{

  if(m_stimuli.count(nom) == 0)
  {
    cout << "L'entrée n'existe pas" << endl;
    exit(1);
  }

  map<string,string>::const_iterator it =  m_stimuli.find(nom);
  if(it == m_stimuli.end()) {
    return 0;
  }

  int i = 0;
  for (string::iterator itr=m_stimuli[nom].begin(); itr!=m_stimuli[nom].end(); ++itr)
  {
    if(i==numero)
    {
      return *itr;
    }

    i++;
  }
}

char Stimuli::recupEntreeParNumero(int numeroEntree, int numeroBool)
{
  if(numeroEntree >= m_stimuli.size())
  {
    cout << "Le numéro n'existe pas" << endl;
    exit(1);
  }

  string nom = v_stimuli[numeroEntree];

  map<string,string>::const_iterator it =  m_stimuli.find(nom);
  if(it == m_stimuli.end()) {
    return 0;
  }

  int i = 0;
  for (string::iterator itr=m_stimuli[nom].begin(); itr!=m_stimuli[nom].end(); ++itr)
  {
    if(i==numeroBool)
    {
      return *itr;
    }

    i++;
  }

}
