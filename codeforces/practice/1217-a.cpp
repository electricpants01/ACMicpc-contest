#include <bits/stdc++.h>

using namespace std;

int main(){

 int t,str,intel,xp;
 cin>>t;
 while(t--){
  cin>>str;
  cin>>intel;
  cin>>xp; 
  int j = xp;
  int sol = 0;
  for(int i = 0 ; i<= xp ; i++){
   if( str+ j > intel + i) sol++;
   if( intel + i > str + j ) break;
   j--;
 }
  cout<<sol<<endl;
 }
 return 0;
}