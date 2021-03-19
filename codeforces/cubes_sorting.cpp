#include <bits/stdc++.h>
//https://codeforces.com/contest/1420/problem/A
using namespace std;
#define ll long long
const int mxN = 1e3;
int dp[mxN][mxN];


int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        for(int i =0; i<n;i++) cin >> v[i];
        bool ban = true;
        for(int i =0; i < n-1 ; i++){
            if( v[i] <= v[i+1]){
                ban = false;
                break;
            }
        }
        cout<<( ban ? "NO" : "YES")<<endl;
    }
    return 0;
}