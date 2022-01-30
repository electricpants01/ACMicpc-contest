#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MOD = 1e9 + 7;
const int maxN = 1e6 + 1;
int dp[maxN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while(t--){
    int n,k; cin >> n >> k;
    ll temp = 1, ans = 0;
    for(int i=0; i<32;i++){
      if( k & (1<<i)) ans = (ans+temp)%MOD;
      temp = (temp*n)%MOD;
    }
    cout<<ans%MOD<<endl;
  }
  return 0;
}