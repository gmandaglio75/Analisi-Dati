int program() {
	double a;

	TGraphErrors *etna = new TGraphErrors("etna_errori.dat");
	TGraphErrors *etna2 = new TGraphErrors("etna_errori.dat");
	TCanvas *canv1 = new TCanvas();

	TF1 *f1 = new TF1("f1","[0]/(pow((pow(x,2)-pow([1],2)),2)+(pow([1],2)*pow([2],2)))+[3]",21.5,22.5);
	f1 -> SetParameters(20000,22,1,2);
	f1 -> SetParNames("a1","b1","c1","d1");
	f1 -> SetLineColor(2);
	f1 -> SetLineStyle(2);

	TF1 *f2 = new TF1("f2","[0]/(pow((pow(x,2)-pow([1],2)),2)+(pow([1],2)*pow([2],2)))+[3]",22.8,24.2);
	f2 -> SetParameters(10000,23.5,1,2);
        f2 -> SetParNames("a2","b2","c2","d2");
        f2 -> SetLineColor(2);
        f2 -> SetLineStyle(2);

	TF1 *f3 = new TF1("f3","[0]/(pow((pow(x,2)-pow([1],2)),2)+(pow([1],2)*pow([2],2)))+[3]",24.3,24.8);
        f3 -> SetParameters(10000,24.5,1,2);
        f3 -> SetParNames("a3","b3","c3","d3");
        f3 -> SetLineColor(2);
        f3 -> SetLineStyle(2);

	TF1 *f4 = new TF1("f4","[0]/(pow((pow(x,2)-pow([1],2)),2)+(pow([1],2)*pow([2],2)))+[3]",26.5,29.);
        f4 -> SetParameters(10000,27.5,1,2);
        f4 -> SetParNames("a4","b4","c4","d4");
        f4 -> SetLineColor(2);
        f4 -> SetLineStyle(2);

	TF1 *f5 = new TF1("f5","[0]/(pow((pow(x,2)-pow([1],2)),2)+(pow([1],2)*pow([2],2)))+[3]",29.,32.);
        f5 -> SetParameters(10000,31.5,1,2);
        f5 -> SetParNames("a5","b5","c5","d5");
        f5 -> SetLineColor(2);
        f5 -> SetLineStyle(2);

	TF1 *f6 = new TF1("f6","[0]/(pow((pow(x,2)-pow([1],2)),2)+(pow([1],2)*pow([2],2)))+[3]",34.5,36.5);
        f6 -> SetParameters(10000,35.5,1,2);
        f6 -> SetParNames("a6","b6","c6","d6");
        f6 -> SetLineColor(2);
        f6 -> SetLineStyle(2);

	TF1 *f7 = new TF1("f7","[0]/(pow((pow(x,2)-pow([1],2)),2)+(pow([1],2)*pow([2],2)))+[3]",51.4,52.);
        f7 -> SetParameters(10000,51.7,1,2);
        f7 -> SetParNames("a7","b7","c7","d7");
        f7 -> SetLineColor(2);
        f7 -> SetLineStyle(2);
	
	TF1 *f8 = new TF1("f8","pol1",10.,59.);
        f8 -> SetParameters(1,0);
        f8 -> SetParNames("ba","bb");
        f8 -> SetLineColor(2);
        f8 -> SetLineStyle(2);
	

	TF1 *f9 = new TF1("f9","[0]*exp(-x/[1])",5.5,9.);
	f9 -> SetParameters(0.1,1);
        f9 -> SetParNames("ea","eb");
        f9 -> SetLineColor(2);
        f9 -> SetLineStyle(2);

	TF1 *fsomma = new TF1("fsomma","f1+f2+f3+f4+f5+f6+f7+f8+f9",5.1,58.);
	fsomma -> SetLineColor(1);
	fsomma -> SetLineStyle(1);
	fsomma -> SetLineWidth(2);
	fsomma -> SetFillColor(0);

	Double_t par[32];
	etna -> Draw();
	etna -> Fit("f1","R");
	etna -> Fit("f2","R+");
	etna -> Fit("f3","R+");
	etna -> Fit("f4","R+");
	etna -> Fit("f5","R+");
	etna -> Fit("f6","R+");
	etna -> Fit("f7","R+");
	etna -> Fit("f8","R+");
	etna -> Fit("f9","R+");

	f1 -> GetParameters(&par[0]);
	f2 -> GetParameters(&par[4]);
	f3 -> GetParameters(&par[8]);
	f4 -> GetParameters(&par[12]);
	f5 -> GetParameters(&par[16]);
	f6 -> GetParameters(&par[20]);
	f7 -> GetParameters(&par[24]);
	f8 -> GetParameters(&par[28]);
	f9 -> GetParameters(&par[30]);

	//fsomma -> GetParameters(&par[0]);

	Double_t par2[32];
	
	par2[14] = par[28];
	par2[30] = par[30];
	par2[15] = par[29];
	par2[31] = par[31];
	for(int i=0;i<28;i++){
		if(i%4 == 0){
			par2[i/4] = par[i];
		}
		if((i-1)%4 == 0){
			par2[(i-1)/4+7] = par[i];
		}
		if((i-2)%4 == 0){
			par2[(i-2)/4+16] = par[i];
		}
		if((i-3)%4 == 0){
			par2[(i-3)/4+23] = par[i];
		}
	}
	
	fsomma -> Draw("same");
	canv1 -> SaveAs("grafico_con_fsomma_iniziale.pdf");

	fsomma -> SetParameters(par2);
	etna -> Fit("fsomma","R+");
        etna2->Draw(); 
        fsomma->SetLineColor(4);
	fsomma -> Draw("same");
	
	canv1 -> SaveAs("fit.pdf");

	return 0;
}
