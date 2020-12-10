
#include "../inc/Porte.h"

using namespace std;


string Porte::getOutput(int numero_element) const
{
  if(numero_element<=(getNbOutput()-1))
  {
    return output[numero_element];
  }
  else
  {
    cout << "erreur";
    exit(1);
  }
}

int Porte::getNbOutput() const
{
  return output.size();
}

void Porte::ajoutOutput(string output_d)
{
  output.push_back(output_d);
}
