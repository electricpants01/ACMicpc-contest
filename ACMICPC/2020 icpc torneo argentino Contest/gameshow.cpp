#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
//ios::sync_with_stdio(0); cin.tie(0);
    cout<<setprecision(12)<<fixed;
    int n; cin >> n;
    int arr[n];
    for(int i =0; i<n;i++) cin >>arr[i];
    int ans = 100, temp = 100;
    for(int i =0; i<n;i++){
        temp += arr[i];
        ans = max(ans , temp);
    }
    cout<<ans<<endl;
    return 0;
}