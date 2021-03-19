#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >>n;
        int arr[n+1];
        map<int,int> mp;
        for(int i =0; i<n;i++){
            cin >> arr[i];
            mp[arr[i]]++;
            if(i){
                if( arr[i] == arr[i-1]) mp[arr[i]]--;
            }
        }
        mp[arr[0]]--;
        mp[arr[n-1]]--;
        int mn = 1e9+7;
        for( auto x : mp){
            mn = min(mn, x.second);
        }
        cout<<mn+1<<endl;
    }
    return 0;
}