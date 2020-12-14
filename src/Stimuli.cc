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
<<<<<<< HEAD
  
  ifstream monFlux("/Users/leomichel/Desktop/Phelma_2A/Projet_info/Projet_C/Inputs.json");
=======
  ifstream monFlux("/home/phelma/Documents/Inputs.json");
>>>>>>> bbada33cd50d989899b7e8941b03ea3a8899f141

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
      cout <<" erreur1" << endl;
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
              cout <<" erreur2" << endl;
            }
          }

          if(tab[i] == 39)
          {
            i++;
            while(tab[i]!=39)
            {

              nom += tab[i]; //Récupération du type présent dans label = " "
              i++;
            }
            cout << "Nom : " << nom << endl;
          }
          i++;

          d = i;
          for(int e = 0;i<d+8;i++,e++)
          {
            if(tab[i]!=wave[e])
            {
              cout <<" erreur3" << endl;
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
              i++;
            }
            cout << "Etat : " << etat << endl;
          }
          i++;
          if(tab[i]!='}')
          {
            cout <<" erreur4" << endl;
          }
          i++;
          if(tab[i] == ',')
          {
            i++;
          }

          cout << tab[i] << endl;
          if(tab[i]!='\n')
          {
            cout <<"erreur6" << endl;
          }
          i++;
          //cout << tab[i] << endl;
          addEntree(nom, etat);

          nom.clear();
          etat.clear();

          cout << "Ligne finie" << endl;
        }
      }

    }
    i++;
  }

  cout << "fin du DOT" << endl;

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
