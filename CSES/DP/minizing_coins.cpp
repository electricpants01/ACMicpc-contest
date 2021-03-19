#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MOD = 1e9+7;
const int maxN = 1e6+1;
int dp[maxN];


int main(){
    ios::sync_with_stdio(false); cin.tie();
    int n,x ; cin >> n >> x;
    int coins[n+1];
    for(int i =0; i<n;i++) cin >> coins[i];
    dp[0] = 1;
    for(int i= 1; i<=x;i++){
        for(int j =0; j<n;j++){
            if( i - coins[j] >= 0){
                dp[i] = (dp[i] + dp[i- coins[j]]) % MOD;
            }
        }
    }
    cout<<dp[x]<<endl;
    return 0;
}