#include <bits/stdc++.h>
using namespace std;


void freq(int a[],int n, int &d,int &m){
 int cont = 1;
 d = a[0]; m = 1;
 for(int i = 1; i < n; i++){
  while( i <n && a[i] == a[i-1] ){ cont++; i++;}
  if( cont > m){
   d = a[i-1]; m = cont;  
  }
  cont = 1;
 } 
}

int main(){
 int d,m;
 int a[] = {1,1,1,1,2,2,2,2,2,4,5,5,5,5,5,5,5};
 freq(a,17,d,m);
 cout<<"el dato de mayor frecuencia es "<<d<<endl;
 cout<<"la cantidad de veces repetidas es "<<m<<endl;
}                                       