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

void Stimuli::parsingStimuli()
{

  char tab[500];
  char a;
  int i = 0;
  int b;
  int d;
  ifstream monFlux("/Users/leomichel/Desktop/Phelma_2A/Projet_info/Projet_C/Inputs.json");

  char signal [10] = {'{','s','i','g','n','a','l',':',' ','['};
  char name [6] = {'n','a','m','e',':',' '};
  char wave [8] = {',',' ','w','a','v','e',':',' '};

  string nom;
  string etat;



  while(monFlux.get(a)) //Récupération des données
  {
    tab[i] = a; //On transfère la donnée
    i++;
  }


  for(i=0;i<10;i++)
  {
    if(tab[i]!=signal[i])
    {
      cout << "Erreur : la première ligne n'est pas bonne" << endl;
      exit(1);
    }
  }
  while(tab[i]!='}')
  {
    while(tab[i]!=']')
    {
      while(tab[i]=='\n')
      {
        i++;
      }

      if(tab[i] != 9)
      {
        i++;

        if(tab[i] == '{')
        {
          i++;

          if(tab[i] == '}')
          {
            continue;
          }

          b = i;
          for(int c = 0;i<b+6;i++,c++)
          {
            if(tab[i]!=name[c])
            {
              cout << "Erreur dans le name " << endl;
              exit(1);
            }
          }

          if(tab[i] == 39)
          {
            i++;
            while(tab[i]!=39)
            {
              nom += tab[i]; //Récupération du type présent dans label = " "
              if(tab[i] == ',')
              {
                cout << "Erreur : il manque l'apostrophe après le nom" << endl;
                exit(1);
              }
              i++;
            }
            cout << "Nom : " << nom << endl;
          }
          else
          {
            cout << "Erreur : il manque l'apostrophe avant le nom" << endl;
            exit(1);
          }
          i++;

          d = i;
          for(int e = 0;i<d+8;i++,e++)
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
            while(tab[i]!=39)
            {
              if(tab[i] == 46)
              {
                tab[i] = tab[i-1];
              }

              etat += tab[i]; //Récupération du type présent dans label = " "
              if(tab[i] == '}')
              {
                cout << "Erreur : il manque l'apostrophe après l'état" << endl;
                exit(1);
              }
              i++;
            }
            cout << "Etat : " << etat << endl;
          }
          else
          {
            cout << "Erreur : il manque l'apostrophe avant l'état" << endl;
            exit(1);
          }
          i++;
          if(tab[i]!='}')
          {
            cout << "Erreur : il manque l'accolade de fin" << endl;
            exit(1);
          }
          i++;
          if(tab[i] == ',')
          {
            i++;
          }
          else
          {
            cout << "Erreur : il manque la virgule de fin" << endl;
            exit(1);
          }
          i++;
          // cout << tab[i] << endl;
          // if(tab[i]!='\n')
          // {
          //   cout <<"Erreur : Il n'y a pas de saut de ligne" << endl;
          //   exit(1);
          // }
          // i++;
          //cout << tab[i] << endl;
          addEntree(nom, etat);

          nom.clear();
          etat.clear();

          cout << "Ligne finie" << endl;
        }

        // else
        // {
        //   cout << "Erreur : La ligne doit commencer par une accolade" << endl;
        //   exit(1);
        // }

        // if(tab[i]!='\n')
        // {
        //   cout << "Erreur : La ligne doit commencer par une accolade" << endl;
        //   exit(1);
        // }
      }

    }
    i++;
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
  //   // for (map<string,string>::const_iterator it =  m_stimuli.find(nom); it!=m_stimuli.end(); ++it)
  //   // {
  //   //   return it->second;
  //   // }
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

  // i = 0;
  // for(string::iterator iter=m_stimuli[nom].begin(); m_stimuli[nom]<getNbElements_input(); ++iter)
  // {
  //   if(i == nom)
  //   {
  //     continue;
  //   }
  //   else
  //   {
  //     return lireElements_input();
  //   }
  // }

}

char Stimuli::recupEntreeParNumero(int numeroEntree, int numeroBool)
{
  if(numeroEntree >= m_stimuli.size())
  {
    cout << "Le numéro n'existe pas" << endl;
    exit(1);
  }

  string nom = v_stimuli[numeroEntree];
  //cout << nom;


  map<string,string>::const_iterator it =  m_stimuli.find(nom);
  if(it == m_stimuli.end()) {
    return 0;
  }

  int i = 0;
  for (string::iterator itr=m_stimuli[nom].begin(); itr!=m_stimuli[nom].end(); ++itr)
  {
    //cout << i;
    if(i==numeroBool)
    {
      return *itr;
    }

    i++;
  }

}
