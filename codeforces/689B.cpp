#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cout << setprecision(12)<<fixed;
    int t; cin >> t;
    while (t--){
        int n,m; cin >> n >>m;
        string arr[n];
        for(int i =0; i<n;i++) cin >> arr[i];
        vector<vector<int>> v(n, vector<int>(m,INT_MAX));
        for (int f = 0; f < n; ++f) {
            int cont = 0;
            for (int c = 0; c < m; ++c) {
                if( arr[f][c] == '*') cont++;
                else cont = 0;
                v[f][c] = min(v[f][c],cont);
            }
            cont = 0;
            for( int c = m-1; c >= 0; --c){
                if( arr[f][c] == '*') cont++;
                else cont = 0;
                v[f][c] = min(v[f][c],cont);
            }
        }
        int ans = 0;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                for (int k = r; k < n; ++k) {
                    if( v[k][c] <=  k-r) break;
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
