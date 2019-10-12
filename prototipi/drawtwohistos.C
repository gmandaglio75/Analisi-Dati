{
  TFile *sim = new TFile("CosMu-.2-2-150cm-n50cm-1248.8Hz-20cmConc-500k.thphtofmod.root");

  TFile *expy = new TFile("GENO-01-2018-09-06-00023.thphtof.root");
  
         Int_t mymarkerstyle=20;
      float mymarkersize=0.6;
         float mytextsize=0.06;
         float mylabsize=0.055;
	 
	 TCanvas *c1 = new TCanvas("c1", "c1",600,500);
   gStyle->SetOptStat("");
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetLeftMargin(0.15);
   c1->SetRightMargin(0.05);
   c1->SetTopMargin(0.05);
   c1->SetBottomMargin(0.15);

   sim->cd();//this allows us to swich between different root files
   thetasim->GetXaxis()->SetTitleSize(mytextsize);
   thetasim->GetYaxis()->SetTitleSize(mytextsize);
   thetasim->GetXaxis()->SetTitleFont(132);
   thetasim->GetYaxis()->SetTitleFont(132);
   thetasim->GetXaxis()->SetLabelSize(mylabsize);
   thetasim->GetXaxis()->SetNdivisions(906);
   thetasim->GetYaxis()->SetLabelSize(mylabsize);
   thetasim->GetXaxis()->SetLabelFont(132);
   thetasim->GetYaxis()->SetLabelFont(132);
   thetasim->GetXaxis()->CenterTitle(1);
   thetasim->GetYaxis()->CenterTitle(1);
   thetasim->GetYaxis()->SetTitleOffset(1.1);
   thetasim->SetTitle("");
   thetasim->GetYaxis()->SetTitle("counts");
   thetasim->GetXaxis()->SetTitle("#theta (degre)");

   thetasim->SetLineWidth(2);
   thetasim->SetLineColor(2);
   thetasim->SetLineStyle(8);
   thetasim->Draw();
   
   double normy = thetasim->GetEntries(); //this for nomalization
   
   TLegend *leg = new TLegend(0.7,0.28,0.93,0.49,NULL,"brNDC"); //this class is for the leggend
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetTextSize(0.05);
   leg->SetFillStyle(1001);
   leg->SetTextFont(132);

   leg->AddEntry(thetasim,"simulation","l");
  
   expy->cd();//this allows us to swich between different root files
   thetaexp->SetLineWidth(2);
   thetaexp->SetLineColor(1);
   thetaexp->SetLineStyle(1);
   thetaexp->DrawNormalized("same",normy);

   leg->AddEntry(thetaexp,"data","l");

   leg->Draw();   
      c1->SaveAs("theta-.2-2.pdf");
}
