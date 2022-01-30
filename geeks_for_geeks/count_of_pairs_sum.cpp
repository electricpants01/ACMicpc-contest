#include <bits/stdc++.h>
/*
 * Count of pairs to sum S
 */
using namespace std;
#define ll long long
const int mxN = 1e3;
int dp[mxN][mxN];

int countPairs(int arr[], int n, int sum){
    // creamos un mapa con las frecuencias
    map<int,int> mp;
    for(int i =0; i<n;i++){
        mp[ arr[i] ]++;
    }
    // recorremos el array
    int ans = 0;
    for(int i =0; i<n;i++){
        ans += mp[ sum - arr[i] ];
        if( sum - arr[i] == arr[i]) ans--; // CUIDADO: si sum == 2*arr[i] no debe suceder
    }
    return ans;
}

int main() {
    int n, sum; cin >> n >> sum;
    int arr[n];
    for(int i =0; i<n;i++ ) cin >> arr[i];
    cout<<countPairs(arr,n,sum)<<endl;
    return 0;
}