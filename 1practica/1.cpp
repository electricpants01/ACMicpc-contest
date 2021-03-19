#include <bits/stdc++.h>

using namespace std;

void func(){
 cout<<"-----mostrar---------\n";
 cout<<" 1 para ver la matriz\n";
 cout<<" 2 para intercambiar fila y columna\n";
 cout<<" 5 para salir\n";
}                      

void mostrar(int a[][100],int f,int c){
 for(int i = 0; i < f; i++){
  for(int j = 0; j < c; j++){
   cout<<a[i][j]<<" ";
  }
  cout<<endl;
 }
}

void intercambiar(int a[][100],int f,int c, int f1, int f2){
  for(int i = 0; i < c; i++){
   int d = a[f1][i];
   a[f1][i] = a[f2][i];
   a[f2][i] = d;
  }  
}

int main(){
 int f,c,d;
 cin>> f >> c;
 int a[100][100];
 for(int i = 0; i < f ; i++){
  for(int j = 0; j < c; j++){
   a[i][j] = rand() % 9 + 1;
  }
 }
 func();
 while( cin>>d){
  if( d == 1) mostrar(a,f,c);  
  if( d == 2){
   int f1,f2; 
   cout<<"intercambiar fila # "; cin>>f1;
   cout<<"con la fila # "; cin>>f2;
   intercambiar(a,f,c,f1,f2);
   mostrar(a,f,c);
  }
  func();
 } 
 return 0;
}