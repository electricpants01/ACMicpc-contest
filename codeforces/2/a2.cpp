#include <bits/stdc++.h>


using namespace std;

int main(){

string nombres[1001];
int i, puntos[1001],n,m = -2000000000;
map<string,int> a,b; 

scanf("%d",&n);
for( i = 0; i < n ; ++i){ 
 cin>>nombres[i] >> puntos[i];
 a[nombres[i]] += puntos[i];
}
map<string,int>::iterator it = a.begin();
for( ; it != a.end(); it++){
 m = max( m , it->second);
}                                                                         
for( i = 0 ; i < n ; i++){
 b[nombres[i]] += puntos[i];
 if( a[nombres[i]] >= m && b[nombres[i]] >= m ) break;
}
// for( i = 0 ; a[nombres[i]] < m || (b[nombres[i]] += puntos[i]) < m ; ++i ) ;
cout<<nombres[i]<<endl;

return 0;
}