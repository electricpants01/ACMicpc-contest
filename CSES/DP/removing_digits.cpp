#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxN = 2e6;
ll values[maxN];

int main() {
    int n; cin >> n;
    for(int i= 1; i <=n; i++){
        int i2 = i;
        values[i] = 1e9;
        while( i2 > 0){
            values[i] = min(values[i], values[ i - i2%10 ] + 1);
            i2 /=10;
        }
    }
    cout<<values[n]<<endl;
    return 0;
}