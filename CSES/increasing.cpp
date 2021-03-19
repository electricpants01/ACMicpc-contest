#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n; cin >>n;
    int arr[n];
    int mx = 0;
    ll ans = 0;
    for(int i =0; i<n; i++){
        cin >> arr[i];
        mx = ( arr[i] > mx) ? arr[i] : mx;
        ans = ans + (mx - arr[i]);
    }
    cout<<ans<<endl;
    return 0;
}