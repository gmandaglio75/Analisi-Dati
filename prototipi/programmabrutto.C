{//inizio della macro
ifstream leggo("datoni.dat");
if(leggo.fail())
    {
    cout<<"the file does not exist!"<<endl;
    }
double a;
//dichiarazione oggetto della classe TH1D
TH1D *h1 = new TH1D("h1","",50,0,0);
TH1D *h2 = new TH1D("h2","",50,0,0);
TH1D *h3 = new TH1D("h3","",50,0,0);
TH1D *h4 = new TH1D("h4","",50,0,0);
TH1D *h5 = new TH1D("h5","",50,0,0);
TH1D *h6 = new TH1D("h6","",50,0,0);
TH1D *h7 = new TH1D("h7","",50,0,0);
TH1D *h8 = new TH1D("h8","",50,0,0);
TH1D *h9 = new TH1D("h9","",50,0,0);
TH1D *h10 = new TH1D("h10","",50,0,0);

int contami =0;
while(leggo>>a)
    {
    contami++;//conta le letture effettuate
    if(contami==1){ 
        h1->Fill(a);
        }
    if(contami==2){ 
        h2->Fill(a);
        }
    if(contami==3){ 
        h3->Fill(a);
        }
    if(contami==4){ 
        h4->Fill(a);
        }
    if(contami==5){ 
        h5->Fill(a);
        }
    if(contami==6){ 
        h6->Fill(a);
        }
    if(contami==7){ 
        h7->Fill(a);
        }
    if(contami==8){ 
        h8->Fill(a);
        }
    if(contami==9){ 
        h9->Fill(a);
        }
    if(contami==10){ 
        h10->Fill(a);
        contami=0;
        }
    }
TCanvas *scatolone = new TCanvas("scatolone","",800,400);
scatolone->Divide(2,2);
scatolone->cd(1);
h1->Draw();
scatolone->cd(2);
h2->Draw();
scatolone->cd(3);
h3->Draw();
scatolone->cd(4);
h4->Draw();
}//fine della macro


