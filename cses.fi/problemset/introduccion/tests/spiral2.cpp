#include <bits/stdc++.h>

// https://cses.fi/problemset/task/1071

using namespace std;

int main(){

long long int t,a,b;
long long int r;
cin>>t;
while(t--){
 cin>> a >> b;
 if( a > b){
  if( a % 2 == 0 ) r = (a*a) - b + 1;
  else r = (a-1)*(a-1) + b;
 }else{
  if( b % 2 == 0 ) r = (b-1)*(b-1) + a;
  else r = (b*b) - a + 1;
 } 
 cout<<r<<endl;
}
return 0;
}