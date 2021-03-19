#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >>n;
    while(n--){
        ll a,b; cin >> a >> b;
        ll ans = 1;
        while(b){
            if(b&1){
                ans = (ans*a) % MOD;
            }
            a = (a*a)% MOD;
            b /=2;
        }
        cout<<ans<<endl;
    }

    return 0;
}
