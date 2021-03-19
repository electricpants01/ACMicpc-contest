#include <bits/stdc++.h>
//https://codeforces.com/contest/1452/problem/B
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll ans = 0, sum = 0, mx = 0;
        for(int i =0; i <n; i++){
            ll temp; cin >> temp;
            sum += temp;
            mx = max(mx, temp);
        }
        ans = ceil((double) sum / (n-1)) * (n-1);
        ans = max( ans, mx * (n-1));
        cout<<ans-sum<<endl;
    }
    return 0;
}