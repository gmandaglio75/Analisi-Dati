{//inizio della macro
ifstream leggo("datoni.dat");
if(leggo.fail())
    {
    cout<<"the file does not exist!"<<endl;
    }
double a;
//dichiarazione oggetto della classe TH1D
TH1D *hist[10];
for(int i=1; i<11;i++){
 hist[i-1]= new TH1D(Form("h%d",i),"",50,0,0);
}
int contami =0;
while(leggo>>a)
    {
    contami++;//conta le letture effettuate
    if(a<100){
              hist[contami-1]->Fill(a);//ogni istogramma  viene riempito dalla corretta colonna
             }
        if(contami==10){
             contami=0;//azzero il contatore
            }
    }
hist[3]->Draw(); //disegno il grafico 4

TCanvas *scatolone = new TCanvas("scatolone","",800,400);
scatolone->Divide(5,2);

for(int i=0; i<10;i++){
 scatolone->cd(i+1);
 hist[i]->Draw();
}

TFile * pino = new TFile("10histo.root","recreate");
for(int i=0; i<10;i++){
 hist[i]->Write();
}
pino->Close();




}//fine della macro
