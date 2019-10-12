{
  
//this macro give an example on how to create a root structure to store your data
//in this case the data are produced by a toy montecarlo, but the sorce
//of data could be whatever ;=)  
   TFile f("test.root","recreate");
   
   TTree h90("h90","h90");
  
   
   float theta,phi,R;
   int event;
   
   double raggio = 10.;
   
   h90.Branch("event",&event,"event/I");
   h90.Branch("theta",&theta,"theta/F");
   h90.Branch("phi",&phi,"phi/F");
   h90.Branch("R",&R,"R/F");
  

   
    TRandom3 randy(0);
   double randello;
   for (int jentry=0; jentry<1000000;jentry++) {
   event =   jentry;
   randello = randy.Rndm();
   phi = 360.*randello;
   randello = randy.Rndm();
   theta = acos(1-2*randello)/acos(-1)*180.;
   randello = randy.Rndm();
   R = raggio*pow(randello,1./3);
     h90.Fill();
  }
    h90.Write();
   f.Close();

   
}
