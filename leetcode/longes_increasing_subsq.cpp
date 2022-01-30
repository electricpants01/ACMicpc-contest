#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MOD = 1e9+7;
const int maxN = 1e6+1;
int dp[maxN];
// https://leetcode.com/problems/number-of-longest-increasing-subsequence/submissions/

int findNumberOfLIS(vector<int>& nums) {
 int n = nums.size();
 if( n <= 1) return n;
 vector<int> lis(n,1), count(n,1);
 for(int j=1; j<n;j++){
  for(int i=0; i<j;i++){
   if( nums[i] < nums[j]){
    if( lis[i] >= lis[j]){
     lis[j] = lis[i] +1;
     count[j] = count[i];
    }else if(lis[j] == lis[i] +1){
     count[j] += count[i];
    }
   }
  }
 }
 int longest = *max_element(lis.begin(),lis.end());
 int ans = 0;
 for(int i=0; i<n;i++){
  if(lis[i] == longest) ans += count[i];
 }
 return ans;
}

int main(){
 vector<int> vec = {1,3,5,4,7};
 cout<<findNumberOfLIS(vec)<<endl;
 return 0;
}