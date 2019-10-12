{
	//apriamo il file che conterrà i nostri dati
TFile * lino = new TFile("lino.root","recreate");
//Stuttura ad albero per accumulare i dati
TTree *hpp = new TTree("hpp","hpp");
//variabile di lettura dei dati, in questo caso uno solo 
//ma potrebbero esser molti di più
float evento;
//agganciamo la variabile ad un ramo della struttura hpp
hpp->Branch("evento",&evento,"evento/F");
ifstream leggo("dati1x.dat");

if(leggo.fail())
	{
	cout<<"non riesco a trovare il file o il file è corrotto \n";
	}
//il ciclo procede a leggere l'evento
while (leggo>>evento)
	{
	hpp->Fill();//questo comando registra dentro il TTree i dati
	}
//Nota 
hpp->Write();//stampa i dati nel TFile attivo, in questo caso lino
lino->Close();//chiudiamo il file
}
