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
 Spettro->SetLogy();
 
 TH2D *frame = new TH2D("frame","",41,-0.5,40.5,110,0,0.11);
 
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
 frame->GetXaxis()->SetTitle("Extracted card");
 frame->GetYaxis()->SetTitle("Probability");
  
 frame->Draw();
  
  TGraphErrors *gr0 = new TGraphErrors("stimaNumenD.dat");
  gr0->SetMarkerColor(1);
  gr0->SetMarkerStyle(20);
  
  TGraph *gr1 = new TGraph("stimateoricaD.dat");
  
  
  
  
  gr0->Draw("same p");
  gr1->Draw("same l");
  
     TLegend *leg = new TLegend(0.58,0.7,0.93,0.9,NULL,"brNDC"); //this class is for the leggend
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetTextSize(0.05);
   leg->SetFillStyle(1001);
   leg->SetTextFont(132);

   leg->AddEntry(gr0,"Num. Estimation","p");
   leg->AddEntry(gr1,"Theor. Estimation","l");
  
   leg->Draw();
   Spettro->SaveAs("confronto.pdf");

}
