#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/1249/problem/B1
int main() {
    int t ; cin >> t;
    int n;
    vector<int> sol;
    while( t--){
        cin >> n;
        int arr[n+1];
        for(int i =1; i<=n; i++) cin >> arr[i];
        for(int i =1; i<=n; i++){
            int ans = 0;
            int j = i;
            while( true ){
                ans++;
                j = arr[j];
                if( j == i ) break;
            }
            sol.push_back(ans);
        }
        for( auto x : sol) cout<<x<<" ";
        cout<<endl;
        sol.clear();
    }
    return 0;
}
