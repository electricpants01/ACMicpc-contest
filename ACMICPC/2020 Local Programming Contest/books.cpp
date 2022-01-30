#include <bits/stdc++.h>
// falta aprender la logica del algoritmo
using namespace std;
#define ll long long
struct Nodo{
    ll width, height;
};

int main(){
//ios::sync_with_stdio(0); cin.tie(0);
    int n,k; cin >> n >> k;
    ll dp[n+1]; // costo minimo usando todas las cajas
    vector<Nodo> v;
    for(int i=0;i<n;+i++){
        ll a,b; cin >> a >> b;
        Nodo temp; temp.width = a; temp.height = b;
        v.push_back(temp);
    }
// relleanos dp como si tuvieramos una caja
    ll h =0, w = 0;
    for(int i=0;i<n;i++){
        h = max(h, v[i].height);
        w += v[i].width;
        dp[i] = h*w;
    }
//
    ll temp[n]; // nuevo arreglo dp llamado temp para cuando tengamos >= 2 cajas q poner
    for(int i=1; i<k;i++){
        for(int j=i; j<n;j++){
            temp[j] = v[j].height * v[j].width + dp[j-1];
            //cout<<"temp[j]: "<<temp[j]<<endl;
            h = v[j].height;
            w = v[j].width;
            for(int prev = j-1; prev > i-1; prev--){
                h = max(h, v[prev].height);
                w += v[prev].width;
                ll ans = h*w + dp[prev-1];
                cout<<"ans: "<<ans<<" h: "<<h<<" w: "<<w<<" temp[j]: "<<temp[j]<<endl;
                temp[j] = min(temp[j],ans);
            }
        }
    }
    for(int i =0;i<n;i++) cout<<temp[i]<<" ";
    return 0;
}

