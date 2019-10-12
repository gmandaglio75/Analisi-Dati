{
TRandom3 randy(0);
TH1D *vediamounpo = new TH1D("vediamounpo","",100,0,6);
TH1D *vediamoduepo = new TH1D("vediamoduepo","",100,0,6);
TH1D *randello = new TH1D("randello","",100,0,1);
TF1 *funz = new TF1("funz","1/x",0.5,5);
double r;
double eg;
for(int i=0; i<1000000;i++)
{
r=randy.Rndm();
randello->Fill(r);
eg=0.5*exp(r*log(10));
vediamounpo->Fill(eg);
vediamoduepo->Fill(funz->GetRandom());

}
TCanvas *p = new TCanvas("p","",600,500);
randello->Draw();
TCanvas *m = new TCanvas("m","",600,500);
vediamounpo->Draw();
TCanvas *n = new TCanvas("n","",600,500);
vediamoduepo->Draw();



}
