#include <bits/stdc++.h>
// https://codeforces.com/contest/886/problem/B
using namespace std;
#define ll long long

int main(){
    int n = 6;
    vector<int> v;
    int sum =0;
    for(int i =0; i< n; i++){
        int d; cin >> d;
        sum += d;
        v.push_back(d);
    }
    sort(v.begin(), v.end());
    //cout<<"la suma total es: "<<sum<<endl;
    if( sum % 2 == 0){
        for(int i =0; i<= n-3; i++){
            for(int j = i+1; j <= n-2; j++){
                for(int k = j+1; k < n; k++){
                    //cout<<"triple: "<<v[i]<<" "<<v[j]<<" "<<v[k]<<endl;
                    if( sum - ( v[i] + v[j] + v[k] ) == (v[i] + v[j]) + v[k]){
                        cout<<"YES"<<endl;
                        return 0;
                    }
                }
            }
        }
        cout<<"NO"<<endl;
    }else cout<<"NO"<<endl;
    return 0;
}