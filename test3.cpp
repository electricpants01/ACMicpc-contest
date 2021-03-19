#include <bits/stdc++.h>

using namespace std;


struct Nodo{
  int value;
  Nodo *izq = NULL; 
  Nodo *der = NULL;
};
Nodo *raiz = NULL;

insertar(int val){
 if(raiz == NULL){
  raiz = new Nodo();
  raiz->value = val;
 }else{
 Nodo *ant;
 Nodo *aux = raiz;
 while( aux != NULL){
  ant = aux;
  if( val < aux->value) aux = aux->izq;
  else aux = aux->der;
 }
 Nodo *nuevo = new Nodo();
 nuevo->value = val; 
 if(val < ant->value ){
  ant->izq = nuevo;
 }else ant->der = nuevo;
 }
}

void mostrar( Nodo *nodo){
  if(nodo != NULL ) cout<<nodo->value<<" ";
  if( nodo->izq != NULL) mostrar(nodo->izq);
  if( nodo->der != NULL) mostrar(nodo->der); 
}



int main(){
 cout<<"Cuantos datos ? : ";
 int d; 
 cin>>d;
 while(d--){
 int a;
 cin>>a;
 insertar(a);
 }
 mostrar(raiz);
 return 0;
}