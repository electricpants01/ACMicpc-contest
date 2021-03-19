#include <bits/stdc++.h>
//https://codeforces.com/contest/1431/problem/A
using namespace std;
#define ll long long
const int mxN = 1e3;
int dp[mxN][mxN];
int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<ll,ll> mp;
        for(int i =0; i<n;i++){
            ll d; cin >> d;
            mp[d]++;
        }
        ll ans =0;
        int i = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            ans = max( (n-i) * it->first, max(ans , it->first * it->second) );
            i += it->second;
        }
        cout<<ans<<endl;
    }
    return 0;
}