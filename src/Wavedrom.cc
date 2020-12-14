#include <fstream>

#include "../inc/Simulateur.h"
#include "../inc/Schema.h"
#include "../inc/Wavedrom.h"
#include "../inc/Stimuli.h"



using namespace std;


void Wavedrom::generation_Wavedrom(Simulateur simu, Schema sch, Stimuli stimu)
{
  ofstream outfile ("sortie.json");
  char debut [11]= {'{','s','i','g','n','a','l',':',' ','[','\n'};
  char name [7] = {'{','n','a','m','e',':',39};
  char wave [10] = {39,',','w','a','v','e',' ',':',39};
  char fin_ligne[3] = {'}',',','\n'};

  char clk [3] = {'c','l','k'};
  char entree[12] = {'[',39,'E','n','t','r','e','e','s',39,',','\n'};

  outfile.write (debut,11);
  outfile.write (name,7);
  outfile.write (clk,3);
  outfile.write (wave,10);


  char point [30];
  for(int i = 0; i < stimu.getnbPeriode() - 1;i++ )
  {
    point[i] = '.';
  }
  outfile.write (point,stimu.getnbPeriode() -1);

  outfile.write (fin_ligne,3);

  outfile.write (entree,12);
  char name_entree[30];

  for(int i = 0; i < sch.getNbElements_input(); i++)
  {
    outfile.write (name,7);
    for(int j = 0; j < sch.lireElements_input(i).size(); j++)
    {
      name_entree[j] = sch.lireElements_input(i)[j];
    }
    outfile.write(name_entree,sch.lireElements_input(i).size());
    outfile.write (wave,10);
    for(int k = 1; k < stimu.getnbPeriode()+1;k++ )
    {
      point[k] = stimu.recupEntreeParNom(sch.lireElements_input(i),k);
    }
    outfile.write (fin_ligne,3);
  }

  char ligne_milieu1[3] = {']',',','\n'};
  outfile.write (ligne_milieu1,3);
  char ligne_milieu2[4] = {'{','}',',','\n'};
  outfile.write (ligne_milieu2,4);


  for(int i = 0; i < sch.getNbElements_output(); i++)
  {
    outfile.write (name,7);
    for(int j = 0; j < sch.lireElements_output(i).size(); j++)
    {
      name_entree[j] = sch.lireElements_output(i)[j];
    }
    outfile.write(name_entree,sch.lireElements_output(i).size());
    outfile.write (wave,10);
    for(int k = 1; k < stimu.getnbPeriode()+1;k++ )
    {
      point[k] = simu.lireElements_resultat(sch.lireElements_output(i))[k];
    }
    outfile.write (fin_ligne,3);
  }

  // for(int i = 0; i < sch.getNbElements_output();i++)
  // {
  //
  // }
}
