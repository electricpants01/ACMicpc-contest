#include <bits/stdc++.h>
// este algoritmo se resuelve facilmente usando la estructura map
using namespace std;

int encontrari(string cad, int n, char d){
 for(int i = 0; i < n ; i++){
  if( cad[i] == d) return i;
 }
 return -1;
}


int main(){
string cad;
int n;
map<char,int> mp;
while(cin >> n && n != 0){
cin >> cad;
int len = cad.length();
for(int i = 0 ; i < len ; i++){
 mp[cad[i]]++;
}
map<char,int>::iterator it = mp.begin();
int menor = it->second;
char men = it->first;
for( ; it != mp.end(); it++){ // encontrar el valor menor
 if( it->second < menor ){
  menor = it->second;
  men = it->first;    
 }
}                              
cout<<encontrari(cad,len,men)+1<<endl;
mp.clear();
}
return 0;
}