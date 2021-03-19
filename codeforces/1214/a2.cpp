#include <bits/stdc++.h>


using namespace std;


int main(){

 int n,d,e;
 cin>>n;
 cin>>d;
 cin>>e;
 int ans = n % d;
 int cant = 0 ;
 int bf = ans;
 while(n >= 0 ){
  ans = min(ans , n % d );
  n -= 5*e;
  if ( bf != ans ) cant++;
 }
 cout<<"cantidad de euros son : "<<cant<<endl; 
 cout<<ans<<endl;
}