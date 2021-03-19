#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxN = 2e5;
int n,t;

int main() {
    int n ; cin >> n;
    ll arr[maxN], s = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        s += arr[i];
    }
    sort(arr,arr+n);
    cout<<max( s, 2ll * arr[n-1])<<endl;
    return 0;
}