#include <bits/stdc++.h>

using namespace std;

int main(){
 
 int len,d	;
 cin>>len;
 int v1[len+1];
 for(int i = 0; i < len ; i++){
  cin>>d;
  v1[i] = d;
 }
 int maximo = *max_element(v1,v1+len);
// cout<<"primer maximo "<<maximo<<endl;
 if( v1[0] == 1 && v1[len-1] == 1) cout<<"0"<<endl;
 else{
 long long int r = 0;
 for(int i = len -1 ; i >= 0 ; i--){
  if(v1[i] < maximo ) r += maximo - v1[i];
  if(v1[i] == maximo) maximo = *max_element(v1,v1+i);
 }
 cout<<r<<endl;
 }
 return 0;
}