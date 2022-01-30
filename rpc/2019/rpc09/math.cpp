#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n ){
 if(n < 2 )return false;
 for(int x = 2 ; x*x <= n ; x++){
  if( n % x == 0 ) return false;
 } 
 return true;
}

int main(){

int n,d,r;
scanf("%d",&n);
d = n/2;
if( d % 2 != 0 ) d--;
r = n - d;        
for( ; isPrime(d) || isPrime(r) ; --d,r = n-d) ; 
if( d > r ) cout<<r<<" "<<d<<endl;
else cout<<d<<" "<<r<<endl;
return 0;   
}