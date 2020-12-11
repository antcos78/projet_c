
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


void Schema::ajouterElements_schema(const string & nom)
{
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

string Schema::lireElements_schema(int numero)
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
  cout << "erreur";
  exit(1);
}

string Schema::lireElements_output(int numero)
{
  return output[numero];
}

string Schema::lireElements_input(int numero)
{
  return input[numero];
}


void Schema::construction_schema( Dot z )
{
  int i = 0;
  int j;
  string element;
  for(i=0;i<z.getnbItems();i++)
  {
    if(z.trouverItemsParNumero(i)->getType() == 0)
    {
      ajouterElements_schema(z.trouverItemsParNumero(i)->getNom());
      ajouterElements_input(z.trouverItemsParNumero(i)->getNom());
    }
  }

  cout << "element dans le schema : " << getNbElements_schema() << endl;
  cout << "element dans le input : " << getNbElements_input()<< endl;


  i = 0;
  j = 0;

  while(getNbElements_schema() < z.getnbItems())  {
    if(z.trouverItemsParNumero(j)->getType() != 1)
    {
      for(int i = 0; i < z.trouverItemsParNom(lireElements_schema(j))->getNbOutput() ; i++ )
      {

        element = z.trouverItemsParNom(lireElements_schema(j))->getOutput(i);
        //cout << element << " ";
        char nb_port = z.trouverItemsParNom(element)->getNbPorts();
      //  cout << "nb ports : " << nb_port << endl;

        if(nb_port == 1)
        {
          if(z.trouverItemsParNom(element)->getType() == 1)
          {
            ajouterElements_output(element);
          }
          ajouterElements_schema(element);
        }

        else if(nb_port == 2)
        {
          if(z.trouverItemsParNom(element)->getFlag() != 1)
          {
            z.trouverItemsParNom(element)->setFlag(1);
            //cout << "flag à 1" << endl;
          }
          else
          {
            ajouterElements_schema(element);
            z.trouverItemsParNom(element)->setFlag(0);
            //cout << "flag OK" << endl;

          }
        }

        else if(nb_port == 3)
        {
          if(z.trouverItemsParNom(element)->getFlag() != 2)
          {
            z.trouverItemsParNom(element)->setFlag(z.trouverItemsParNom(element)->getFlag() + 1);
          }
          else
          {
            ajouterElements_schema(element);
            z.trouverItemsParNom(element)->setFlag(0);
          }
        }



      }
    }
    j++;
  }

}
