#include <bits/stdc++.h>

using namespace std;

int mayor(int a[]){
 int may = a[0];
 for(int i = 0; i < 26 ; i++){
  if( may < a[i]){
  may = a[i];
 }
 }
 return may;
}        // para saber que valor repetido mas del abecedario

int main(){
 
 vector<string> cad;
 int num ;
 string name;
 cin>>num;
 for(int i= 0 ; i < num ; i++){
 cin>>name;
 cad.push_back(name);  
}
 int len = cad.size();
 int a[26];
 for(int i = 0 ; i < 26 ; i++) a[i] = 0; // casillas del alfabeto en cero
 for(int i = 0 ; i < len; i++){
  name = cad[i];
  int d = int(name[0]);
  a[d-97] += 1;
 }
 vector<int> vec;
 long long int r = 0;
 for(int i = 0 ; i < 26 ; i++ ){
  //  cout<<a[i]<<endl;
  if(a[i] > 0 ) vec.push_back(a[i]);
 } 
 int len2 = vec.size();
 for(int i = 0 ; i < len2 ; i++){
  long long int n = vec[i]/2;
  long long int m = vec[i] - n;
  n = n*(n-1) /2;
  m= m*(m-1) /2;
  r += (n+m);
 }
 cout<<r<<endl;
 return 0;
}