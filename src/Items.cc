
#include "../inc/Items.h"
using namespace std;


Items::Items(const string &nom, char type, char nbPorts)
{
  this->nom = nom;
  this->type = type;
  this->nbPorts = nbPorts;
}

const string & Items::getNom() const
{
  return this->nom;
}

const char Items::getType() const
{
  return this->type;

}
const char Items::getNbPorts() const
{
  return this->nbPorts;
}
