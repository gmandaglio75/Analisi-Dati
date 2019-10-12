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
  
  //we are reading data and passing them to pino
  ifstream leggo("dati1x.dat");
  
    if(leggo.fail()){
        cout<<"the file does not exist!"<<endl;
    }
  double a;
  TH1D *pino = new TH1D("pino","",50,0,20);
  
  while(leggo>>a){
  pino->Fill(a);  
  }
  

 
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
 pino->GetXaxis()->SetTitle("Energy (MeV)");
 pino->GetYaxis()->SetTitle("Counts");
 
 
 pino->Draw();

 TF1 * gaus2 = new TF1 ("gaus2","[0]*exp(-0.5*pow((x-[1])/[2],2))+[3]*exp(-0.5*pow((x-[4])/[5],2))+[6]+[7]*x",10,17);
 gaus2->SetParameters(1800.,12.5,0.125,800,14,0.5,200,-0.6);

pino->Fit("gaus2","R");
 




 
 Spettro->SaveAs("drawhisto2.pdf");
 
}
