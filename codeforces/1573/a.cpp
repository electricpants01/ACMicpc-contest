#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MOD = 1e9+7;
const int maxN = 1e6+1;
int dp[maxN];
map<char,int> mp;

// codeforces A


int main(){
 int t; cin >> t;
 while(t--){
  int n; cin >> n;
  string cad; cin >> cad;
  ll ans = 0;
  if(cad[n-1] != '0'){
   ans += cad[n-1]-'0';
   cad[n-1] = '0';
  }
  for(int i=0; i<n-1; i++){
   if(cad[i] != '0'){
    ans += cad[i]-'0'+1;
   }
  }
  cout<<ans<<endl;
 }
 return 0;
}