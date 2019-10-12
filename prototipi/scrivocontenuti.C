{
TFile apro("10histo.root");
//h1->Draw();
//dichiaro     la roba tra parentesi dice ciò che deve restituire Get ....Get si aggancia all'istogramma che dite voi
TH1D *copia = (TH1D*)apro.Get("h1");//copia l'indirizzo dell'istogramma h1 nella variabile copia
int stop = copia->GetNbinsX();
for(int i =1 ; i < stop; i++){
cout<<copia->GetBinCenter(i) <<"   "<<copia->GetBinContent(i)<<endl;
}

ofstream scrivo("histodata.dat");

for(int i =1 ; i < stop; i++){
scrivo<<copia->GetBinCenter(i) <<"   "<<copia->GetBinContent(i)<<endl;
}

}

