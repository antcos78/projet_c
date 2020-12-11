#include <iostream>
#include <fstream>

using namespace std;

#include "../inc/Items.h"
#include "../inc/Porte.h"
#include "../inc/Not.h"
#include "../inc/And2.h"
#include "../inc/Or2.h"
#include "../inc/Dot.h"
#include "../inc/Input.h"
#include "../inc/Output.h"

#define INPUT 0
#define OUTPUT 1
#define NOT 2
#define AND2 3
#define OR2 4
#define MUX 5


Dot::Dot()
{
  cout << "construction du Dot" << endl;
}

void Dot::parsingDot()
{
  char tab[500];
  char a;
  int i = 0;
  int b;
  int d;
  ifstream monFlux("/home/phelma/Documents/AND.gv");

  char digraph [14] = {'d','i','g','r','a','p','h',' ','t','e','s','t',' ','{'};
  char label [8] = {'l','a','b','e','l',' ','=',' '};
  char sel [6] = {'s','e','l',' ','=',' '};

  string entree;
  string type;
  string select;
  string porte;




  while(monFlux.get(a)) //Récupération des données
  {
    tab[i] = a; //On transfère la donnée
    //cout << a << endl; //On affiche chaque caractère
    i++;
  }

  //i = 0; //Remise à 0 du compteur
  cout << "salut" << endl;

  for(i=0;i<14;i++)
  {
    if(tab[i]!=digraph[i])
    {
      cout <<" erreur1" << endl; //Si texte différente de digraph test{ alors erreur
      }
    }
    while(tab[i]!='}')
    {
      while(tab[i]=='\n'){i++;}
      while((tab[i]!='[')&&(tab[i]!='-'))
      {
        if(tab[i]!=' ')
        {
          entree += tab[i];
        }
        i++;
      }

      if(tab[i] == '[')
      {
        i++;

        b = i;
        for(int c = 0;i<b+8;i++,c++)
        {
          if(tab[i]!=label[c])
          {
            cout <<" erreur2" << endl;
          }
        }

        if(tab[i] == 34)
        {
          i++;
          while(tab[i]!=34)
          {
            type += tab[i]; //Récupération du type présent dans label = " "
            i++;
          }
          cout << "Entrée : " << entree << ", type : " << type <<endl;
        }

        i++;
        if(tab[i]!=']')
        {
          i++;
          d = i;
          for(int s = 0;i<d+6;i++,s++)
          {
            if(tab[i]!=sel[s])
            {
              cout <<" erreur3" << endl;
            }
          }
          if(tab[i] == 34)
          {
            i++;
            while(tab[i]!=34)
            {
              select += tab[i]; //Récupération du sel présent dans sel = " "
              i++;
            }

          }
          i++;
          cout << "Entrée : " << entree << ", type : " << type << ", select :"<< select <<endl;
        }
        i++;

        if(tab[i]!=';')
        {cout <<"erreur4" << endl;}
        i++;

        if(tab[i]!='\n')
        {cout <<"erreur5" << endl;}
        i++;

        //cout << "Entrée : " << entree << ", type : " << type << ", select :"<< select <<endl;

        if(type == "INPUT")
        {
          addItems(entree, new Input(entree, 0, 0));
        }
        if(type == "OUTPUT")
        {
           addItems(entree, new Output(entree, 1, 1));
        }
        if(type == "NOT")
        {
          addItems(entree, new Not(entree, 2, 1));
        }
        if(type == "AND2")
        {
          addItems(entree, new And2(entree, 3, 2));
        }
        if(type == "OR2")
        {
          addItems(entree, new Or2(entree, 4, 2));
        }
        // if(type == "MUX")
        // {
        //   addItems(entree, new Mux(entree, 5, 2));
        //AJOUTER ENTREE SEL
        // }

        entree.clear();
        type.clear();

        cout << "Ligne finie" << endl;
        /////CREATION DE L'OBJET//////
      }


      if(tab[i]=='-')
      {
        i++;
        if(tab[i]=='>')
        {
          i++;

          do{
            if(tab[i] != ' ')
            {
              porte += tab[i]; //Récupération du nom d'élement
            }
            i++;
            if(tab[i]=='-')
            {
              i++;
              if(tab[i]=='>')
              {
                i++;
                cout << "Entrée1 :" << entree << endl;
                cout << " porte : " << porte << endl;
                cout << "taille " << entree.size() << endl;
                trouverItemsParNom(entree)->ajoutOutput(porte);

                entree = porte;
                porte.clear();
              }
            }

          }while(tab[i]!=';');
          cout << "Entrée1 :" << entree << endl;
          cout << " porte : " << porte << endl;
          cout << "taille " << entree.size() << endl;
          trouverItemsParNom(entree)->ajoutOutput(porte);
          entree = porte;
          porte.clear();

        }
        i++;
        if(tab[i]!='\n')
        {
          cout <<"erreur6" << endl;
        }
        i++;

        entree.clear();
        cout << "Ligne finie" << endl;
      }
    }
    cout << "fin du DOT" << endl;
  }


  //addItems(porte, Not(porte,0,1))

  void Dot::addItems(const string & nom, Items *p_items)
  {
    if(m.count(p_items->getNom()) > 0)  {
      cout << "L'item existe déjà" << endl;
      exit(1);
    }
    m[p_items->getNom()] = p_items;
    v.push_back(p_items->getNom());

    cout << "l'item est ajouté" << p_items->getNom() << endl;

  }

  Items * Dot::trouverItemsParNom( const string & nom)
  {
    if(m.count(nom) > 0)  {
      return m[nom];
    }
  }

  Items * Dot::trouverItemsParNumero(int numero)
  {
    return m[v[numero]];
  }
