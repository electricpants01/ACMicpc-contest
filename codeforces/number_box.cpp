#include <bits/stdc++.h>
//https://codeforces.com/contest/1447/problem/B
using namespace std;
#define ll long long
typedef long long int lli;
const int mxN = 2e5;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int arr[n][m];
        int mx = 0;
        int neg = 0;
        int sum = 0;
        int mn = 2e9;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++){
                cin >> arr[i][j];
                sum += abs(arr[i][j]);
                mn = min( mn, abs(arr[i][j]));
                if( arr[i][j] < 0 ) neg++;
            }
        }
        if( neg & 1 ){ // si es impar
            sum = sum - 2*mn;
        }
        cout<<sum<<endl;

    }
    return 0;
}