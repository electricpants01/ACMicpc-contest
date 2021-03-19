#include <bits/stdc++.h>

using namespace std;

struct Nodo{
  int valor;
  Nodo *izquierda = NULL;
  Nodo *derecha = NULL;
};

Nodo *raiz = NULL;

void insertar(int d){
 if(raiz == NULL){
  raiz = new Nodo();
  raiz->valor = d;
 }else{
  Nodo *aux = raiz;
  Nodo *anterior;
  while( aux != NULL){
   anterior = aux;
   if( aux->valor > d) aux = aux->izquierda;
   else aux = aux->derecha;
  }
   Nodo *nuevo = new Nodo();
   nuevo->valor = d;
  if( anterior->valor > d ) anterior->izquierda = nuevo;
  else anterior->derecha = nuevo;  
 }
}

void mostrar(Nodo *aux){
 cout<<aux->valor<<" ";
 if(aux->izquierda != NULL ) mostrar(aux->izquierda);
 if(aux->derecha != NULL) mostrar(aux->derecha);
}

int main(){

 int n;
 cin>>n;
 while(n--){
 int d;
 cout<<"introduzca un valor : ";
 cin>>d; 
 insertar(d); 
 }
 mostrar(raiz);
 return 0;
}