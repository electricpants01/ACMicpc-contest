#include<bits/stdc++.h>

using namespace std;

int ordenar(long long int vec[],int n){
 long long int aux, cont = 0;
 for(int i = 0 ; i < n ; i++){
  for(int j = i ; j < n - 1 ; j++){
   if( vec[j] >= vec[j+1] ){
    aux = vec[i];
    vec[i] = vec[j];
    vec[j] = aux;        
    cont++;
   }
  }
 }
 return cont;
}

int main(){

 long long int n;
 cin>>n;
 long long int vec[n+1];
 long long int aux = n;
 for(int i = 0 ; i < n ; i++){
  long long int d;
  cin>>d;
  vec[i] = d;
 }
 cout<<ordenar(vec,n); 
 return 0;
}