#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MOD = 1e9+7;
const int maxN = 1e6+1;
int dp[maxN];

ll modP(ll a, ll b, int m){
    ll ans = 1;
    while(b){
        if(b&1){
            ans = (ans*a) % m;
        }
        a = (a*a)% m;
        b /=2;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie();
    int t; cin >> t;
    while (t--){
        ll a,b,c; cin >> a >> b >> c;
        cout<<modP( a,modP(b,c,MOD-1), MOD )<<endl;
    }
    return 0;
}
