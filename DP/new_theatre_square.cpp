#include <bits/stdc++.h>
//http://codeforces.com/problemset/problem/1359/B
using namespace std;
#define ll long long
const int MX = 1e5;
int dp[MX];


int main() {
    int t; cin >> t;
    int n,m,x,y;
    while(t--){
        cin >> n >> m >> x >> y;
        int ans = 0;
        for(int i=0; i<n; i++){
            string cad; cin >>cad;
            if( 2*x < y ){
                for(int i =0;i<m;i++){
                    if( cad[i] == '.' ) ans += x;
                }
            }else{
                for( int i=0; i<m;i++){
                    if( i+1 < m){
                        if( cad[i] == '.' && cad[i+1] == '.'){
                            ans += y;
                            i++;
                            continue;
                        }
                    }
                    if( cad[i] == '.' ){
                        ans += x;
                    }
                }
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}