{
  //This macro opens a root file storing 10 histograms
  //and it uses a dinamical procedure to write in 10 data files
  //the contents of the histograms.
  //The output of the macro will be used for the example macros of TGraph classes.
  TFile *file = new TFile("histos.root"); //opens the root file

  TH1* readThis = 0; //histogram class pointer
  
  stringstream ss; //to manipulate the string name for our use
  char name[30];  
  
  ofstream writer;
  
  for(int i =0; i<file->GetNkeys();i++){//
  ss<<"pino"<<i;
  ss>>name;
  file->GetObject(name, readThis); //we estract the address of pino0, pino1.....
  ss.clear(); //we clear the information stored in ss
  ss<<"histo_dati_"<<i<<".dat";
  ss>>name;
  writer.open(name);//we open the file histo_dati_0.dat, histo_dati_1.dat.....
    for(int j=0; j<readThis->GetNbinsX(); j++){//we copy the contents of histrograms in histo_dati_0, histo_dati_1.dat.....
      writer<<readThis->GetBinCenter(j)<<"  "<<readThis->GetBinContent(j)<<"  "<<readThis->GetBinWidth(j)/2.<<"  "<<readThis->GetBinError(j)<<endl;
    }
    writer.close();//close the current file to be able to move to the next one.
    ss.clear();//again we clear ss
  }
  
}