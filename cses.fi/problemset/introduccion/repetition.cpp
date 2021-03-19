#include <bits/stdc++.h>


using namespace std;


int main(){


 string cad;
 cin>>cad;
 long long int len = cad.length();
 long long int i = 0;
 long long int s = 0, cont = 0;
 while( i < len){
  char a = cad[i]; 
  while( cad[i] == a){
   cont++; i++;
  }
  if( cont > s) s = cont;
  cont = 0;
 }
 cout<<s<<endl;
 return 0;
}