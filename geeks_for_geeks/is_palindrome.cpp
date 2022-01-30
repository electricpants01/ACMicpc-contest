#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MOD = 1e9 + 7;
const int maxN = 1e6 + 1;
int dp[maxN];
map<char, int> mp;

bool solve(string cad){
 int n = cad.size();
 int last = n-1;
 for(int i=0; i<(n-1)/2;i++){
  if(cad[i] != cad[last]) return false;
  last--;
 }
 return true;
}

int main() {
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 string cad; cin >> cad;
 if(solve(cad)) cout<<"yes\n";
 else cout<<"no\n";
 return 0;
}