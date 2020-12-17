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
#include "../inc/Bascule.h"


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
  int nbPorts;


  ifstream monFlux(mon_fichier);


  char digraph [7] = {'d','i','g','r','a','p','h'};
  char label [8] = {'l','a','b','e','l',' ','=',' '};
  char sel [6] = {'s','e','l',' ','=',' '};


  string entree;
  string type;
  string select;
  string porte;

  bool flag = false;



  if (monFlux.is_open()!=true)
  {
    cout << "Problème de fichier" << endl;
    exit(3);
  }
  cout <<endl << endl << "Fichier ouvert" << endl << endl;


  while(monFlux.get(a)) //Récupération des données
  {

    tab[i] = a; //On transfère la donnée
    i++;
  }
  i = 0;

  while(tab[i]=='\n'){i++;}
  b = i;
  for(int c = 0;i<b+7;i++,c++)
  {
    if(tab[i]!=digraph[c])
    {
      cout <<" Erreur digraph" << endl; //Si texte différente de digraph test{ alors erreur
        exit(1);
      }
    }
    while(tab[i]!='{'){i++;}
    i++;
    while(tab[i]!='}')
    {
      while(tab[i]=='\n'){i++;}
      while((tab[i]!=' ')&&(flag == false))
      {

        if((tab[i]=='[')||(tab[i]=='-'))
        {
          flag = true;
          continue;
        }
        else
        {
          entree += tab[i];
        }

        i++;
      }
      flag = false;

      //Crochet
      while(tab[i] == ' '){i++;}
      if(tab[i] == '[')
      {
        i++;

        b = i;
        for(int c = 0;i<b+8;i++,c++)
        {
          if(tab[i]!=label[c])
          {
            cout <<" Erreur label" << endl;
            exit(4);
          }
        }

        //Guillemet
        if(tab[i] == 34)
        {
          i++;
          while(tab[i]!=34)
          {
            type += tab[i]; //Récupération du type présent dans label = " "
            if(tab[i] == ']')
            {
              cout << "Erreur guillemet de fin" << endl;
              exit(4);
            }
            i++;
          }
          cout << "Entrée : " << entree << ", type : " << type <<endl;
        }

        else
        {
          cout << "Erreur guillemet de début" << endl;
          exit(4);
        }
        i++;

        //On enleve les espaces
        while(tab[i]==' ')
        {
          i++;
        }


        if(tab[i]!=']')
        {
          d = i;

          if(tab[i]!=';')
          {
            //Si pas de point virgule, alors c'est qu'il y a un mux
            for(int s = 0;i<d+6;i++,s++)
            {
              if(tab[i]!=sel[s])
              {
                cout <<" Erreur sel mux" << endl;
                exit(4);
              }
            }
            //recupération de l'entrée sel
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
            cout << "Entrée : " << entree << ", type : " << type << ", select :"<< select <<endl;  //On affiche les informations recueillies
          }

        }


        if(tab[i]!=']')
        {
          cout << "Erreur crochet de fin" << endl;
          exit(4);
        }

        i++;

        if(tab[i]!=';')
        {
          cout <<"Erreur point virgule" << endl;
          exit(4);
        }
        i++;

        if(tab[i]!='\n')
        {
          cout <<"Erreur saut de ligne" << endl;
          exit(4);
        }
        i++;

        if(type.size() == 0)
        {
          cout << "Erreur pas de type dans le label" << endl;
          exit(5);
        }

        if((type != "NOT") && (type != "INPUT") && (type != "OUTPUT")&&(type != "FF")) //Pour le choix du nombre de ports, ceux la ne sont pas possibles
        {
          nbPorts = type[type.size() - 1] - 48;
          cout << "Nombre de ports = " << nbPorts << endl;
          type.erase(type.size() - 1);
        }

        //Liste des portes possibles et ajout à la map des objets
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
        else if(type == "FF")
        {
          addItems(entree, new Bascule(entree, 11, 1));
        }
        else if(type == "MUX")
        {
          addItems(entree, new Mux(entree, 10, nbPorts+log2(nbPorts) ));

          if(m.count(entree) > 0){
            if(m.count(select) > 0){
              trouverItemsParNom(select)->ajoutOutput(entree);  //on ajoute le mux comme sortie de l'élément
              trouverItemsParNom(entree)->setEntreeSel(select,0); //on ajoute l'entrée dans le mux
            }
            else
            {
              cout << "Erreur nom interconnexion" << endl;
              exit(5);
            }
          }
          else
          {
            cout << "Erreur nom interconnexion" << endl;
            exit(5);
          }
        }
        else
        {
          cout << "Erreur, porte non existante" << endl;
          exit(4);
        }

        entree.clear();
        type.clear();
        select.clear();

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
                cout << "Entrée :" << entree << endl;
                cout << "Porte : " << porte << endl;
                if(m.count(entree) > 0){
                  if(m.count(porte) > 0){
                    if(trouverItemsParNom(porte)->getType()==0) //Si input
                    {
                      cout << "Attention entrée en sortie d'élément" <<endl;
                      exit(4);
                    }
                    if(trouverItemsParNom(porte)->getType()==10) //Si mux
                    {
                      trouverItemsParNom(porte)->setEntree(entree,0);
                      cout << "Entrée " << entree << " ajouté à " << porte << endl<<endl;
                    }
                    if(trouverItemsParNom(entree)->getType()!=1)  //Autre que output
                    {

                      trouverItemsParNom(entree)->ajoutOutput(porte);
                      cout << "Entrée " << entree << " ajouté à " << porte << endl<<endl;

                      entree = porte;
                      porte.clear();
                    }
                    else  //Si output
                    {
                      cout << "erreur Output en entree" << endl;
                      exit(5);
                    }
                  }
                  else
                  {
                    cout << "Erreur porte non existante 1" << endl;
                    exit(5);
                  }
                }
                else
                {
                  cout << "Erreur porte non existante 2" << endl;
                  exit(5);
                }
              }


              else
              {
                cout << "Manque >" << endl;
                exit(3);
              }

            }
            else if(tab[i]=='>')
            {
              cout << "Manque -" << endl;
              exit(10);
            }

          }while((tab[i]!=';')&&(tab[i]!='\n'));
          if(tab[i]=='\n')
          {
            cout << "Erreur fin de ligne";
            exit(3);
          }
          cout << "Entrée :" << entree << endl;
          cout << "Porte : " << porte << endl;

          if(m.count(porte) > 0){
            if(m.count(entree) > 0){
              if(trouverItemsParNom(porte)->getType()==0)
              {
                cout << "Attention INPUT en sortie d'élément" <<endl;
                exit(4);
              }
              if(trouverItemsParNom(porte)->getType()==10)
              {
                trouverItemsParNom(porte)->setEntree(entree,0);
                cout << "Entrée " << entree << " ajouté à " << porte << endl<<endl;
              }
              if(trouverItemsParNom(entree)->getType()!=1)
              {
                trouverItemsParNom(entree)->ajoutOutput(porte);
                cout << "Entrée " << entree << " ajouté à " << porte << endl<<endl;

                entree = porte;
                porte.clear();

              }
              else
              {
                cout << "Erreur Output en entree" << endl;
                exit(5);
              }
            }
            else
            {
              cout << "Erreur porte non existante 3" << endl;
              exit(5);
            }
          }
          else
          {
            cout << "Erreur porte non existante 4" << endl;
            exit(5);
          }
        }
        else
        {
          cout << "Manque >" << endl;
          exit(1);
        }
        i++;
        if(tab[i]!='\n')
        {
          cout <<"Erreur6" << endl;
        }
        i++;

        entree.clear();
      }
      else
      {
        cout << "Manque [ ou -" <<endl;
        exit(5);
      }

      while(tab[i] == '\n')
      {
        i++;
      }
    }
    cout << "fin du DOT" << endl << endl << endl << endl;
  }



  void Dot::addItems(const string & nom, Items *p_items)
  {
    if(m.count(p_items->getNom()) > 0)  {
      cout << "L'item existe déjà" << endl;
      exit(1);
    }
    m[p_items->getNom()] = p_items;
    v.push_back(p_items->getNom());

    cout << "L'item " << nom << " est ajouté "  << endl <<endl;

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
