#include <bits/stdc++.h>

using namespace std;


int main(){
 cout.precision(20);
 int n; 
 const long long int m = 1e9+7; 
 cin>>n;
 long long int r = 1;
 for(int i = 0 ; i < n ; i++){
  r = (r * 2) % m ;
 }
 cout<<r<<endl;
 return 0;
}