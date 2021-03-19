#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/1249/problem/B1
int main() {
    int t,n; cin >> t;
    while(t--){
        cin >> n;
        int arr[n];
        bool sol[n];
        for(int i =0; i<n; i++) sol[i] = true;
        for(int i =0; i<n; i++) cin >> arr[i];
        sort(arr,arr+n);
        sol[n-1] = false;
        for(int i = n-1; i > 0; i--){
            if( abs(arr[i]- arr[i-1]) > 1 ) sol[i-1] = false;
        }
        bool ban = false;
        for( int i = n-1; i >= 0; i--) if( sol[i] ) ban = true;
        if( ban ) cout<<"2"<<endl;
        else cout<<"1"<<endl;
    }
    return 0;
}
