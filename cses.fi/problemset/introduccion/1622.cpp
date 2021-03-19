#include <bits/stdc++.h>

using namespace std;

int factorial(int d){
 if(d == 0 || d == 1 ) return 1;
 else return d * factorial(d-1);
}

int contar1(string cad, char d){ // devuelve la cantidad de letras que hay en cad
int s = 0;
int len = cad.length();
for(int i = 0 ; i < len ; i++){
 if( cad[i] == d) s++;
} 
return s;
}


int main(){
                                                             
string  cad,rep = ""; // rep se convertira la repeticion de "cad" sin letras repetidas
double r = 1;
int contar;
cin>> cad;
int len = cad.length();
for(int i = len ; i >= 1 ; i--){
 if( rep.find_first_of(cad[i-1]) == -1 ){
  rep += cad[i-1];
  contar = contar1(cad,cad[i-1]);
  r = (r * i) / factorial(contar);                  	
 }else r *= i;
}
cout<<" la cadena dada tiene "<<r<<" combinaciones sin repeticion"<<endl;
return 0;
}