#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, q ; cin >> n >> q ;
    long long int arr[n+1];
    for(int i =0; i< n; i++){
        cin >> arr[i+1];
        arr[i+1] += arr[i];
    }
    while(q--){
        int a, b; cin >> a >> b, a--;
        cout<< arr[b] - arr[a]<<endl;
    }
    return 0;
}