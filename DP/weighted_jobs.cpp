#include <bits/stdc++.h>
//https://www.youtube.com/watch?v=zFe-SX7jzDs&list=PLeIMaH7i8JDjMEB-b2I8NGcKMFZc85djW&index=4
using namespace std;
#define ll long long
struct Nodo{
    int start;
    int end;
    int cost;
};

int main() {
    vector<Nodo> v; int n; cin >> n;
    for(int i =0; i< n; i++){
        int a,b,c; cin >> a >> b >> c;
        Nodo temp;
        temp.start = a;
        temp.end = b;
        temp.cost = c;
        v.push_back(temp);
    }
    sort(v.begin(),v.end(), []( Nodo a , Nodo b){ return a.end < b.end; });
    //
    int dp[100];
    for(int i =0; i<n; i++) dp[i] = v[i].cost;
    for(int i = 1; i<n;i++){
        for(int j =0; j<i; j++){
            if( v[j].end <= v[i].start ){
                dp[i] = max( dp[j] + v[i].cost, dp[i] );
            }
        }
    }
    for(int i =0; i<n; i++) cout<<dp[i]<<" ";
    cout<<endl;
    return 0;
}