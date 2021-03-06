#include <fstream>

#include "../inc/Simulateur.h"
#include "../inc/Schema.h"
#include "../inc/Wavedrom.h"
#include "../inc/Stimuli.h"



using namespace std;


void Wavedrom::generation_Wavedrom(Simulateur simu, Schema sch, Stimuli stimu, char *mon_fichier)
{
  ofstream outfile (mon_fichier);
  char debut [11]= {'{','s','i','g','n','a','l',':',' ','[','\n'};
  char name [7] = {'{','n','a','m','e',':',39};
  char wave [9] = {39,',','w','a','v','e',' ',':',39};
  char fin_ligne[4] = {39,'}',',','\n'};

  char clk [3] = {'c','l','k'};
  char entree[12] = {'[',39,'E','n','t','r','e','e','s',39,',','\n'};
  char sortie[12] = {'[',39,'S','o','r','t','i','e','s',39,',','\n'};

  char point [30];
  char ligne_milieu1[3] = {']',',','\n'};
  char ligne_milieu2[4] = {'{','}',',','\n'};

  //Début du document//
  outfile.write (debut,11);
  outfile.write (name,7);
  outfile.write (clk,3);
  outfile.write (wave,9);

  //clock
  point[0] = 'p';
  for(int i = 1; i < stimu.getnbPeriode() ;i++ )
  {
    point[i] = '.';
  }
  outfile.write (point,stimu.getnbPeriode());

  outfile.write (fin_ligne,4);

  outfile.write (entree,12);
  char name_entree[30];
  char element_k;
  char element;


  /////ENTREES////
  for(int i = 0; i < sch.getNbElements_input(); i++)
  {
    outfile.write (name,7);
    element_k=2;
    for(int j = 0; j < sch.lireElements_input(i).size(); j++)
    {
      name_entree[j] = sch.lireElements_input(i)[j];
    }
    outfile.write(name_entree,sch.lireElements_input(i).size());
    outfile.write (wave,9);
    for(int k = 0; k < stimu.getnbPeriode();k++)
    {
      element = stimu.recupEntreeParNom(sch.lireElements_input(i),k);
      if(( element == element_k)||(point[k-1]==element))
      {
        point[k]='.';
        element_k = element;
      }
      else
      {
        point[k] = element;
        element_k = 2;

      }

    }
    outfile.write (point,stimu.getnbPeriode());
    outfile.write (fin_ligne,4);
  }

  /////SEPARATION/////
  outfile.write (ligne_milieu1,3);
  outfile.write (ligne_milieu2,4);

  //AFFICHE SORTIE//
  outfile.write (sortie,12);


  //SORTIE///
  for(int i = 0; i < sch.getNbElements_output(); i++)
  {
    element_k=2;
    outfile.write (name,7);
    for(int j = 0; j < sch.lireElements_output(i).size(); j++)
    {
      name_entree[j] = sch.lireElements_output(i)[j];
    }
    outfile.write(name_entree,sch.lireElements_output(i).size());
    outfile.write (wave,9);

    for(int k = 1; k < stimu.getnbPeriode()+1;k++ )
    {
      element = simu.lireElements_resultat(sch.lireElements_output(i)).at(k);
      if(( element == element_k)||(point[k-2]==element))
      {
        point[k-1] = '.';
        element_k = element;
      }
      else
      {
        point[k-1] = element;
        element_k = 2;
      }
    }
    outfile.write (point,stimu.getnbPeriode());
    outfile.write (fin_ligne,4);
  }

  //FIN DE FICHIER///
  outfile.write (ligne_milieu1,3);
  char fin_fichier[2] = {']','}'};
  outfile.write (fin_fichier,2);
}
