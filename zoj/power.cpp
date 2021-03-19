#include <bits/stdc++.h>

using namespace std;

double power(double a, int n){
 double ret = 1; 
 while(n){
  if( n % 2 == 1 ) ret *= a;
  a *= a ; n /=2;
 }
 return ret;
}

int main(){

 double a;
 int n;
 cin>>a;
 cin>>n; 
 double r = power(a,n);
 cout<<r<<endl; 
 return 0;
}

