#include <bits/stdc++.h>
/*
  Este algoritmo reemplaza las vocales con asteriscos
*/
using namespace std;


int main(){

string cad;
getline(cin,cad);
int d = cad.find_first_of("aeiou",0);
while( d != -1){
cad[d] = '*';
d = cad.find_first_of("aeiou",d+1);
}
cout<<cad<<endl;
return 0;
}