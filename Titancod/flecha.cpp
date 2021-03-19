#include <bits/stdc++.h>

using namespace std;



int main(){
 string cad; int sum = -1; int cont = 0; int n;
 cin>>n;
 while(n--){
  cin>>cad;
  int len = cad.length();
  for( int i = 0 ; i < len ;){
    if( cad[i] == '>'){
      cont++;
      if( sum < cont ) sum = cont;
       i++ ; cont = 0;
     } 
     else if (cad[i] == '<'){
       cont = 1;
       char c = cad[++i];
       if( c == '-' || c == '='){
         while(c == cad[i]){
  cont++; i++;
 }
 }
       if( sum < cont ) sum = cont;
       cont = 0;
      }
      else if ( cad[i] == '-' || cad[i] == '='){
cont = 0;
         char c = cad[i];
  while(c == cad[i]){
   cont++; i++;
  }
}
   }
   cout<<sum<<'\n';
   sum = -1; cont = 0;
 }
 return 0;
}