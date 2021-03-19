#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxN = 2e5;
int n,t;

int main() {
    int n; cin >> n;
    array<int,2> arr[maxN];
    for(int i =0; i < n; i++)
        cin >> arr[i][0] >> arr[i][1];
    sort( arr, arr+n);
    ll ans = 0, t = 0;
    for(int i =0; i < n; i++){
        t += arr[i][0];
        ans += arr[i][1] - t;
    }
    cout<<ans<<endl;
    return 0;
}