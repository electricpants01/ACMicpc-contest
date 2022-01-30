#include <bits/stdc++.h>
using namespace std;
     
int main(){
// cin >> cad;
// ordenar cad;
// vector set ; datos unicos de cad;
// vector de frecuencia del set
// strfinal = myset[i]*frec
string cad; char d,cont = 0;
cin>>cad;
int len = cad.length();
vector<int> frec;
vector<char> vec; 
sort(cad.begin(),cad.end());
for(int i = 0 ; i < len ;){
 d = cad[i];
 cont = 0;
 vec.push_back(cad[i]);
 while( cad[i] == d ){ cont++; i++;}
 frec.push_back(cont);  
}                                                          
len = vec.size();
for(int i = 0 ; i < len -1 ; i++){
 for(int j = i+1; j < len ; j++){
  if( frec[i] < frec[j] ){ // intercambiar
   int aux = frec[i]; frec[i] = frec[j];  frec[j] = aux; // ordenamos las frecuencias
   char aux2 = vec[i]; vec[i] = vec[j]; vec[j] = aux2; // ordenamos los caracteres
  }
  if( frec[i] == frec[j] && vec[i] > vec[j]){
   int aux = frec[i]; frec[i] = frec[j];  frec[j] = aux; // ordenamos las frecuencias
   char aux2 = vec[i]; vec[i] = vec[j]; vec[j] = aux2; // ordenamos los caracteres
   }
 }
}             
string nuevo = "";
for(int i = 0 ; i < len ; i++){
 string cod(frec[i],vec[i]);
 nuevo += cod;
}
cout<<nuevo<<endl;
return 0;
}