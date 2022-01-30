#include <bits/stdc++.h>
// this gives wrong answer :/
using namespace std;
#define ll long long int
const int MOD = 1e9+7;
const int maxN = 1e6+1;
int dp[maxN];

int main(){
    int n; cin >> n;
    vector<string> v;
    ll mx = -1;
    for(int i =0; i<n;i++){
        string d; cin >> d;
        v.push_back(d);
        int len = d.length();
        if(mx < len ) mx = len;
    }
    ll ans = 0;
    for(int i =0; i<n;i++){
        ans += (mx-v[i].length());
    }
    cout<<ans<<endl;
    return 0;
}