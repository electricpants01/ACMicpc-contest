#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MOD = 1e9+7;
const int maxN = 1e6+1;
int dp[maxN];

int main(){
    // first we solve using brute force all the posible answers
    int init = 0;
    int arr[1001];
    for(int i = 1; i<=1000;i++){
        while(init % 3 == 0 || init %10 == 3 )init++;
        arr[i] = init;
        init++;
    }
    // we will print the answer calculated before hand
    int t; cin >> t;
    while(t--){
        int k; cin >> k;
        cout<<arr[k]<<endl;
    }
    return 0;
}