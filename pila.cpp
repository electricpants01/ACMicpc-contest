#include <bits/stdc++.h>

using namespace std;

struct Pila{
 int valor;
 Pila *sig = NULL;
};
Pila *pila = NULL;

insertar(int valor){
 if(pila == NULL){
 pila = new Pila();
 pila->valor = valor;
 }else{
 Pila *nuevo = new Pila();
 nuevo->valor = valor;
 nuevo->sig = pila;
 pila = nuevo;
 }
}

void mostrar(Pila *pila){
 while(pila != NULL){
  cout<<pila->valor<<" ";
  pila = pila->sig;
 } 
}

int lenf(){
 Pila *aux = pila;
 int c = 0;
 while(aux != NULL){
  c++;
  aux = aux->sig;
 }
 return c;
}

int pop(){
 int len = lenf();
 if(len == 0) return -1;
 int d = pila->valor;
 pila = pila->sig;
 return d;
}

void solucion(){
 int len = lenf();
 if(len % 3 != 0){
  int a,b;
  a = pop();
  b = pop();
  solucion();
  if(b != -1) insertar(b);
  if(a != -1) insertar(a);
 }else if( len % 3 == 0 && len > 0){
  int a,b,c;
  a = pop();
  b = pop();
  c = pop();
  solucion();
  insertar(a);
  insertar(b);
  insertar(c);
 }
}
int main(){
 int d;
 cout<<"cuantos datos desea meter en la pila : ";
 cin>>d;
 while(d--){
 int a; 
 cout<<"Dato a meter en la pila : "; 
 cin>>a;
 insertar(a);
 }
 mostrar(pila); cout<<endl;
 solucion();
 mostrar(pila); cout<<endl;
 return 0;
}