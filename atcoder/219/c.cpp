#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MOD = 1e9+7;
const int maxN = 1e6+1;
int dp[maxN];
map<char,int> mp;



int main(){
 string x; cin >> x;
 for(int i=0; i<x.size(); i++) mp[x[i]] = i;
 int n; cin >> n;
 vector<string> vec(n);
 for(auto &x: vec) cin >> x;
 sort(vec.begin(), vec.end(),[](string a,string b){
     int lena = a.size(); int lenb = b.size();
     int lenMin = min(lena,lenb);
     for(int i=0; i< lenMin; i++){
      if( a[i] == b[i]) continue;
      return mp[a[i]]<mp[b[i]];
     }
     return a < b;
 });
 for(auto &x: vec) cout<<x<<endl;

 return 0;
}