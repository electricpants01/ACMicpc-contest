#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxN = 2e6;
const int MODULO = 1e9+7;
bool is_computed[maxN];
ll values[maxN];

int solve(int x,vector<int> &v){
    if( x < 0 ) return 1e9;
    if( x == 0 ) return 0;
    if( is_computed[x] ) return values[x];
    int n = v.size();
    int best = 1e9;
    for(int i =0; i <n; ++i){
        best = min(best, solve( x - v[i],v) +1);
    }
    is_computed[x] = true;
    values[x] = best;
    return best;
}


int main() {
    int n,x; cin >> n >> x;
    vector<int> v(n);
    for(int i =0; i<n;i++) cin >>v[i];
    int ans = solve(x,v);
    if( ans == 1e9 )cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}