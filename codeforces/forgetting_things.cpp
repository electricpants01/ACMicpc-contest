#include <bits/stdc++.h>
// https://codeforces.com/contest/1225/problem/A
using namespace std;

int main(){

int a,b; cin >> a >> b;
if( a == 9 && b == 1) cout<<a<<" "<<b*10<<endl;
else if( (b-a) < 0 || (b-a) > 1 ){
 cout<<-1<<endl;
}else{
 if( a == b){
  cout<<a*10<<" "<<b*10+1<<endl;
 }else{
  cout<<a*10+9<<" "<<b*10<<endl;
 }
}
return 0;
}