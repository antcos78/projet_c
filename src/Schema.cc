#include "../inc/Schema.h"



using namespace std;

int Schema::getNbElements_schema()
{
  return schema.size();
}

int Schema::getNbElements_input()
{
  return input.size();
}

int Schema::getNbElements_output()
{
  return output.size();
}

int Schema::getNbElements_bascule()
{
  return bascule.size();
}

void Schema::ajouterElements_schema(const string & nom)
{
  cout << "element ajouté" << endl;
  schema.push_back(nom);
}
void Schema::ajouterElements_input(const string & nom)
{
  input.push_back(nom);
}
void Schema::ajouterElements_output(const string & nom)
{
  output.push_back(nom);
}
void Schema::ajouterElements_bascule(const string & nom)
{
  bascule.push_back(nom);
}

string Schema::lireElements_schema(int numero)
{
  if(numero < getNbElements_schema())
  {
    int i = 0;
    list<string>::const_iterator itr;
    for(itr = schema.begin() ; itr!= schema.end() ; ++itr) {

      if(i==numero)
      {
        return *itr;
      }
      i++;
    }
    cout << "erreur lecture schema";
    exit(1);
  }
  else
  {
    cout << "erreur dimension schema ou erreur nb port" << endl;
    exit(2);
  }
}

string Schema::lireElements_output(int numero)
{
  if(numero < getNbElements_output())
  {
    return output[numero];
  }
  else
  {
    cout << "erreur dimension output" << endl;
    exit(2);
  }
}

string Schema::lireElements_input(int numero)
{
  if(numero < getNbElements_input())
  {
    return input[numero];
  }
  else
  {
    cout << "erreur dimension output" << endl;
    exit(2);
  }
}

string Schema::lireElements_bascule(int numero)
{
  if(numero < getNbElements_bascule())
  {
    return bascule[numero];
  }
  else
  {
    cout << "erreur dimension bascule" << endl;
    exit(2);
  }
}

void Schema::construction_schema( Dot z )
{
  int i = 0;
  int j;
  string element;
  for(i=z.getnbItems()-1;i>=0;i--)  //on verifie sur tous les éléments de la map si c'est une entrée
  {
    if(z.trouverItemsParNumero(i)->getType() == 11)
    {
      ajouterElements_schema(z.trouverItemsParNumero(i)->getNom());  //si oui on ajoute à la liste schema et bascule
      ajouterElements_bascule(z.trouverItemsParNumero(i)->getNom());
    }
  }

  for(i=0;i<z.getnbItems();i++)  //on verifie sur tous les éléments de la map si c'est une entrée
  {

    if(z.trouverItemsParNumero(i)->getType() == 0)
    {
      ajouterElements_schema(z.trouverItemsParNumero(i)->getNom());  //si oui on ajoute à la liste schema et input
      ajouterElements_input(z.trouverItemsParNumero(i)->getNom());
    }
  }

  cout << "element dans le schema : " << getNbElements_schema() << endl;
  cout << "element dans le input : " << getNbElements_input()<< endl;

  if(getNbElements_input()==0)
  {
    cout << "Pas d'entrée dans le schéma" << endl;
    exit(4);
  }

  i = 0;
  j = 0;

  while(getNbElements_schema()+getNbElements_output() < z.getnbItems()) //tant que les éléments stockés ne sont pas égaux
  {

    if(j == getNbElements_schema()) //si nombre d'élément trop grand (element non connecté)
    {
      cout << "erreur nb element schema et interconnexion" << endl;
      exit(3);
    }
    if(z.trouverItemsParNom(lireElements_schema(j))->getType() != 1)  //si c'est une sortie, on gère différemment
    {
      for(int i = 0; i < z.trouverItemsParNom(lireElements_schema(j))->getNbOutput() ; i++ ) //pour chaque élément liste de sortie
      {

        element = z.trouverItemsParNom(lireElements_schema(j))->getOutput(i);
        char nb_port = z.trouverItemsParNom(element)->getNbPorts();
        if(z.trouverItemsParNom(element)->getType() == 11)
        {
          cout << "bascule " << endl;
        }

        else if(nb_port == 1)  //S'il y a un port
        {
          if(z.trouverItemsParNom(element)->getFlag()==0 )  //Si flag à 0
          {
            if(z.trouverItemsParNom(element)->getType() == 1)  //Type est sortie
            {
              ajouterElements_output(element);  //On ajoute à la liste output
            }
            else
            {
              ajouterElements_schema(element);
            }
            z.trouverItemsParNom(element)->setFlag(1);  //On met le flag à 1
          }
          else
          {
            cout << "erreur nb entree 1 port" << endl;  //ERREUR NB PORTS D'ENTREE
            exit(3);
          }
        }

        else  //SI plus d'un port
        {
          if(z.trouverItemsParNom(element)->getFlag() < (z.trouverItemsParNom(element)->getNbPorts() - 1))  //Si nbport-1 > flag
          {
            z.trouverItemsParNom(element)->setFlag(z.trouverItemsParNom(element)->getFlag() +1);  //on met + 1 a flag
          }
          else if(z.trouverItemsParNom(element)->getFlag() == (z.trouverItemsParNom(element)->getNbPorts() - 1)) //Si nb port - 1 == flag
          {
            ajouterElements_schema(element);                                                          //On ajoute element
            z.trouverItemsParNom(element)->setFlag(z.trouverItemsParNom(element)->getNbPorts());
          }
          else  //Si flag trop grand, trop de ports
          {
            cout << "erreur nb entrees ports" << endl;
            exit(3);
          }
        }
      }
      if(z.trouverItemsParNom(lireElements_schema(j))->getNbOutput() == 0)  //Si output, problème
      {
        cout << "Erreur nb sortie de l'élément (0 sortie)" << endl;
        exit(5);
      }
    }
    j++;

  }


  if(getNbElements_output()==0)  //si list output vide
  {
    cout << "Pas de sortie dans le schéma" << endl;
    exit(4);
  }


  for(i = 0; i< getNbElements_output(); i ++)   //on met les output dans le schema  (à la fin)
  {
    ajouterElements_schema(lireElements_output(i));
  }
  for(i = getNbElements_output(); i < getNbElements_schema(); i++)  //on remet les flags à 0
  {
    z.trouverItemsParNom(lireElements_schema(i))->setFlag(0);
  }
  cout << "fin schema" << endl;

}
