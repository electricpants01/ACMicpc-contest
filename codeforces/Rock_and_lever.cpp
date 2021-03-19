#include <bits/stdc++.h>
//https://codeforces.com/contest/1420/problem/B
using namespace std;
#define ll long long
const int mxN = 1e3;
int dp[mxN][mxN];


int main() {
    int t; cin >> t ;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        map<int,int> mp;
        ll ans = 0;
        for(int i =0; i<n;i++){
            cin >> v[i];
            int clz = __builtin_clz(v[i]);
            ans += mp[ clz ];
            mp[ clz ] += 1;
        }
        cout<<ans<<endl;

    }
    return 0;
}