#include <bits/stdc++.h>

using namespace std;

int main(){

int n;
string cad;
cin >> n;
getline(cin,cad); // se usa para dar un salto de linea, y no almacena nada
while(n--){
 getline(cin,cad);
 int d = cad.find_first_of("AEIOUaeiou");
 while( d != -1){
  cad[d] = '-';
  d = cad.find_first_of("AEIOUaeiou",d+1);
 }
 cout<<cad<<endl;
}
return 0;
}