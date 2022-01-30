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
    int n; char c; cin >> n >> c;
    string s; cin>>s;
    int count = 0;
    for(char temp: s) if(c == temp) count++;
    if(count == n) cout<<"0"<<endl;
    else if(count == n-1){
      cout<<"1"<<endl;
      int ans = -1;
      for(int i=0; i<n && ans == -1;i++){
        if(s[i] != c) ans = i+1;
      }
      if(ans == 1) cout<<ans+1<<endl;
      else if( ans == n) cout<<ans-1<<endl;
      else cout<<ans+1<<endl;
    }else{
      // always the minimum number of operations required to make all the characters equal to c is 2
      cout<<"2"<<endl;
      cout<<n<<" "<<n-1<<endl;
    }
  }
  return 0;
}