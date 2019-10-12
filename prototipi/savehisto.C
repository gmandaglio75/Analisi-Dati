{
  
    //make-up section:
  //we are building our canvas and the general set-up of the figure
 int mymarkerstyle=20;
 float mymarkersize=1.;
 float mytextsize=0.065;
 int mytextfont=132;

 
 
  TCanvas *Spettro = new TCanvas("Spettro","Spettro",700,500);
 gStyle->SetOptStat("");
 Spettro->SetFillColor(0);
 Spettro->SetBorderMode(0);
 Spettro->SetBorderSize(2);
 Spettro->SetLeftMargin(0.14);
 Spettro->SetRightMargin(0.06);
 Spettro->SetTopMargin(0.03);
 Spettro->SetBottomMargin(0.16);
 Spettro->SetTickx(1);
 Spettro->SetTicky(1);
  stringstream ss;
  char name[20];  
  TH1D *pino[10];
  for(int i =0; i<10;i++){
  ss<<"pino"<<i;
  ss>>name;
  pino[i] = new TH1D(name,"",100,-20,20);
  ss.clear();
  }
  double a;
  ifstream leggo("dati_Gennaio.dat");
  int k=0;
  while(leggo>>a){
    pino[k]->Fill(a);
    k++;
    if(k==10)k=0;
  }
   
  

 for(int j=0; j<10;j++){
 pino[j]->GetXaxis()->SetTitleSize(mytextsize);
 pino[j]->GetYaxis()->SetTitleSize(mytextsize);
 pino[j]->GetXaxis()->SetLabelSize(mytextsize);
 pino[j]->GetYaxis()->SetLabelSize(mytextsize);
 pino[j]->GetXaxis()->SetTitleFont(mytextfont);
 pino[j]->GetYaxis()->SetTitleFont(mytextfont);
 pino[j]->GetXaxis()->SetLabelFont(mytextfont);
 pino[j]->GetYaxis()->SetLabelFont(mytextfont);
 pino[j]->GetXaxis()->CenterTitle(1);
 pino[j]->GetYaxis()->CenterTitle(1);
 pino[j]->GetXaxis()->SetTitleOffset(1.10);
 pino[j]->GetYaxis()->SetTitleOffset(1.1);
 pino[j]->SetTitle("");
 pino[j]->GetXaxis()->SetTitle("#theta (degree)");
 pino[j]->GetYaxis()->SetTitle("Counts");
 
 }
 
 
 
 TObjArray eventi(0);

//aggiungi gli istogrammi
 for(int m=0; m<10;m++){
eventi.Add(pino[m]);
 }
gROOT->ForceStyle();
TFile *fg = new TFile ("histos.root", "RECREATE");
fg->cd();
eventi.Write();
fg->Close();
 
}