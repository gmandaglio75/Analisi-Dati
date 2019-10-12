{
  //it opens the file containing the histos
  // in root after the following command if you type sim->ls(); the class will tell you
  // what is stored in the root file
TFile *sim = new TFile("CosMu-.2-2-150cm-n50cm-1248.8Hz-20cmConc-500k.thphtofmod.root");
//I'm copying the histo thetasim in CosMu-.2-2-150cm-n50cm-1248.8Hz-20cmConc-500k.thphtofmod.root
//in a local variable "pino" (I did because of root6, c++ to rigid)
TH1D *pino;
pino = thetasim;
//I'm asking the numbers of bins
int numerodibin = pino->GetNbinsX();
cout<<numerodibin<<endl;
//I'm writing in a file the computed histo stored in CosMu-.2-2-150cm-n50cm-1248.8Hz-20cmConc-500k.thphtofmod.root
ofstream scrivo1("histocontentsexample1.dat");
ofstream scrivo2("histocontentsexample2.dat");
//I'm writing in two format in order to be compatible for future use with TGraph and TGraphError classes 
for(int i=1;i<=numerodibin;i++){
scrivo1<<pino->GetBinCenter(i)<<"   "<<pino->GetBinContent(i)<<endl;
scrivo2<<pino->GetBinCenter(i)<<"   "<<pino->GetBinContent(i)<<"   "<<pino->GetBinWidth(i)/2<<"  "<<pino->GetBinError(i)<<endl;
}
scrivo1.close();
scrivo2.close();
}
