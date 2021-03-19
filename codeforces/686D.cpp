#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> sol(1000,1);
        int n2 = 1;
        for(ll i = 2; i*i <= n; i++){
            if( n % i == 0){
                int cont = 0;
                while( n % i == 0){
                    cont++;
                    n /= i;
                }
                n2 = max(n2,cont);
                for(int k = 0; k < cont; k++) sol[k] = sol[k] * i;
            }
        }
        sol[0] *= n;
        sol.resize(n2);
        reverse(sol.begin(),sol.end());
        cout<<sol.size()<<endl;
        for(int i =0; i< sol.size(); i++) cout<<sol[i]<<" ";
        cout<<endl;
    }
    return 0;
}