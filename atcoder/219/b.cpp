#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MOD = 1e9+7;
const int maxN = 1e6+1;
int dp[maxN];


int main(){
 string a1,a2,a3; cin >> a1 >> a2 >> a3;
 string cad[3] = {a1,a2,a3};
 string q; cin >> q;
 string ans = "";
 for(int i=0; i<q.size(); i++){
  int curr = q[i] - '0';
  ans += cad[curr-1];
 }
 cout<<ans<<endl;
 return 0;
}