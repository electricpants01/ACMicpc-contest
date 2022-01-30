#include <bits/stdc++.h>
/*creado por christian torrico avila
 * crear un mapa map<int,Nodo> de cada valor con el indice inicial y el indice final de cada valor unico
 *poner el mapa en un vector<Nodo> y ordenarlos por sus indices finales
 * recorrer el vector cuando v[i].start > end, si es verdad entonces ans++
 * luegos la respuesta sera ( v.size() - ans);
 */
using namespace std;
#define ll long long
struct Nodo{
    int start,end;
};

int main(){
//ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int arr[n];
    for(int i =0; i<n;i++) cin >> arr[i];
    map<int, Nodo> mp;
    for(int i=0; i<n;i++){
        if( mp.count(arr[i]) == 0 ){ // si no existe, añadir un minimo
            mp[arr[i]].start = i;
        }
        mp[arr[i]].end = i; //siempre cambiamos el maximo de cada valor
    }
    vector<Nodo> v;
    for( auto it : mp){
        Nodo temp; temp.start = it.second.start;
        temp.end = it.second.end;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), [](const Nodo a, const Nodo b){ return a.end < b.end; });
    int ans = 0, final = -1;
    for(int i=0; i<v.size();i++){
        if(v[i].start > final){
            ans++;
            final = v[i].end;
        }
    }
    cout<<v.size()-ans<<endl;
    return 0;
}
