#include <bits/stdc++.h>

using namespace std;


int next(int g){
 if( g == 1 ) return 3;
 int a = 0,b = 1,d = 0;
 while(d != g ){
  d = a+b;
  a = b;
  b = d;
 }
 return (a+b);
}

int main(){

 cout<<"cant de filas y columnas "<<endl;
 int n,m,a;
 scanf("%d %d", &n,&m);
 int vec[n][m];
 for(int i = n ; i > 0 ; i--){
  (i == n) ? a = 1 : a = next( vec[i+1][m]);
  for(int j = m ; j > 0 ; j--){
   vec[i][j] = a;
   a = next(a);    
  }      
 }
 // mostrar
 for(int i = 1 ; i <= n ; i++){
  for(int j = 1 ; j <= m; j++){
   cout<<vec[i][j]<<" ";
  }
  cout<<endl;
 }
 return 0;
}