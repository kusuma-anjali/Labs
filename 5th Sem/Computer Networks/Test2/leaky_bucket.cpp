#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

#define bksize 256

void bkleaky(int a,int b){
  if(a>bksize)
    cout<<"\t\toverflow\n";
  else{
    //usleep(500);
    while(a>b){
      //usleep(500);
      cout<<"\n\t\t"<<b<<"bytes outputted";
      a=a-b;
    }
    if(a>0)
      cout<<"\n\t\tlast "<<a<<" bytes sent";
      cout<<"\n\t\tsuccesfull\n";
  }
}

int main(){
  int op,pk[]={100, 345, 230,78, 980, 130, 7, 89, 670, 256};
  cout<<"enter outdata rate:\n";
  cin>>op;
  for(int i=0;i<10;i++){
    cout<<"Packet "<<i+1<<" Packet size:"<<pk[i]<<"\n";
    bkleaky(pk[i],op);
    usleep(5000);
  }
  return 0;
}
