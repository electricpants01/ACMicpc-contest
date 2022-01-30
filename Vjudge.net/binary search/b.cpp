#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MOD = 1e9+7;
const int maxN = 1e6+1;
int dp[maxN];

int main(){

 int n,m; cin >> n >> m;
 vector<pair<int,int>> play;
 vector<int> arr;
 int left = 0;
 for(int i=0; i<n;i++){
  int c,t; cin >> c >> t;
  play.emplace_back(left, left+c*t-1);
  arr.push_back(left);
  left += c*t;
 }
 for(int i=0; i<m;i++){
  int query; cin >> query;
  auto it = lower_bound(arr.begin(),arr.end(),query-1);
  if(it != arr.end()){
   int index = it - arr.begin();
   if(play[index].first <= query-1 && query-1 <= play[index].second ){
    cout<<index+1<<endl;
   }
   else if( play[index-1].first <= query-1 && query-1 <= play[index-1].second) cout<<index<<endl;
  }else{
   int index = it-arr.begin()-1;
   if( play[index].first <= query-1 && query-1 <= play[index].second) cout<<index+1<<endl;
  }
 }
 return 0;
}