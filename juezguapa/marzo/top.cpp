#include <bits/stdc++.h>
using namespace std;


int main(){

int n,cont;
cin >> n;
string team1[n+1];
string team2[n+1];
for(int i = 0 ; i < n; i++) cin >> team1[i];
for(int i = 0 ; i < n; i++) cin >> team2[i];
for(int i = 0 ; i < n;){
    cont = 0;
    if( team1[i] == team2[i]){
        cout<<"1"<<endl; i++;
        continue;
    }
    while( team1[i] != team2[i] ){
        cont++; i++;
    }
    cout<<cont<<endl;
}
return 0;
}
