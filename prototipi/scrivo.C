{
TFile *ciao = new TFile("10histo.root");
ofstream scrivo("usciat.dat");
TH1D *copia = (TH1D*)ciao->Get("h1");
int stop =copia->GetNbinsX();
for(int i=1; i<stop; i++)
scrivo<<copia->GetBinCenter(i)<<"   "<<copia->GetBinContent(i)<<endl;


}
