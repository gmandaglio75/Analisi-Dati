{
  
//this macro give an example on how to create a root structure to store your data
//in this case the data are produced by a toy montecarlo, but the sorce
//of data could be whatever ;=)  
   TFile f("test.root","recreate");
   
   TTree h90("h90","h90");
  
   
   float Vx,Vy,Vz;
   int event;
   
   h90.Branch("event",&event,"event/I");
   h90.Branch("Vx",&Vx,"Vx/F");
   h90.Branch("Vy",&Vy,"Vy/F");
   h90.Branch("Vz",&Vz,"Vz/F");
  

   
    TRandom3 randy(0);
   
   for (int jentry=0; jentry<1000000;jentry++) {
   event =   jentry;
   Vx = randy.Gaus(0,0.3);
   Vy = randy.Gaus(0,0.7);
   Vz = randy.Uniform(-3,3);
     h90.Fill();
  }
    h90.Write();
   f.Close();

   
}
