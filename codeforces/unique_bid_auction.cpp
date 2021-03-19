#include <bits/stdc++.h>
//https://codeforces.com/contest/1454/problem/B
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<int,int> mp;
        vector<pair<int,int>> v;
        for(int i =1; i<=n;i++){
            int d; cin >> d;
            v.push_back(make_pair(i,d));
            mp[d]++;
        }
        int temp = 1e9+7;
        for( auto a : mp){
            if( a.second == 1){
                temp = min(temp, a.first);
            }
        }
        if( temp == 1e9+7 ){
            cout<<"-1"<<endl;
        }else{
            for(auto x : v){
                if( x.second == temp){
                    cout<<x.first<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}