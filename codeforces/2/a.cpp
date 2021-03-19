#include <bits/stdc++.h>
// ESTE ALGORITMO ESTA MAL, EL CORECTO ES a2.cpp

using namespace std;

bool siNombre(vector<string> nombre, string cad){ // verifica si esta el nombre
 for(vector<string>::iterator it = nombre.begin() ; it != nombre.end() ; it++){
  if(*it == cad) return true;
 } 
 return false;
} 

int buscarNombre(vector<string> nombre, string cad){ // retorna el indice de donde se encuentra el nombre
 int len = nombre.size();
 for(int i = 0 ; i < len ; i++){
  if( nombre[i] == cad) return i;
 }
 return -1;
}                
    
int main(){
 string cad;
 vector<string> nombre;
 int puntos[1001];
 for(int i = 0 ; i< 1001; i++) puntos[i] = 0;
 int n,v,winner = 0;            
 cin>>n;
 //
 while(n--){
  cin>>cad;
  cin>>v;
  if( !siNombre(nombre,cad)) nombre.push_back(cad);
  int d = buscarNombre(nombre,cad);
  puntos[d] += v;
  if( puntos[winner] < puntos[d] ) winner = d;
 }
 cout<<nombre[winner]<<endl; 
 return 0;
}