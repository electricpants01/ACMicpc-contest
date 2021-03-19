#include <bits/stdc++.h>

using namespace std;

void mostrar(map<char,int> mp){
for(map<char,int>::iterator it = mp.begin(); it != mp.end(); it++){
 cout<<it->first<<" -> "<<it->second<<endl;
}
}

bool verifPar(map<char,int> mp){
for(map<char,int>::iterator it = mp.begin(); it != mp.end(); it++){
 if( it->second % 2 != 0 ) return false;
} 
return true;
}           

bool verifImpar(map<char,int> mp){
int cont = 0;
for(map<char,int>::iterator it = mp.begin() ; it != mp.end(); it++){
 if( it->second % 2 != 0 ) cont++;  
}
if( cont == 1 ) return true;
return false;
}

string sol(map<char,int> mp){
int len;
string r = "",u = "",rev ="";
for(map<char,int>::iterator it = mp.begin() ; it != mp.end(); it++){
 if( it->second % 2 != 0 ) u += it->first;
 int d = it->second/2;
 for( int i = 1; i <= d ; i++){
  r = r + it->first;
 }
}
if( u != "" ){
 r = r +u;
 len = r.length() - 2;  
}else len = r.length() -1;
for(int i = len ; i >= 0 ; i--){
 rev = rev + r[i];
}
return r+rev;
}                 


int main(){
string cad,r;
int len;
map<char,int> mp;
cin>>cad;
len = cad.length();
for( int i = 0 ; i < len ; i++) mp[cad[i]]++;
if( ( len % 2 == 0 && verifPar(mp)) || (len % 2 != 0 && verifImpar(mp))){
r = sol(mp);
cout<<r<<endl;
}else cout<<"NO SOLUTION"<<endl;
return 0;
}