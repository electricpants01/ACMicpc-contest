#include <bits/stdc++.h>
/*
 * El problema se reduce en ver q intervalos se sobreponen el uno al otro,
 * primeramente ordenar ascendentemente por el inicio del objeto, si un objeto esta en el rango del otro entonces
 * se deben sumar sus alturas, cuando dejen de sobreponerse entonces el valor actual se reiniciara ( curr = 0)
 */
using namespace std;
#define ll long long

struct Nodo{
    int inicio, fin, vertical;
};

int main(){
//ios::sync_with_stdio(0); cin.tie(0);
    int base, n; cin >> base >> n;
    vector<Nodo> v;
    for(int i=0; i<n;i++){
        int a,b,c; cin >> a >> b >> c;
        Nodo temp; temp.inicio = c; temp.fin = a; temp.vertical = b;
        v.push_back(temp);
    }
    sort(v.begin(),v.end(), [](const Nodo a , Nodo b){ return a.inicio < b.inicio;});
    int mx = v[0].inicio + v[0].fin;
    int ans =  0, curr = v[0].vertical;
    for(int i = 1; i<n;i++){
        if( v[i].inicio <  mx ){
            curr += v[i].vertical;
        }else{
            ans = max(ans, curr);
            curr = 0;
        }
        mx = max(mx, v[i].inicio + v[i].fin);
    }
    ans = max(ans, curr);
    cout<<ans<<endl;
    return 0;
}
