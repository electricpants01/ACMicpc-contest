#include <bits/stdc++.h>
 
int k;
 
using namespace std;
 
int mod(vector<int> &vec, int g){
// devuelve cero si no encuentra el rango, else devuelve 1
int i = 0, j = vec.size();
bool ban = false;
while( i <= j && ban == false){
 int m = (i+j)/2;
 if( (g-k) <= vec[m] && vec[m] <= (g+k)){
  vec.erase(vec.begin() + m );
  ban = true;   
 }
 if( g < vec[m] ) j = m-1;
 else i = m+1;
}
if( ban ) return 1;
return 0;
}
 
void mostrar(vector<int> vec){
int len = vec.size();
for(int i = 0 ; i < len ; i++) cout<<vec[i]<<" ";
cout<<endl;
}
 
int main(){
 
int n,m,d,len,cont;
vector<int> app,apt;
cin>> n >> m >> k;
for(int i = 0 ; i < n ; i++){ cin>>d; app.push_back(d);}
for(int i = 0 ; i < m ; i++){ cin>>d; apt.push_back(d);}
sort(app.begin(),app.end());
sort(apt.begin(),apt.end());
len = app.size(),cont = 0;
for(int i = 0 ; i < len ; i++){
 cont += mod(apt,app[i]);  
}
cout<<cont<<endl;
return 0;
}