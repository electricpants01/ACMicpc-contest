#include <bits/stdc++.h>
// https://cses.fi/problemset/task/1083

using namespace std;

long long int sol(bool arr[],long long int n){
 long long int s = -1;
 for(int i = 1 ; i <= n ; i++){
  if( arr[i] == false) {s = i; break;}
 }
 return s;
}

int main(){

 long long int d;
 cin>>d;
 long long int n = d;
 bool arr[d+1];
 for(int i = 1; i <= d ; i++){ arr[i] = false;}
 while(--d){
 long long int x;
 cin>>x; 
 arr[x] = true;
 } 
 long long int s = sol(arr,n);
 cout<<s<<endl;
 return 0;
}