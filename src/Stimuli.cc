#include <iostream>
#include <fstream>

using namespace std;

#include "../inc/stimuli.h"

Stimuli::Stimuli()
{
  cout << "construction du Stimuli" << endl;
}



void Stimuli::addEntree(const string & nom, bool[] etat)
{
  if(m_stimuli.count(nom) > 0)
  {
    cout << "L'entree existe déjà" << endl;
    exit(1);
  }
  m_stimuli[nom] = etat;
  v_stimuli.push_back(etat);

  cout << "l'entrée est ajoutée" << nom << endl;
}

bool Stimuli::recupEntreeParNom( const string & nom)
{
  return m_stimuli[nom];
}

bool Stimuli::recupEntreeParNumero(int numeroEntree, int numeroBool)
{
  return m_stimuli[v_stimuli[numeroEntree]];
  return m_stimuli[v_stimuli[numeroBool]];
}




  // char tab[256];
  // char a;
  // int i = 0;
  // int b;
  // int d;
  // ifstream monFlux("/Users/leomichel/Desktop/Phelma_2A/Projet_info/Projet_C/MUX.gv");
  //
  // char digraph [14] = {'d','i','g','r','a','p','h',' ','t','e','s','t',' ','{'};
  // char label [8] = {'l','a','b','e','l',' ','=',' '};
  // char sel [6] = {'s','e','l',' ','=',' '};
  //
  // string entree;
  // string type;
  // string select;
  // string porte;
  //
  //
  //
  //
  // // while(monFlux.get(a)) //Récupération des données
  // // {
  // //   tab[i] = a; //On transfère la donnée
  // //   cout << a << endl; //On affiche chaque caractère
  // //   i++;
  // // }
  // //
  // // i = 0; //Remise à 0 du compteur
  //
  // for(i=0;i<14;i++)
  // {
  //   if(tab[i]!=digraph[i])
  //   {
  //     cout <<" erreur1" << endl; //Si texte différente de digraph test{ alors erreur
  //   }
  // }
  // while(tab[i]!='}')
  // {
  //     while(tab[i]=='\n'){i++;}
  //     while((tab[i]!='[')&&(tab[i]!='-'))
  //     {
  //       if(tab[i]!=' ')
  //       {
  //         entree += tab[i];
  //       }
  //       i++;
  //     }
  //
  //
  //
  //     if(tab[i] == '[')
  //     {
  //       i++;
  //
  //       b = i;
  //       cout << tab[i];
  //       for(int c = 0;i<b+8;i++,c++)
  //       {
  //         if(tab[i]!=label[c])
  //         {
  //           cout <<" erreur2" << endl;
  //         }
  //       }
  //
  //       if(tab[i] == 34)
  //       {
  //         i++;
  //         while(tab[i]!=34)
  //         {
  //           type += tab[i]; //Récupération du type présent dans label = " "
  //           i++;
  //         }
  //         cout << "Entrée : " << entree << ", type : " << type <<endl;
  //       }
  //       i++;
  //       if(tab[i]!=']')
  //       {
  //         i++;
  //         d = i;
  //         for(int s = 0;i<d+6;i++,s++)
  //         {
  //           if(tab[i]!=sel[s])
  //           {
  //             cout <<" erreur3" << endl;
  //           }
  //         }
  //         if(tab[i] == 34)
  //         {
  //           i++;
  //           while(tab[i]!=34)
  //           {
  //             select += tab[i]; //Récupération du sel présent dans sel = " "
  //             i++;
  //           }
  //
  //         }
  //         i++;
  //         cout << "Entrée : " << entree << ", type : " << type << ", select :"<< select <<endl;
  //       }
  //       i++;
  //
  //       if(tab[i]!=';')
  //       {cout <<"erreur4" << endl;}
  //       i++;
  //
  //       if(tab[i]!='\n')
  //       {cout <<"erreur5" << endl;}
  //       i++;
  //
  //       //cout << "Entrée : " << entree << ", type : " << type << ", select :"<< select <<endl;
  //
  //
  //       /////CREATION DE L'OBJET//////
  //     }
  //
  //
  //
  //     if(tab[i]=='-')
  //     {
  //       i++;
  //
  //       if(tab[i]=='>'){
  //       i++;
  //
  //         while((tab[i]!='-')&&(tab[i]!=';'))
  //         {
  //
  //           if(tab[i]!=' ')
  //           {
  //             porte += tab[i]; //Récupération du nom d'élement
  //
  //           }
  //           //etape de stockage dans element stockage de MY_AND dans I1
  //           //Ajout de MY_AND à la liste "output" de I1
  //           //entree = porte;
  //           cout << "Entrée :" << porte;
  //
  //           i++;
  //           if(tab[i]=='>')
  //           {
  //             i++;
  //           }
  //           i++;
  //           cout << " -> Entrée2 :" << entree << endl;
  //
  //
  //       }
  //         if(tab[i]!='\n')
  //         {
  //           cout <<"erreur6" << endl;
  //         }
  //         i++;
  //     }
  //     i++;
  //
  //     //cout << "Entrée :" << entree << endl;
  //
  //   }
  //
  //
  //   cout << "Ligne finie" << endl;
  //
  // }
  // cout << "fin du DOT" << endl;
  //
  // return 0;