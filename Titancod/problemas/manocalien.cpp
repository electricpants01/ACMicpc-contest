#include <bits/stdc++.h>

using namespace std;

void mostrar(vector<int> vec){
 int len = vec.size();
 for(int i = 0 ; i < len ; i++){
 cout<<vec[i]<<endl;
 }
}

double suma(vector<int> vec){
 int len = vec.size();
 double r = 0;
 for(int i = 0 ; i < len ; i++){
   if( vec[i] > 0) r++;
 }
 return r;
}
int main(){

string cad;
vector<int> vec;
 for(int i = 0 ; i < 4 ;i++) vec.push_back(0);
 int g = 0,indice = 0;
 while(cin >> cad){
 g++;
 int len = cad.length();
 int cont = 0;
 for(int i = 0 ; i < len ;){
  if( cad[i] == '1'){
  while( cad[i] == '1'){ cont++; i++;}
  if(cont > 4 ){ vec[indice]++; continue;}
  }
  cont = 0; i++;
 }
 indice++;
 if( g == 4){
 mostrar(vec);
 double r = double(suma(vec)*100)/double(vec.size()); 
 cout<<r<<endl;
 vec.clear(); indice = 0 ; g = 0;
 for(int i = 0 ; i < 4 ;i++) vec.push_back(0);
 }
 } 
return 0;
}