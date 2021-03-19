#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxN = 2e6;
int length[maxN];
int arr[maxN];

int main() {
    int n; cin >> n;
    vector<int> v;
    for(int i =0; i<n; i++){
        int a; cin >> a;
        int p = lower_bound(v.begin(), v.end(), a) - v.begin();
        if( p < v.size() ) {
            v[p] = a;
        }else{
            v.push_back(a);
        }
    }
    cout<<v.size();
    return 0;
}