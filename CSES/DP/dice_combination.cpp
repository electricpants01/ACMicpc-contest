#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MOD = 1e9+7;
const int maxN = 1e6+1;
int dp[maxN];

int main(){
    ios::sync_with_stdio(false); cin.tie();
    dp[0] = 1;
    int n; cin >> n;
    for(int i=1; i<=n;i++){
        for(int j =1; j<= 6; j++){
            if(i-j >= 0){
                dp[i] = (dp[i] + dp[i-j]) % MOD;
            }
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
