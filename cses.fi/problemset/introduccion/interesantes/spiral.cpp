// este algoritmo es interesante

#include <bits/stdc++.h>

using namespace std;

long double encontrar(long double d){
 long double r = 1 + ((d-1)*(d-1) + (d-1));
 return r;
}

int main(){
 
 cout.precision(20); 
 // ya generamos los datos de la matriz diagonal principal, ahora viene el algoritmo
 long long int n,i,j;
 long double r;
 cin>>n;
 while(n--){
  cin>>i;
  cin>>j;
  if( i == j) r = encontrar(i);
  if( j > i){
   if( j % 2 != 0){
  // cout<<"j es mayor"<<endl;
  // cout<<encontrar(j);
    r = encontrar(j) + (j - i );
   }else{
    r = encontrar(j) - ( j - i );
   }
  }else if( i > j){
   if( i % 2 != 0 ){
    r = encontrar(i) - ( i - j );
   }else{
    r = encontrar(i) + ( i - j );
   }   
  }
  cout<<r<<endl;
 }
 return 0;
}