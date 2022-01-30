#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MOD = 1e9+7;
const int maxN = 1e6+1;
int dp[maxN];

int main(){
    int t; cin >> t;
    while(t--){
        int k; cin >> k;
        int x = int(ceil(sqrt(k)));
        int y = x-1;
        int diff = k - y*y;
        int row = min(diff,x);
        int col = x - max(diff-x, 0);
        cout<<row<<" "<<col<<endl;
    }
    return 0;
}