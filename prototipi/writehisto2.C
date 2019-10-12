{
  ifstream leggo("datix.dat");
  double a;
  TH1D *pino = new TH1D("pino","",50,0,20);
  
  while(leggo>>a){
  pino->Fill(a);  
  }
  int numerodibin = pino->GetNbinsX();
  cout<<numerodibin<<endl;
//I'm writing in a file the computed histo stored in CosMu-.2-2-150cm-n50cm-1248.8Hz-20cmConc-500k.thphtofmod.root
ofstream scrivo1("histocontentsexample1x.dat");
ofstream scrivo2("histocontentsexample2x.dat");
//I'm writing in two format in order to be compatible for future use with TGraph and TGraphError classes 
for(int i=1;i<=numerodibin;i++){
scrivo1<<pino->GetBinCenter(i)<<"   "<<pino->GetBinContent(i)<<endl;
scrivo2<<pino->GetBinCenter(i)<<"   "<<pino->GetBinContent(i)<<"   "<<pino->GetBinWidth(i)/2<<"  "<<pino->GetBinError(i)<<endl;
}
scrivo1.close();
scrivo2.close();
}
