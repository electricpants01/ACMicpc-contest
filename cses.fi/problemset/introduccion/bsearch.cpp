#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

int compararEnteros( const void *a, const void *b){
 return ( *(int*)a - *(int*)b );
}

int main(){
 int d;
 int vec[] = {10,20,30,40,50,60,70};
 int *item = NULL;
 cout<<"escriba el dato a buscar : ";
 cin >>d;
 item = (int*) bsearch(&d, vec,7,sizeof(int), compararEnteros );
 //cout<<"valor de item : "<<*item<<endl;
 if( item == NULL){
    cout<<"NO se encontro el dato\n";
 }else cout<<"SI se encontro el dato\n";
}
