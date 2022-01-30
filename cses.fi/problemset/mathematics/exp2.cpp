#include <bits/stdc++.h>

using namespace std;


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
 
long long int power(int a , int b){
 if (b == 0) return 1;
 if(b == 1) return a;
 long long int r = power(a, b/2);
 r *= r;  
 if( b % 2 != 0 ) r *= a;
 return r;
}           


int main(){
 int a,b,c,d;
 cin>>a;
 while(a--){
 cin>>b;
 cin>>c;
 cin>>d;
 long long int r = power(c,d);
 long long int s = divide(b,r);
 cout<<s<<endl;
 }                        
 
 return 0;
}