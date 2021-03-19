#include <bits/stdc++.h>
//https://codeforces.com/contest/1440/problem/A
using namespace std;
#define ll long long
const int mxN = 2e5;


int main() {
    int t; cin >> t;
    while(t--){
        int n,a,b,h; cin >> n >> a >> b >> h;
        string cad; cin >> cad;
        int mn = 0;
        for( int i =0; i<n;i++){
            if( cad[i] == '0'){
                mn = min( mn + a, mn + h + b );
            }else{
                mn = min( mn + b, mn + h + a);
            }
        }
        cout<<mn<<endl;
    }
    return 0;
}