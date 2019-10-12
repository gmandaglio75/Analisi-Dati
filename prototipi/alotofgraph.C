{
      //make-up section:
  //we are building our canvas and the general set-up of the figure
 int mymarkerstyle=20;
 float mymarkersize=1.;
 float mytextsize=0.065;
 int mytextfont=132;

TCanvas *Spettro = new TCanvas("Spettro","Spettro",700,500);
 gStyle->SetOptStat("");
 Spettro->SetFillColor(0);
 Spettro->SetBorderMode(0);
 Spettro->SetBorderSize(2);
 Spettro->SetLeftMargin(0.14);
 Spettro->SetRightMargin(0.06);
 Spettro->SetTopMargin(0.03);
 Spettro->SetBottomMargin(0.16);
 Spettro->SetTickx(1);
 Spettro->SetTicky(1);
 
 TH2D *frame = new TH2D("frame","",100,-10,20,100,0,2000);
 
 frame->GetXaxis()->SetTitleSize(mytextsize);
 frame->GetYaxis()->SetTitleSize(mytextsize);
 frame->GetXaxis()->SetLabelSize(mytextsize);
 frame->GetYaxis()->SetLabelSize(mytextsize);
 frame->GetXaxis()->SetTitleFont(mytextfont);
 frame->GetYaxis()->SetTitleFont(mytextfont);
 frame->GetXaxis()->SetLabelFont(mytextfont);
 frame->GetYaxis()->SetLabelFont(mytextfont);
 frame->GetXaxis()->CenterTitle(1);
 frame->GetYaxis()->CenterTitle(1);
 frame->GetXaxis()->SetTitleOffset(1.10);
 frame->GetYaxis()->SetTitleOffset(1.1);
 frame->SetTitle("");
 frame->GetXaxis()->SetTitle("Common variable (fishing-going)");
 frame->GetYaxis()->SetTitle("Counts");
  
 frame->Draw();
  
  TGraphErrors *gr0 = new TGraphErrors("histo_dati_0.dat");
  TGraphErrors *gr1 = new TGraphErrors("histo_dati_1.dat");
  TGraphErrors *gr2 = new TGraphErrors("histo_dati_2.dat");
  TGraphErrors *gr3 = new TGraphErrors("histo_dati_3.dat");
  TGraphErrors *gr4 = new TGraphErrors("histo_dati_4.dat");
  TGraphErrors *gr5 = new TGraphErrors("histo_dati_5.dat");
  TGraphErrors *gr6 = new TGraphErrors("histo_dati_6.dat");
  TGraphErrors *gr7 = new TGraphErrors("histo_dati_7.dat");
  TGraphErrors *gr8 = new TGraphErrors("histo_dati_8.dat");
  TGraphErrors *gr9 = new TGraphErrors("histo_dati_9.dat");
  
  gr0->SetLineColor(1);
  gr0->SetMarkerColor(1);
  gr0->SetMarkerStyle(20);
  
  gr1->SetLineColor(2);
  gr1->SetMarkerColor(2);
  gr1->SetMarkerStyle(21);
  
  gr2->SetLineColor(3);
  gr2->SetMarkerColor(3);
  gr2->SetMarkerStyle(22);
  
  gr3->SetLineColor(4);
  gr3->SetMarkerColor(4);
  gr3->SetMarkerStyle(23);

  gr4->SetLineColor(5);
  gr4->SetMarkerColor(5);
  gr4->SetMarkerStyle(24);
  
  gr5->SetLineColor(6);
  gr5->SetMarkerColor(6);
  gr5->SetMarkerStyle(25);
  
  gr6->SetLineColor(1);
  gr6->SetMarkerColor(7);
  gr6->SetMarkerStyle(26);

  gr7->SetLineColor(8);
  gr7->SetMarkerColor(8);
  gr7->SetMarkerStyle(27);
  
  gr8->SetLineColor(9);
  gr8->SetMarkerColor(9);
  gr8->SetMarkerStyle(28);
  
  gr9->SetLineColor(10);
  gr9->SetMarkerColor(10);
  gr9->SetMarkerStyle(29);
  
  
  gr0->Draw("same p");
  gr1->Draw("same l");
  gr2->Draw("same p");
  gr3->Draw("same p");
  gr4->Draw("same p");
  gr5->Draw("same p");
  gr6->Draw("same c");
  gr7->Draw("same p");
  gr8->Draw("same p");
  gr9->Draw("same p");
  
     TLegend *leg = new TLegend(0.7,0.45,0.9,0.95,NULL,"brNDC"); //this class is for the leggend
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetTextSize(0.05);
   leg->SetFillStyle(1001);
   leg->SetTextFont(132);

   leg->AddEntry(gr0,"data 0","p");
   leg->AddEntry(gr1,"data 1","l");
   leg->AddEntry(gr2,"data 2","p");
   leg->AddEntry(gr3,"data 3","p");
   leg->AddEntry(gr4,"data 4","p");
   leg->AddEntry(gr5,"data 5","p");
   leg->AddEntry(gr6,"data 6","l");
   leg->AddEntry(gr7,"data 7","p");
   leg->AddEntry(gr8,"data 8","p");
   leg->AddEntry(gr9,"data 9","p");
  
   leg->Draw();

Spettro->SaveAs("figurazza.pdf");
Spettro->SaveAs("figurazza.jpg");
Spettro->SaveAs("figurazza.tiff");
Spettro->SaveAs("figurazza.gif");
Spettro->SaveAs("figurazza.ps");
}
