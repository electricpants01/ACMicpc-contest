#include <bits/stdc++.h>
using namespace std;

int main(){
string cad;
cin>>cad;
int counts[ 'z' + 1 ];
int len = cad.length();
for(int i = 'a'; i <= 'z'; i++) { counts[i] = 0;}
for(int i = 0 ; i < len ; i++){
    counts[ cad[i] ]++;
}

while(true){
    char michar = 0;
    int max = 0;
    //obtenemos el mayor en orden descendiente ya que nuestro array es de a - z
    for(char i = 'a' ; i <= 'z'; i++){
        if( max < counts[i] ){
            max = counts[i];
            michar = i;
        }
    }
    // si el valor de max es cero entonces ya mostramos todo
    if( max == 0) break;
    string cod(max,michar); // ver la documentacion "string c++"
    cout<<cod;
    counts[ michar ] = 0; // cuando ya mostramos el caracter de mas frecuencia, entonces nos deshacemos de ese valor
}
cout<<endl;
 return 0;
}
