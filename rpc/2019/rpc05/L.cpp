#include <bits/stdc++.h>


using namespace std;

int bf(vector<int> &cajero){
 int len = cajero.size();
 int men = cajero[0];
 int indice =0;
 for(int i = 0 ; i < len ; i++){
  if( cajero[i] < men){ 
   men = cajero[i]; 
   indice = i;
  }
 }
 return indice; 
}

int main(){

 int caj; //cajeros
 int c,imen;  // customers
 cin>>caj;
 cin>>c;
 vector<int> vec;
 for(int i = 0 ; i < c ; i++){
 int d;
 cin>>d;
 vec.push_back(d);
 }
 vector<int> cajero(caj,0); // la cantidad de cajeros y tiempo en cero                 
 for(int i = 0 ; i < c ; i++){
  imen = bf(cajero);
  cajero[imen] += vec[i];
  cout<<imen+1;
  if(i == c-1 ) cout<<endl;
  else cout<<" "; 
 }
 // cout<<endl;
 return 0;
}