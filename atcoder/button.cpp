#include <bits/stdc++.h>

// https://atcoder.jp/contests/abc124/tasks/abc124_a
using namespace std;


int main(){
 int a,b;
 cin>>a;
 cin>>b;
 int s = 0 ;
 int may;
 if(a > b){
  s = a;
  a--;
  if( a > b){
   s += a;
  }else{
   s+=b;
  }
 }else{
 s = b;
 b--;
 if(b > a ){
  s+=b;
 }else{
  s+=a;
 }
 }
 cout<<s<<endl;	
 return 0;
}