#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxN = 2e5;
int n,t;

int main() {
    int k[maxN];
    cin >> n >> t;
    for(int i =0; i < n; i++)
        cin >> k[i];
    ll lb = 1; ll rb = 1e18;
    while( lb < rb){
        ll mb = (lb+rb)/2;
        ll s = 0;
        for(int i =0; i < n; i++)
            s += min( mb/k[i], (ll)1e9);
        if( s >= t)
            rb = mb;
        else
            lb = mb+1;
    }
    cout<<lb<<endl;
    return 0;
}