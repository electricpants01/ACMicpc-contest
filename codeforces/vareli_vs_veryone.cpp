#include <bits/stdc++.h>
//https://codeforces.com/contest/1438/problem/B
using namespace std;
#define ll long long
typedef long long int lli;
const int mxN = 2e5;

int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >>n;
        set<int> s;
        for(int i =0; i<n;i++){
            int d; cin >> d;
            s.insert(d);
        }
        if(s.size() == n) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}