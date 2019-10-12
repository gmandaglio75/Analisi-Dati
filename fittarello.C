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
   TF1 * fun = new TF1("fun","[0]*exp(-[1]/[2]*x)",2,8);
      fun->SetParameters(1,1,1);
histo[4]->Draw();
histo[4]->Fit("fun","R");
//cout<<"chi2ridotto ="<<fun->GetChisquare() / fun->GetNDF()<<endl;




}
