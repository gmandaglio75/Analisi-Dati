{
TTree *hpp1 = new TTree("hpp1","hpp1");
TTree *hpp2 = new TTree("hpp2","hpp2");
float evento1,evento2,evento3,evento4,evento5,evento6,evento7,evento8,evento9,evento10;
hpp1->Branch("evento1",&evento1,"evento1/F");
hpp1->Branch("evento2",&evento2,"evento2/F");
hpp1->Branch("evento3",&evento3,"evento3/F");
hpp1->Branch("evento4",&evento4,"evento4/F");
hpp1->Branch("evento5",&evento5,"evento5/F");
hpp2->Branch("evento6",&evento6,"evento6/F");
hpp2->Branch("evento7",&evento7,"evento7/F");
hpp2->Branch("evento8",&evento8,"evento8/F");
hpp2->Branch("evento9",&evento9,"evento9/F");
hpp2->Branch("evento10",&evento10,"evento10/F");

ifstream leggo("datoni.dat");

if(leggo.fail())
	{
	cout<<"non riesco a trovare il file o il file è corrotto \n";
	}

while (leggo>>evento1>>evento2>>evento3>>evento4>>evento5>>evento6>>evento7>>evento8>>evento9>>evento10)
	{
	hpp1->Fill();
        hpp2->Fill();
	}

TFile * rocco = new TFile("lino1.root","recreate");
TFile * mario = new TFile("lino2.root","recreate");
rocco->cd();
hpp1->Write();
rocco->Close();
mario->cd();
hpp2->Write();
mario->Close();
}
