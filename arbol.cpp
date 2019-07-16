#include <bits/stdc++.h>

using namespace std;

struct Nodo{
 char valor;
 Nodo *izq = NULL;
 Nodo *der = NULL; 
};
Nodo *raiz = NULL;

void insertar(char v){
 if(raiz == NULL){
  raiz = new Nodo();
  raiz->valor = v;
 }else{
  Nodo *nuevo = new Nodo();
  nuevo->valor = v;
  Nodo *aux = raiz;
  Nodo *anterior;
  while( aux != NULL){
   anterior = aux;
   if( aux->valor < v ) aux = aux->der;
   else aux = aux->izq;
  }
  if(anterior->valor > v) anterior->der = nuevo;
  else anterior->izq = nuevo;
 }
}

void mostrar(Nodo *nodo){
 if(nodo != NULL){
  cout<<nodo->valor<<" , ";
  if( nodo->izq != NULL ) mostrar(nodo->izq);
  if( nodo->der != NULL) mostrar(nodo->der);
 }
}

int main(){
 int d;
 cout<<"cuantos datos va meter en el arbol : ";
 cin>>d;
 while(d--){
  char a;
  cout<<"Escriba un caracter : ";
  cin>>a;
  insertar(a);
 }
 mostrar(raiz);
 return 0;
}