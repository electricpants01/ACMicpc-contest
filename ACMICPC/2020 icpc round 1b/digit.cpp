#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll freq(int n, int d){
    ll ans =0;
    while( n > 0){
        if( d == n%10) ans++;
        n /=10;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int a, b, d; cin >> a >> b >> d;
    ll ans =0;
    for(int i=a; i<=b;i++){
        ans += freq(i,d);
    }
    cout<<ans<<endl;
    return 0;
}
