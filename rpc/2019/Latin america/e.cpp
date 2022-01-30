#include <bits/stdc++.h>

using namespace std;

int main(){

string cad;
int s,cont,j;
bool found = false;
cin>> cad >> s;
int len = cad.length();
long long int r = 0;
for(int i = 0; i < len ; i++){
 //----------------------
 if( i == (len -1) && cad[i] == 'P' ) j = -1;
 else j = i;
 //------------------------
  if( cad[i] == 'P'){
  cont = 1,found = false;
  while( cont < s && found == false){
   if( cad[j + cont] == 'E') found = true;
   else cont++;  
  }
  if( found ){
   r += s - cont;
  }
 }else if( cad[j] == 'E') r += s;
}
cout<<r<<endl;
return 0;
}
