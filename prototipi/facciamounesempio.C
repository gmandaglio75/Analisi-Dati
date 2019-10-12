#include <fstream>
#include <iostream>
#include "TH1D.h"
void facciamounesempio()
{

double a;

ifstream leggo("dati1x.dat");

TH1D *primoistogramma = new TH1D("primoistogramma","esempio",100,-1,8);


while(leggo>>a){primoistogramma->Fill(a);}

primoistogramma->Draw();

return;

}
