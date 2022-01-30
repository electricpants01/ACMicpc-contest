#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int mxN = 1e3;
int dp[mxN][mxN];


int main() {
    int g,p,t; cin >> g >> p >> t;
    int total = g*p;
    int parcial = p*t+g;
    if( total == parcial) cout<<"0"<<endl;
    else if( total < parcial ) cout<<"1"<<endl;
    else cout<<"2"<<endl;
    return 0;
}