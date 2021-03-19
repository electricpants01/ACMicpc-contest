#include <bits/stdc++.h>
//https://codeforces.com/contest/1420/problem/C1
using namespace std;
#define ll long long
const int mxN = 1e3;
int dp[mxN][mxN];


int main() {
    int t; cin >> t;
    while(t--){
        int n, q ; cin >> n >> q;
        int arr[n];
        for(int i =0; i<n;i++) cin >>arr[i];
        ll ans = arr[0];
        for(int i =1; i<n; i++){
            ans += max(0, arr[i] - arr[i-1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}