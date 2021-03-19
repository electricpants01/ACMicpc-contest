#include <bits/stdc++.h>
//https://contest.yandex.com/snws2020/contest/16518/problems/F/
using namespace std;
#define ll long long
const int mxN = 1e3;
int dp[mxN][mxN];

int main() {
    int n,k; cin >> n >> k;
    double ans = 0;
    for(int i =0; i<k; i++){
        double nans = 0;
        for(int j =1; j<=n; j++){
            nans += max( (double)j, ans);
            cout<<"nans: "<<nans<<endl;
        }
        nans /= n;
        ans = nans;
    }
    cout<<fixed<<setprecision(12)<<ans<<endl;
    return 0;
}