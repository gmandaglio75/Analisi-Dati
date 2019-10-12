{
TCanvas *p = new TCanvas("p","",600,500);
TH1D *isto = new TH1D("isto","",100,0.,10.);
TH1D *isto1 = new TH1D("isto1","",100,0.,10.);
TH1D *isto2 = new TH1D("isto2","",100,0.,10.);
TH1D *isto3 = new TH1D("isto3","",100,0.,10.);

isto->SetLineWidth(2);
isto1->SetLineWidth(2);
isto2->SetLineWidth(2);
isto3->SetLineWidth(2);
isto->SetLineColor(1);
isto1->SetLineColor(2);
isto2->SetLineColor(3);
isto3->SetLineColor(4);
TF1 * fondo = new TF1("fondo","-x*x+20*x",0,20);

TRandom3 generello(0);

//ora abbiamo gli ingredianti mettiamoli all'opera
//facciamo un ciclo per riempire 
double misura,temp;
for(int i =0; i<1000000; i++){
double peso=generello.Uniform();
if(peso<0.05){
misura =generello.Gaus(6.2,0.3);
isto->Fill(misura);
temp = misura + generello.Gaus(0,1);
isto1->Fill(temp);
temp = misura + generello.Gaus(0,0.5);
isto2->Fill(temp);
temp = misura + generello.Gaus(0,0.1);
isto3->Fill(temp);
}
else{
misura = fondo->GetRandom();
isto->Fill(misura);
temp = misura + generello.Gaus(0,1);
isto1->Fill(temp);
temp = misura + generello.Gaus(0,0.5);
isto2->Fill(temp);
temp = misura + generello.Gaus(0,0.1);
isto3->Fill(temp);
}
isto->Draw("pe");
p->Update();
}//chiudo il ciclo

isto->Draw();
isto1->Draw("same");
isto2->Draw("same");
isto3->Draw("same");

}
