#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxN = 1e5;
const int MOD = 1e9+7;
int dp[maxN];
int coins[maxN];

int main() {
    int n,x; cin >> n >> x;
    for(int i =0; i<n; i++)
        cin >> coins[i];
    dp[0] = 0;
    for(int i =1; i<=x;i++){ // hasta X
        dp[i] = 1e9;
        for(int j=0; j<n;j++){ // hasta N
            if( i - coins[j] >= 0 ){
                dp[i] = min(dp[i], dp[i - coins[j]] +1);
            }
        }
    }
    for(int i =0; i<=x; i++) cout<<dp[i]<<" ";
    cout<<dp[x]<<endl; // imprimimos el ultimo
    return 0;
}