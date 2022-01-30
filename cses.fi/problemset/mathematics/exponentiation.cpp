#include <bits/stdc++.h>

using namespace std;

// https://cses.fi/problemset/task/1095

const int modulo = 1000000000 +7;                              

long long int divide(int a, int b){
 if ( b == 0)  return 1;
 if( b == 1 ) return a;
 long long int r = divide(a , b / 2);
 r *= r; 
 r %= modulo;
 if( b % 2 != 0 ) r *= a;
 r %= modulo;
 return r;
}


int main(){
 int a,b,c;
 cin>>a;
 while(a--){
 cin>>b;
 cin>>c;
 long long int r = divide(b,c);
 cout<<r<<endl;
 }                        
 
 return 0;
}