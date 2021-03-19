#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Nodo{
    int x,y;
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    vector<Nodo> v;
    while(t--){
        int n,k; cin >> n >> k;
        for(int i=0;i<n;i++){
            int x, y; cin >> x >> y;
            Nodo temp; temp.x = x; temp.y = y;
            v.push_back(temp);
        }
        bool ans = false;
        for(int i =0; i<n && !ans;i++){
            int cont =0;
            for(int j=0;j<n;j++){
                if( (abs(v[i].x - v[j].x) + abs(v[i].y - v[j].y)) <= k ) cont++;
            }
            if( cont == n) ans = true;
        }
        if(ans) cout<<"1"<<endl;
        else cout<<"-1"<<endl;
        v.clear();
    }
    return 0;
}

/*
 * La distancia entre dos puntos dado k, es -> (abs(x1 - x2 ) + abs(y1 - y2)) <= k
 */