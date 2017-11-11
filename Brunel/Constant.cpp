

#include "Constant.hpp"


double h (0.1);
double tau (20.0);
double r (20.0);
double z (-(h/tau));

double Je (0.1);
double Ji (-0.5);

double thresholdSpikes (20.0);

int D (15);
double bufferSize (D+1);
int presision (100);

double Ce (1000);
double Ci (250);

double Vthr (thresholdSpikes/(Ce*Je*tau));
double Vext (2*Vthr);
