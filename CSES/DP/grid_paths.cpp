#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxN = 1e3;
const int MOD = 1e9+7;
string cad[maxN];
int dp[maxN][maxN];

int main() {

    int n; cin >> n;
    for(int i =0; i<n;i++)
        cin >> cad[i];
    dp[0][0] = 1;
    for(int i =0; i < n; i++){
        for(int j =0; j<n; ++j){
            if(i)
                dp[i][j] += dp[i-1][j];
            if(j)
                dp[i][j] += dp[i][j-1];
            dp[i][j] %= MOD;
            if( cad[i][j] == '*')
                dp[i][j]  = 0;
        }
    }
    cout<<dp[n-1][n-1];
    return 0;
}