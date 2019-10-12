{
double P[40];

for(int i =0; i<40; i++){
P[i]=1;
}
P[0]=0.1;

for(int i =1; i<40; i++)
{
for(int j=0; j<i;j++){
P[i]-=P[j];
}
P[i]=P[i]/10.;
}
ofstream scrivo("stimateoricaD.dat");
for(int i =0; i<40; i++){
scrivo<<i+1<<"  " <<P[i]<<endl;
}


}
