#include "../inc/Mux.h"

using namespace std;


char Mux::calculEtat()
{
  int nb_sel;
  if((m_entree_sel.size()>1))
  {
    cout << "taille m_entree_sel : " << m_entree_sel.size() << endl;
    nb_sel = (getEntreeSel_par_numero(0) + (getEntreeSel_par_numero(1)<<1));
    for(int i = 2; i < m_entree_sel.size();i++)
    {
      nb_sel += (getEntreeSel_par_numero(0) << i);
    }
  }
  else
  {
    nb_sel = (getEntreeSel_par_numero(0));
  }
  cout << "m_entree_sel : " << nb_sel<< endl;

  cout << "taille entree : " << m_entree.size()<< endl;

  cout << "entree 1 " << getEntree_par_numero(0) << endl;
  cout << "entree 2 " << getEntree_par_numero(1) << endl;

  cout << "taille m_entree_sel : " << getEntree_par_numero(nb_sel) << endl;

  return (getEntree_par_numero(nb_sel));

}


bool Mux::element_present_entree(string nom)
{
  if(m_entree.count(nom)>0)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool Mux::element_present_entree_sel(string nom)
{
  if(m_entree_sel.count(nom)>0)
  {
    return true;
  }
  else
  {
    return false;
  }
}


char Mux::getEntree_par_numero(int numero) const
{
  string nom = v_entree[numero];
  return m_entree.at(nom);
}
char Mux::getEntree_par_nom(string nom) const
{
  return m_entree.at(nom);
}


char Mux::getEntreeSel_par_nom(string nom) const
{
  return m_entree_sel.at(nom);
}

char Mux::getEntreeSel_par_numero(int numero) const
{
  string nom = v_entree_sel[numero];
  return m_entree_sel.at(nom);
}
