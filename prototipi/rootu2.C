{
TTree *hpp = new TTree("hpp","hpp");
float evento1,evento2,evento3,evento4,evento5,evento6,evento7,evento8,evento9,evento10;
hpp->Branch("evento1",&evento1,"evento1/F");
hpp->Branch("evento2",&evento2,"evento2/F");
hpp->Branch("evento3",&evento3,"evento3/F");
hpp->Branch("evento4",&evento4,"evento4/F");
hpp->Branch("evento5",&evento5,"evento5/F");
hpp->Branch("evento6",&evento6,"evento6/F");
hpp->Branch("evento7",&evento7,"evento7/F");
hpp->Branch("evento8",&evento8,"evento8/F");
hpp->Branch("evento9",&evento9,"evento9/F");
hpp->Branch("evento10",&evento10,"evento10/F");

ifstream leggo("datoni.dat");

if(leggo.fail())
	{
	cout<<"non riesco a trovare il file o il file è corrotto \n";
	}

while (leggo>>evento1>>evento2>>evento3>>evento4>>evento5>>evento6>>evento7>>evento8>>evento9>>evento10)
	{
	hpp->Fill();
	}

TFile * lino = new TFile("lino.root","recreate");
hpp->Write();
lino->Close();
}
