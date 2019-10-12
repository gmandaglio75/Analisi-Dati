{
  stringstream ss; //to manipulate the string name for our use
 char name[2];

   for(int i=0; i<8;i++){
    ss<<"f"<<i;
    ss>>name;
    ss.clear();
    cout<<name<<endl;
   }

}
