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
  while (t--){
    ll n; cin >> n;
    if(n == 1) cout<<0<<" "<<1<<endl;
    else cout<<-(n-1)<<" "<<n<<endl;
  }
  return 0;
}