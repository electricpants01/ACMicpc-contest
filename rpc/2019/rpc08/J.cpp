#include <bits/stdc++.h>

using namespace std;

int encontrarArriba(int dato,bool num[]){
 int n,aux,anterior;
 n = dato;
 while( n < 1000){
 aux = n;
 anterior = aux;
 while( aux > 0){
  if( num[aux % 10] ) aux /= 10;
  else break;
 }
 if(aux == 0 ) break;
 n++;
 }
 return anterior;
}

int encontrarAbajo(int dato, bool num[]){
 int n,aux,anterior;
 n = dato; 
 while( n >= 0 ){
  aux = n;
  anterior = aux;
  while(aux > 0){
   if( num[ aux % 10 ] ) aux /= 10;
   else break;
  }
  if( aux == 0 ) break;
  n--;
 }
 return anterior;
}

int main(){

 bool num[10];
 int n,d,valor;
 for(int  i = 0 ; i < 10 ; i++){ num[i] = true;}
 cin>>n;
 while(n--){
 cin>>d;
 num[d] = false;
}
 cin>>valor;
 int a = encontrarArriba(valor,num);
 int b = encontrarAbajo(valor,num);
 if( ( a - valor ) > ( valor - b ) ) cout<<(valor - b)<<endl;
 else cout<<(a - valor )<<endl; 
 return 0;
}