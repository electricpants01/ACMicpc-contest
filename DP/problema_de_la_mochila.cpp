#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN = 1e3;
int dp[mxN][mxN];

struct Nodo{
    int weight;
    int value;
};

int main() {
    vector<Nodo> v; int n; cin >> n;
    int total_sum;
    for(int i =0; i<n; i++){
        int a,b; cin >> a >> b;
        Nodo temp;
        temp.value = a;
        temp.weight = b;
        v.push_back(temp);
    }
    sort(v.begin(),v.end(), []( Nodo a, Nodo b){ return a.value < b.value; });
    cin >> total_sum;
    for(int i =0; i < n; i++) dp[i][0] = 0;
    for(int j =1; j <= total_sum; j++) dp[0][j] = v[0].value;
    for(int i= 1; i < n; i++){
        for(int j =1; j <= total_sum; j++){
            if( v[i].weight <= j ){
                dp[i][j] = max( dp[i-1][j], dp[i-1][ j - v[i].weight ] + v[i].value ); //Incluyendo y excluyendo el PESO
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for (int i =0; i < v.size(); i++) cout<<v[i].value<<" ";
    cout<<endl;
    for(int i =0; i<n; i++){
        for(int j =0; j <= total_sum; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[n-1][total_sum]<<endl;
    return 0;
}