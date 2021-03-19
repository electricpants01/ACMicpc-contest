#include <bits/stdc++.h>

using namespace std;

int main(){

int n,m;
string cad2;
char abc[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s',
't','u','v','w','x','y','z'};
cin >> n;
while(n--){
 cin>> m;
 string cad = "",str = "";
 int cont = 0;
 while(m--){ cin>> cad2; cad += cad2;}
 for( int i = 0 ; i < 26; i++){
  if( cad.find_first_of(abc[i]) != -1) cont++;
  else str += abc[i];
 } 
 if( cont == 26 ) cout<<"OK\n";
 else cout<<str<<endl; 
}
return 0;
}