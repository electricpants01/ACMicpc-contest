#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxN = 2e5;
int n;
int sol[maxN];
bool is_computed[maxN];
int coins[] = {1,3,4};

int solve(int x){
    if( x < 0 ) return 1e9;
    if( x == 0 ) return 0;
    if( is_computed[x] ) return sol[x];
    int best = 1e9;
    for(int i = 0; i < n; i++){
        best = min(best, solve( x - coins[i] )  +1);
    }
    is_computed[x] = true;
    sol[x] = best;
    return best;
}

int main() {
    n = 3;
    cout<<solve(10)<<endl;
    return 0;
}