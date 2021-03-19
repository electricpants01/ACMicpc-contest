#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxN = 2e5;
int n;
int sol[maxN];
bool is_computed[maxN];
int coins[] = {1,3,4};

int main() {
    n = 3;
    sol[0] = 0;
    for(int i =1; i <= 10; i++){
        sol[i] = 1e9;
        for(int j =0; j < n; j++){
            if( i - coins[j] >= 0){
                sol[i] = min( sol[i], i - coins[j] +1 );
            }
        }
    }
    cout<<sol[2]<<endl;
    return 0;
}