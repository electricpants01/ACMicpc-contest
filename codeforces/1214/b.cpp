#include <bits/stdc++.h>

using namespace std;


int main(){

 int b,g,n,sol = 0;
 cin>>b;
 cin>>g;
 cin>>n;
 if( b != g && min(b,g) >= n ) cout<<n+1<<endl;
 else{
 int j = n;
 for(int i = 0 ; i <= n ; i++ ){
   if( i <= b && j <= g) sol++;
   j--;
  }
 cout<<sol<<endl;
 }
 return 0;
}