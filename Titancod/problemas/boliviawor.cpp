#include <bits/stdc++.h>

using namespace std;

int main(){

int n;
string cad;
cin>> n;
while(n--){
cin >> cad;
int cont = 0,d;
string vec[7] = {"B","O","L","I","V","I","A"};
for(int i = 0 ; i < 7 ; i++){
 int d = cad.find_first_of(vec[i]);  // d es la posicion donde se encontro vec[i]
 if( d != -1){
  cad[d] = 'Z'; cont++;
 }
}
if( cont == 7 ) cout<<"ES POSIBLE\n";
else cout<<"NO ES POSIBLE\n";

}
}