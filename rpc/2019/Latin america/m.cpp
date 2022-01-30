#include <bits/stdc++.h>

using namespace std;

int main(){

int n,x,sol = 0,resul = 0;
cin>> n >> x ;
int vec[n+1];
for( int i = 1 ; i <= n ; i++ ) cin>>vec[i];
for( int i = 2 ; i <= n ; i++){
 if( (vec[i] - vec[i-1]) <= x ) resul++;
 else{       
  sol = max(sol, resul);
  resul = 0;
 }
}
sol = max( sol, resul);
cout<<sol+1<<endl;
return 0;
}