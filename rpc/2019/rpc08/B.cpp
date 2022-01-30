#include <bits/stdc++.h>
#include <string>
using namespace std;


int main(){

 string cad;
 int n;
 bool ban = true;
 int cont = 1;
 cin>>n;
 while( n-- ){
  cin>>cad;
  string d;
  stringstream ss;
  ss << cont;
  d = ss.str();
  if( cad == "mumble" || cad == d ) cont++;
  else ban = false;
 }
 if( ban ) cout<<"makes sense"<<endl;
 else cout<<"something is fishy"<<endl;
 return 0;
}