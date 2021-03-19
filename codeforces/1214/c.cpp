#include <bits/stdc++.h>

using namespace std;
// comentario
// si n es impar entonces cout<<"NO";

int main(){

 int n;
 string s;
 cin>>n;
 cin>>s;
 long long int i = 0 ;

 while(n-- && (i+2)){
  if( s[n] == ')' ) i++;
  else i--;
 }
 //cout<<"i es = "<<i<<endl;
 if(i) cout<<"No\n";
 else cout<<"Yes\n";
 return 0;
}