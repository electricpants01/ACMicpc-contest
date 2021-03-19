#include <bits/stdc++.h>
//https://codeforces.com/contest/1440/problem/B
using namespace std;
#define ll long long int
const int mxN = 2e5;

int main() {
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        int arr[n*k+1];
        for(int i=0; i < n*k;i++) cin >> arr[i];
        int median = n / 2 + 1;
        ll ans  =0;
        int p = n*k-median;
        for(int i =0; i<k; i++){
            ans += arr[p];
            p -= median;
        }
        cout<<ans<<endl;
    }
    return 0;
}