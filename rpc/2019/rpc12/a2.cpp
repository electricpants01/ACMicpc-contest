#include <bits/stdc++.h>
// solucion = n * 2^(n-1)
// solucion % MOD
using namespace std;

typedef long long int ll;
#define MOD 1000000007ll

int main(){

int a,b,k,c;
cin>> a >> b >> k >> c;
ll res = 1;
for( int i = 1 ; i < k ; i++)  res = (res * 2 )% MOD;
res = (res * k) % MOD;
if( a != c && b != c ) res = 0;
if( a == b ) res = k;
cout<<res<<endl; 
return 0;
}