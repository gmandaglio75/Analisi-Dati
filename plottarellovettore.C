{
 ifstream leggo1("daterelli.dat");
 ifstream leggo2("daterelli2.dat");
TH1D *histo[6];
for(int i =0; i<6;i++){
histo[i] = new TH1D(Form("h%d",i+1),"",50,0,10);
}

double a,b,c,d;
while(leggo2>>a>>b)
   {
   histo[0]->Fill(a);
   histo[1]->Fill(b);
   }
while(leggo1>>a>>b>>c>>d)
   {
   histo[2]->Fill(a);
   histo[3]->Fill(b);
   histo[4]->Fill(c);
   histo[5]->Fill(d);
   }
TCanvas *tutti = new TCanvas("tutti","",1200,1000);
tutti->Divide(2,3);

for(int i =0; i<6;i++){
tutti->cd(i+1);
histo[i]->GetYaxis()->SetRangeUser(0,10000);
histo[i]->Draw();
}
tutti->SaveAs("figuratutti.pdf");


TCanvas *ggg = new TCanvas("ggg","",600,500);


TH1D * diff = new TH1D("diff","",50,0,10);

diff->Add(histo[1],histo[5],1,-1);

histo[1]->Draw();

diff->SetLineColor(2);

diff->Draw("same");

ggg->SaveAs("diff4.pdf");





}
