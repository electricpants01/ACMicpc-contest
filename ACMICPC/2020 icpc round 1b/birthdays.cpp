#include <bits/stdc++.h>
/*
 * la entrada de datos pueden ser string repetidos, nosotros solo buscamos
 * el tamaño (size) de las cadenas no repetidas
 */
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    set<string> s;
    int n; cin >> n;
    for(int i =0; i<n;i++){
        string cad; cin >> cad;
        s.insert(cad);
    }
    cout<<s.size()<<endl;
    return 0;
}
