#include <bits/stdc++.h>
//https://codeforces.com/contest/1431/problem/B
using namespace std;
#define ll long long
const int mxN = 1e3;
int dp[mxN][mxN];
bool ban[101];

int main() {
    int t ; cin >> t;
    while(t--) {
        string cad;
        cin >> cad;
        int n = cad.length();
        int ans = (cad[0] == 'w') ? 1 : 0;
        for (int i = 1; i < n; i++) {
            if (cad[i] == 'w') {
                ans++;
                ban[i] = true;
            } else if (cad[i] == 'v' and ban[i - 1] == false) {
                ans++;
                ban[i] = true;
            }
        }
        cout << ans << endl;
    }
    return 0;
}