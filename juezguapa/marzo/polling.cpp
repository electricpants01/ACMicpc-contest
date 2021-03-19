#include <bits/stdc++.h>
using namespace std;

int contar( string nombres[], int n, string cad){
 int cont = 0;
 for(int i = 0; i  < n; i++){
    if( nombres[i] == cad) cont++;
 }
 return cont;
}

int main(){

int n,mayor,indice,i;
set<string> originales;
cin >>n;
string nombres[n+1];
for( int i=0; i < n; i++){
    cin >> nombres[i];
    originales.insert( nombres[i] );
}
sort(nombres,nombres + n);
mayor = 0;
indice = 0;
i = 0;
vector<int> vec;
for(set<string>::iterator it = originales.begin(); it != originales.end(); it++){
    int d = contar(nombres,n,*it);
    vec.push_back(d);
    if( mayor < vec[i] ){
        mayor = vec[i];
        indice = i;
    }
    i++;
}
int len = vec.size();
i = 0;
for( set<string>::iterator it = originales.begin(); it != originales.end(); it++){
    if( vec[i] == mayor ) cout<<*it<<endl;
    i++;
}
return 0;
}
