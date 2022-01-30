#include <bits/stdc++.h>

using namespace std;

int main(){

 cout.precision(20);
 long long int n;
 cin>>n;
 long long r = 0;
 while( n > 0){
  r += n/5;
  n /= 5;  
 }
 cout<<r<<endl;
 return 0;
}