#include <bits/stdc++.h>


using namespace std;

int main(){

int f,s; // facts , statements
string a,b,c,d,e;
bool r[500][500];
map<string,int> mp;
int cont = 0;
scanf(" %d %d",&f,&s);
for(int i = 0 ; i < f ; i++){
 cin>> a >> b >> c >> d >> e;
 if( !mp[a]) mp[a] = ++cont;
 if( !mp[e]) mp[e] = ++cont;
 r[mp[a]][mp[e]] = true; 
}
for(int k=1;k<=cont;k++){
for(int i=1;i<=cont;i++){
  for(int j=1;j<=cont;j++)x
  r[i][j] |= r[i][k]&& r[k][j];
 }
}
// mostrar
for(int i = 1 ; i <= cont; i++){
 for(int j = 1 ; j <= cont; j++){
  cout<<r[i][j]<<" ";
 }
 cout<<endl;
}
for(int i = 0 ; i < s ; i++){
 cin>> a >> b >> c >> d >> e;
 if(!mp[a] || !mp[e]){
  cout<<"Pants on Fire"<<endl;
  continue;
 }
 
}
return 0;
}