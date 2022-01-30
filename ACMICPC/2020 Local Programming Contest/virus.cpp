//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int g,p,t; cin >> g >> p >> t;
    ll groups = t * p + g;
    if( groups == (ll) g * p ) cout<<"0"<<endl;
    else if( groups < (ll) g * p) cout<<"2"<<endl;
    else cout<<"1"<<endl;
    return 0;
}

