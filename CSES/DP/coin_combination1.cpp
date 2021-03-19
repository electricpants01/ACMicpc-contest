#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxN = 2e6;
const int MODULO = 1e9+7;
bool is_computed[maxN];
ll values[maxN];

int main() {
    int n,x; cin >> n >> x;
    vector<int> coins(n);
    for(int i =0; i<n;i++) cin >>coins[i];
    values[0] = 1;
    for(int i =1; i<=x;i++){
        for(int j =0; j<n;++j){
            if( i - coins[j] >= 0)
                values[i] = (values[i] + values[ i - coins[j]])  % MODULO;
        }
    }
    cout<<values[x]<<endl;
    return 0;
}