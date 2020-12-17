
#include "../inc/Simulateur.h"
#include "../inc/Schema.h"
#include "../inc/Items.h"
#include "../inc/Stimuli.h"



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






void Simulateur::algo_simulation(int numero, Schema sch, Dot d, Stimuli sti)
{
  char delta_etat;
  string element ;
  for(int i = 0; i < sch.getNbElements_schema();i++ )
  {
    element = sch.lireElements_schema(i);
    if(d.trouverItemsParNom(element)->getType() == 1) //OUTPUT
    {
      char etat_actuel = d.trouverItemsParNom(element)->getEtat(0) + 48;
      resultat.at(element) = resultat.at(element) + etat_actuel;
    }
    else if(d.trouverItemsParNom(element)->getType() == 0) //INPUT
    {
      delta_etat = d.trouverItemsParNom(element)->calculEtat(sti, numero);
    }
    else
    {
      delta_etat = d.trouverItemsParNom(element)->calculEtat();
      d.trouverItemsParNom(element)->setFlag(0);
    }


    if(d.trouverItemsParNom(element)->getType() != 1) //Si pas output
    {
      for(int j = 0; j < d.trouverItemsParNom(element)->getNbOutput(); j++) //Pour chaque sortie
      {
        string sortie = d.trouverItemsParNom(element)->getOutput(j);
        cout << "L'élément " << element <<" est l'entrée de " << sortie << " qui a pour etat  " << (int*)delta_etat << ". Le flag est de  " << (int*)d.trouverItemsParNom(sortie)->getFlag()<< endl;
        if(d.trouverItemsParNom(sortie)->getNbPorts() == 1) //output
        {
          d.trouverItemsParNom(sortie)->ajoutEtat(delta_etat, 0);
        }
        else
        {
          if(d.trouverItemsParNom(sortie)->getType() == 10) //MUX
          {
            if(d.trouverItemsParNom(sortie)->element_present_entree(element)==true) //si entree est une "entree"
            {
              d.trouverItemsParNom(sortie)->setEntree(element, delta_etat);
              cout << "sortie mux " << element << endl;
            }
            else if(d.trouverItemsParNom(sortie)->element_present_entree_sel(element)==true)  //Si entree est un "sel"
            {
              d.trouverItemsParNom(sortie)->setEntreeSel(element,delta_etat);
              cout << "sortie mux sel" << element << endl;
            }
            else
            {
              d.trouverItemsParNom(sortie)->ajoutEtat( delta_etat,  1);
              cout << "deuxieme etape" << endl;
              cout << "delta etat" << delta_etat << endl;
            }
          }
          else  //Si different de mux
          {
            d.trouverItemsParNom(sortie)->ajoutEtat( delta_etat,  d.trouverItemsParNom(sortie)->getFlag() );  //On place l'état à son emplacement en fonction du flag
            d.trouverItemsParNom(sortie)->setFlag(d.trouverItemsParNom(sortie)->getFlag() + 1);  //On ajoute 1 au flag pour l'état suivant
          }

        }
      }
    }


  }
}




void Simulateur::calcul_simulation(int nb_periode, Schema sch, Dot d, Stimuli sti)
{

  for(int i = 0; i < nb_periode; i ++)
  {
    cout << "Période : " << i +1 << endl;
    if((getDelta_cycle(i) == 0)||(sch.getNbElements_bascule()!=0))  //Si delta cycle == 0, on calcul tous les états
    {
      algo_simulation(i, sch, d, sti);
    }
    else  //Sinon, on recopie les valeurs précédentes
    {
      for(int j = 0; j <sch.getNbElements_output(); j++)
      {
        string sortie ;
        sortie = lireElements_resultat(sch.lireElements_output(j));
        char test = sortie[sortie.size()-1];
        string::iterator it=sortie.end();
        *it--;
        ajouterElements_resultat(sch.lireElements_output(j),test);
      }
    }
    cout << endl;
  }


}



void Simulateur::calcul_delta_cycle(Stimuli sti, Schema sch)
{
  int flag;
  int i;
  for(int j = 1; j < sti.getnbPeriode(); j++)
  {
    flag = 1;
    i = 0;
    while((i < sch.getNbElements_input())&&(flag!=0))
    {
      if((sti.recupEntreeParNom(sch.lireElements_input(i),j))==(sti.recupEntreeParNom(sch.lireElements_input(i),j-1)))  //On regarde deux états successifs s'ils sont égaux
      {
        flag = 1;
      }
      else
      {
        flag = 0;
      }
      i++;
    }
    setDelta_cycle(flag);  //On met le flag dans la valeur du delta cycle
  }
}



char Simulateur::getDelta_cycle(int periode)
{
  return delta_cycle[periode-1];
}

void Simulateur::setDelta_cycle( char value)
{
  delta_cycle.push_back(value);
}
