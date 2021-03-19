#include <bits/stdc++.h>
//https://codeforces.com/contest/1447/problem/C
using namespace std;
#define ll long long
const int mxN = 2e5;

int main() {
    int t; cin >> t;
    while(t--) {
        ll a, parcial = -1, total_sum = 0;
        vector<int> v;
        int n; long long int w; cin >> n >> w;
        for(int i =0; i<n;i++){
            cin >> a;
            if( a > w) continue;
            if( a >= (w+1)/2){
                parcial = i+1;
            }else if( total_sum + a < w) {
                v.push_back(i+1);
                total_sum += a;
            }
        }
        if( parcial != -1){
            cout<<"1"<<endl;
            cout<<parcial<<endl;
        }else if( total_sum >= (w+1)/2){
            cout<<v.size()<<endl;
            for( int i=0; i<v.size(); i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }else{
            cout<<"-1"<<endl;
        }
    }
    return 0;
}