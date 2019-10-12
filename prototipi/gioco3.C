{
TGraph *pino = new TGraph();

double x,y,step,a,b,c;
step=0.1;
a=1;
c=0.001;
TCanvas *oooh=new TCanvas("oooh","",600,600);
oooh->SetLogy();
oooh->SetLogx();
for(int i=0;i<10000;i++){
a=double(i)*step;
b=c*exp(a);
x= b*cos(a);
y= b*sin(a);
//cout<< i <<"  "<<x<<"  "<<y<<endl;
//cout<<x<<"  "<<y<<endl;
pino->SetPoint(i,x,y);
pino->Draw();
oooh->Update();

}


}
