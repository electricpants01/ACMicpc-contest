#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MOD = 1e9+7;
const int maxN = 1e6+1;
int dp[maxN];

int main(){
// 4 8 2 6 2
// 4 5 4 1 3
 int n; cin >> n;
 vector<int> a(n),b(n);
 for(auto &it: a) cin >> it;
 for(auto &it: b) cin >> it;
 vector<int> c(n);
 for(int i=0; i<n;i++){
  c[i] = a[i] - b[i];
 }
 sort(c.begin(),c.end());
 ll ans = 0;
 for(int i=0; i<n;i++){
  if( c[i] <= 0) continue;
  int index = lower_bound(c.begin(),c.end(), -c[i] +1 ) - c.begin();
  ans += i - index;
 }
 cout<<ans<<endl;
 return 0;
}