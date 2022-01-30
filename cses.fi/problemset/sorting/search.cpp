#include <bits/stdc++.h>

// BINARY SEARCH

using namespace std;

int main(){

int n;
cin>>n;
int d[] = {1,2,3,4,5,6,7};
int i = 0,j = 7; // j es len total
bool ban = false;
while( i <= j && ban == false){
 int m = i + j /2;
 if( n == d[m]){ ban = true; break;}
 if( n < d[m] ) j = m-1;
 else i = m+1;
} 
if( ban ) cout<<"Si se encontro"<<endl;
else cout<<"No se encontro"<<endl;
}