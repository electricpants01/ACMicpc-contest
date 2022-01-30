#include <iostream>
#include <stdio.h>
using namespace std;

int main(){

 int n,m;
 cin>>n;
 cin>>m;
 int vec[n+1];
 int dp[n+1];
 for(int i = 1; i <= n; i++) scanf("%d", &vec[i]);
 for(int i = 1; i <= m; i++) dp[i] = 0;
 for(int i = m+1; i <= n; i++) dp[i] = max( vec[i] + dp[i-m], dp[i-1]);
 cout<<dp[n]<<endl;    
 return 0;
}