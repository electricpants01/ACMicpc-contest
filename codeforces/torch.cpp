#include<bits/stdc++.h>
//https://codeforces.com/problemset/problem/1418/A
#define ll long long int
using namespace std;
const int MOD = 1e9+7;


long long int ceil_div(int64_t a, int64_t b) {
    return (a + b - 1) / b;
}

int main(){
    ll t,y,x,k; cin >> t;
    while(t--){
        cin >> x >> y >> k;
        ll ans = ceil_div( y*k + k-1, x-1 );
        ans += k;
        cout<<ans<<endl;
    }
    return 0;
}
