{
 ifstream leggo1("daterelli.dat");
 ifstream leggo2("daterelli2.dat");
TH1D *h1 = new TH1D("h1","",50,0,10);
TH1D *h2 = new TH1D("h2","",50,0,10);
TH1D *h3 = new TH1D("h3","",50,0,10);
TH1D *h4 = new TH1D("h4","",50,0,10);
TH1D *h5 = new TH1D("h5","",50,0,10);
TH1D *h6 = new TH1D("h6","",50,0,10);
double a,b,c,d;
while(leggo2>>a>>b)
   {
   h1->Fill(a);
   h2->Fill(b);
   }
while(leggo1>>a>>b>>c>>d)
   {
   h3->Fill(a);
   h4->Fill(b);
   h5->Fill(c);
   h6->Fill(d);
   }
TCanvas *tutti = new TCanvas("tutti","",1200,1000);
tutti->Divide(2,3);
tutti->cd(1);
h1->Draw();
tutti->cd(2);
h2->Draw();
tutti->cd(3);
h3->Draw();
tutti->cd(4);
h4->Draw();
tutti->cd(5);
h5->Draw();
tutti->cd(6);
h6->Draw();

//abbiamo tutti gli istogrammi per giocare

TH1D *somma = new TH1D("somma","",50,0,10);

somma->Add(h1,h3,1,-1);


h1->SetLineColor(1);
h1->SetLineStyle(1);
h1->SetLineWidth(2);

somma->SetLineColor(2);
somma->SetLineStyle(2);
somma->SetLineWidth(2);

TCanvas *sss = new TCanvas("sss","",1200,1000);

h1->Draw();

somma->Draw("same");

sss->SaveAs("diffhisto1.pdf");





}
