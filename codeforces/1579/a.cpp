#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MOD = 1e9 + 7;
const int maxN = 1e6 + 1;
int dp[maxN];
map<char, int> mp;

int main() {
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t; cin >> t;
 while (t--) {
  string s; cin >> s;
  int arr[3] = {0,0,0};
  for(auto c : s ) arr[c - 'A']++;
  cout<<(arr[0] + arr[2] == arr[1] ? "YES\n" : "NO\n");
 }
 return 0;
}