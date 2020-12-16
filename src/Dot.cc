#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

#include "../inc/Items.h"
#include "../inc/Porte.h"
#include "../inc/Not.h"
#include "../inc/And2.h"
#include "../inc/Or2.h"
#include "../inc/Dot.h"
#include "../inc/Input.h"
#include "../inc/Output.h"
#include "../inc/Xnor2.h"
#include "../inc/Xor2.h"
#include "../inc/Nand2.h"
#include "../inc/Nor2.h"
#include "../inc/Mux.h"


Dot::Dot()
{
  cout << "construction du Dot" << endl;
}

void Dot::parsingDot(char *mon_fichier)
{
  char tab[3000];
  char a;
  int i = 0;
  int b;
  int d;
  int q = 0;
  // int e;
  int nbPorts;
  ifstream monFlux(mon_fichier);

  char digraph [14] = {'d','i','g','r','a','p','h',' ','t','e','s','t',' ','{'};
  char label [8] = {'l','a','b','e','l',' ','=',' '};
  char sel [6] = {'s','e','l',' ','=',' '};

  string entree;
  string type;
  string select;
  string porte;


  if (monFlux.is_open()!=true)
  {
    cout << "Problème de fichier" << endl;
    exit(3);
  }
  cout << "Fichier ouvert" << endl;


  while(monFlux.get(a)) //Récupération des données
  {

    tab[i] = a; //On transfère la donnée
    //cout << a << endl; //On affiche chaque caractère
    i++;
  }
  i = 0;

  //i = 0; //Remise à 0 du compteur
  while(tab[i]=='\n'){i++;}
  b = i;
  for(int c = 0;i<b+14;i++,c++)
  {
    if(tab[i]!=digraph[c])
    {
      cout <<" Erreur digraph" << endl; //Si texte différente de digraph test{ alors erreur
      }
    }
    while(tab[i]!='}')
    {
      while(tab[i]=='\n'){i++;}
      while((tab[i]!=' '))
      {

        entree += tab[i];
        if((tab[i]=='[')||(tab[i]=='-'))
        {
          cout << "manque espace après nom" << endl;
          exit(5);
        }
        i++;
      }
      while(tab[i] == ' '){i++;}

      if(tab[i] == '[')
      {
        i++;

        b = i;
        for(int c = 0;i<b+8;i++,c++)
        {
          if(tab[i]!=label[c])
          {
            cout <<" erreur label" << endl;
            exit(4);
          }
        }

        if(tab[i] == 34)
        {
          i++;
          while(tab[i]!=34)
          {
            type += tab[i]; //Récupération du type présent dans label = " "
            if(tab[i] == ']')
            {
              cout << "erreur guillemet de fin" << endl;
              exit(4);
            }
            i++;
          }
          cout << "Entrée : " << entree << ", type : " << type <<endl;
        }
        else
        {
          cout << "erreur guillemet de début" << endl;
          exit(4);
        }
        i++;

        if((type != "INPUT") && (type != "OUTPUT"))
        {
          if(tab[i]!=' ')
          {
            cout << "Erreur : il doit y avoir un espace ou type différent de input/output" << endl;
            exit(1);
          }

          i++;

          if(tab[i]!=']')
          {
            d = i;

            if(tab[i]!=';')
            {
              for(int s = 0;i<d+6;i++,s++)
              {
                if(tab[i]!=sel[s])
                {
                  cout <<" erreur sel mux" << endl;
                  exit(4);
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

          }
        }
        cout << tab[i];

        if(tab[i]!=']')
        {
          cout << "erreur crochet" << endl;
          exit(4);
        }

        i++;

        if(tab[i]!=';')
        {
          cout <<"erreur point virgule" << endl;
          exit(4);
        }
        i++;

        if(tab[i]!='\n')
        {
          cout <<"erreur saut de ligne" << endl;
          exit(4);
        }
        i++;

        // e = i;
        if((type != "NOT") && (type != "INPUT") && (type != "OUTPUT"))
        {
          // for(e = i; tab[e] < type.size(); e++, i++)
          // {
          nbPorts = type[type.size() - 1] - 48;
          cout << "nb de port = " << nbPorts << endl;
          type.erase(type.size() - 1);
          // }
        }

        if(type == "INPUT")
        {
          addItems(entree, new Input(entree, 0, 0));
        }
        else if(type == "OUTPUT")
        {
          addItems(entree, new Output(entree, 1, 1));
        }
        else if(type == "NOT")
        {
          addItems(entree, new Not(entree, 2, 1));
        }
        else if(type == "AND")
        {
          addItems(entree, new And2(entree, 3, nbPorts));
        }
        else if(type == "OR")
        {
          addItems(entree, new Or2(entree, 4, nbPorts));
        }
        else if(type == "NOR")
        {
          addItems(entree, new Nor2(entree, 5, nbPorts));
        }
        else if(type == "XOR")
        {
          addItems(entree, new Xor2(entree, 7, nbPorts));
        }
        else if(type == "XNOR")
        {
          addItems(entree, new Xnor2(entree, 8, nbPorts));
        }
        else if(type == "NAND")
        {
          addItems(entree, new Nand2(entree, 9, nbPorts));
        }
        else if(type == "MUX")
        {
          addItems(entree, new Mux(entree, 10, nbPorts+log2(nbPorts) ));

          if(m.count(entree) > 0){
            if(m.count(select) > 0){
              trouverItemsParNom(select)->ajoutOutput(entree);
              trouverItemsParNom(entree)->setEntreeSel(select,0);
            }
            else
            {
              cout << "erreur nom interconnexion" << endl;
              exit(5);
            }
          }
          else
          {
            cout << "erreur nom interconnexion" << endl;
            exit(5);
          }
        }




        else
        {
          cout << "erreur, porte non existante" << endl;
          exit(4);
        }

        entree.clear();
        type.clear();
        select.clear();

        cout << "Ligne finie" << endl;
        /////CREATION DE L'OBJET//////
      }

      else if(tab[i]=='-')
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
                if(m.count(entree) > 0){
                  if(m.count(porte) > 0){
                    if(trouverItemsParNom(porte)->getType()==0)
                    {
                      cout << "Attention entrée en sortie d'élément" <<endl;
                      exit(4);
                    }
                    if(trouverItemsParNom(porte)->getType()==10)
                    {
                      trouverItemsParNom(porte)->setEntree(entree,0);
                      cout << "entree " << entree << "ajoute a " << porte << endl;
                    }
                    if(trouverItemsParNom(entree)->getType()!=1)
                    {

                      trouverItemsParNom(entree)->ajoutOutput(porte);
                      cout << "entree " << entree << "ajoute a " << porte << endl;

                      entree = porte;
                      porte.clear();
                    }
                    else
                    {
                      cout << "erreur Output en entree" << endl;
                      exit(5);
                    }
                  }
                  else
                  {
                    cout << "erreur nom interconnexion" << endl;
                    exit(5);
                  }
                }
                else
                {
                  cout << "erreur nom interconnexion" << endl;
                  exit(5);
                }
              }


              else
              {
                cout << "manque >" << endl;
                exit(3);
              }

            }
            else if(tab[i]=='>')
            {
              cout << "manque -" << endl;
              exit(10);
            }

          }while((tab[i]!=';')&&(tab[i]!='\n'));
          if(tab[i]=='\n')
          {
            cout << "erreur fin de ligne";
            exit(3);
          }
          cout << "Entrée1 :" << entree << endl;
          cout << " porte : " << porte << endl;

          if(m.count(porte) > 0){

            if(m.count(entree) > 0){
              if(trouverItemsParNom(porte)->getType()==0)
              {
                cout << "attention entrée en sortie d'élément" <<endl;
                exit(4);
              }
              if(trouverItemsParNom(porte)->getType()==10)
              {
                trouverItemsParNom(porte)->setEntree(entree,0);
                cout << "entree " << entree << "ajoute a " << porte << endl;
              }
              if(trouverItemsParNom(entree)->getType()!=1)
              {
                if(m.count(porte) > 0){
                  trouverItemsParNom(entree)->ajoutOutput(porte);
                  entree = porte;
                  porte.clear();
                }
                else
                {
                  cout << "erreur nom interconnexion" << endl;
                  exit(5);
                }
              }
              else
              {
                cout << "erreur Output en entree" << endl;
                exit(5);
              }
            }
            else
            {
              cout << "erreur nom interconnexion" << endl;
              exit(5);
            }
          }
          else
          {
            cout << "erreur nom interconnexion" << endl;
            exit(5);
          }
        }
        else
        {
          cout << "manque >" << endl;
          exit(1);
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
      else
      {
        cout << "manque [ ou -" <<endl;
        exit(5);
      }

      while(tab[i] == '\n')
      {
        i++;
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
