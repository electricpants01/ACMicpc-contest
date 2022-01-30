//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;cin>>t;
    ll etrump = 0;
    ll eclinton = 0;
    ll sumtrump = 0;
    ll sumclinton = 0;
    while(t--){
        int e, v1,v2; cin >> e >> v1 >> v2;
        if( v1 > v2 ) eclinton++;
        if( v2 > v1) etrump++;
        sumclinton += v1;
        sumtrump += v2;
    }
    if( sumclinton > sumtrump && eclinton > etrump ) cout<<"1"<<endl;
    else if( sumtrump > sumclinton && etrump > eclinton) cout<<"2"<<endl;
    else cout<<"0"<<endl;
    return 0;
}

