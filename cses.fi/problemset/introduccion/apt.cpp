// apartments task 1084
#include <bits/stdc++.h>
using namespace std;

int main(){
int n,m,k;
cin >>n >> m >> k;
int app[n+1];
int apt[m+1];
for(int i = 0 ; i < n ; i++) cin>>app[i];
for(int i = 0 ; i < m ; i++) cin>>apt[i];
sort(app,app+n);
sort(apt,apt+m);
int indice = 0,cont = 0;
for(int i = 0 ; i < m;){
    if(indice == n ) break;
    if( app[indice] - k <= apt[i] && apt[i] <= app[indice] + k){
        cont++; indice++; i++;
    }
    if( app[indice] - k > apt[i] ) i++;
    if( app[indice] + k < apt[i] ) indice++;
}
cout<<cont<<endl;
return 0;
}
