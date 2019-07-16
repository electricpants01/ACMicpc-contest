#include <bits/stdc++.h>

using namespace std;


int main(){
 long long int n,i,m,p = 0,q = 0;
 cin>>n;
 i = n+2;
 m = n+4;
 while(true){ 
 p = ((i-1)*(i) - n*(n-1))/2;	// (n*(n+1) - m*(m+1))/2
 q = ((m)*(m+1) - i*(i+1))/2;
 if(p != q){
  if(p > q){
   m++;  
  }else{
   i++; m++;
  }
 } else{
  break;
 } 
 }
 cout<<n<<" "<<i<<" "<<m<<endl;
 return 0;
}