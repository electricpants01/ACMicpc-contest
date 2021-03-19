#include<bits/stdc++.h>

#define ll long long int
using namespace std;
const int mxN = 1e5;
int dp[mxN];

int main() {
    int n,x; cin >> n >> x;
    int h[n],s[n];
    for(int i =0; i<n; i++)
        cin >> h[i];
    for(int i=0; i<n;i++)
        cin >> s[i];
    for(int i=0; i<n; i++){
        for(int j=x; j>=h[i];--j){
            dp[j] = max(dp[j], dp[j-h[i]] + s[i]);
        }
    }
    cout<<dp[x]<<endl;
    return 0;
}
