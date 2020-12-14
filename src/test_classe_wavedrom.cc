#include <iostream>
#include "../inc/Stimuli.h"

#include "../inc/Items.h"
#include "../inc/Porte.h"
#include "../inc/Not.h"
#include "../inc/And2.h"
#include "../inc/Or2.h"
#include "../inc/Schema.h"
#include "../inc/Dot.h"
#include "../inc/Input.h"
#include "../inc/Output.h"
#include "../inc/Simulateur.h"
#include "../inc/Wavedrom.h"


using namespace std;



int main ()
{
  Dot dov;
  Simulateur simu;
  Schema sch;
  Wavedrom wave;
  Stimuli sti;


  dov.parsingDot();

  sti.parsingStimuli();

  sch.construction_schema( dov );
  simu.declaration_resultat(sch);
  simu.calcul_delta_cycle(sti, sch);
  simu.calcul_simulation(sti.getnbPeriode(), sch, dov,sti);
  wave.generation_Wavedrom( simu, sch, sti);

  return 0;
}
