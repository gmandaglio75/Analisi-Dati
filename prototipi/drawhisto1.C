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
  
  //it opens the file containing the histos
  // in root after the following command if you type sim->ls(); the class will tell you
  // what is stored in the root file
TFile *sim = new TFile("CosMu-.2-2-150cm-n50cm-1248.8Hz-20cmConc-500k.thphtofmod.root");
//I'm copying the histo thetasim in CosMu-.2-2-150cm-n50cm-1248.8Hz-20cmConc-500k.thphtofmod.root
//in a local variable "pino" (I did because of root6, c++ to rigid)
TH1D *pino;
pino = thetasim;
  

 
 pino->GetXaxis()->SetTitleSize(mytextsize);
 pino->GetYaxis()->SetTitleSize(mytextsize);
 pino->GetXaxis()->SetLabelSize(mytextsize);
 pino->GetYaxis()->SetLabelSize(mytextsize);
 pino->GetXaxis()->SetTitleFont(mytextfont);
 pino->GetYaxis()->SetTitleFont(mytextfont);
 pino->GetXaxis()->SetLabelFont(mytextfont);
 pino->GetYaxis()->SetLabelFont(mytextfont);
 pino->GetXaxis()->CenterTitle(1);
 pino->GetYaxis()->CenterTitle(1);
 pino->GetXaxis()->SetTitleOffset(1.10);
 pino->GetYaxis()->SetTitleOffset(1.1);
 pino->SetTitle("");
 pino->GetXaxis()->SetTitle("#theta (degree)");
 pino->GetYaxis()->SetTitle("Counts");
 
 
 pino->Draw();
 
 
 Spettro->SaveAs("drawhisto1.pdf");
 
}