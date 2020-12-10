
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

//void Schema::construction_schema();
