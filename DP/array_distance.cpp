#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxN = 1e3;
const int MOD = 1e9+7;
ll dp[maxN][maxN];

int main() {
    int n,m ; cin >> n >> m ;
    int a[n+1];
    for(int i =0; i<n;i++ )cin >>a[i];
    for(int i =0; i<n; i++){
        if(i){
            for(int j =0; j<m;j++){
                dp[i][j] = dp[i-1][j];
                if(j){
                    dp[i][j] += dp[i-1][j-1];
                }
                if(j<m-1){
                    dp[i][j] += dp[i-1][j+1];
                }
                dp[i][j] %= MOD;
            }
        }else{
            for(int j=0; j<m;j++)
                dp[0][j] = 1;
        }
        if( a[i] != 0 ){
            for(int j=0; j<m;j++){
                if( j ^ a[i]){
                    dp[i][j] = 0;
                }
            }
        }
    }
    for(int i =0; i<=m;i++) {
        for (int j = 0; j <= m; j++) cout << dp[i][j] << " ";
        cout << endl;
    }
    ll ans = 0;
    for(int i =0; i<m; i++){
        ans += dp[n-1][i];
    }
    cout<<ans<<endl;
    return 0;

}