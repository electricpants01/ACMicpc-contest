#include <bits/stdc++.h>
// https://codeforces.com/contest/886/problem/B
using namespace std;
#define ll long long

int main(){
    int n; cin >>n;
    int arr[n];
    set<int> s;
    for(int i =0; i< n; i++) cin >> arr[i];
    int ans = arr[0];
    for(int i = n-1; i>=0; i--){
        if( s.count( arr[i] ) == 0){
            ans = arr[i];
            s.insert( arr[i] );
        }
    }
    cout<<ans<<endl;
    return 0;
}