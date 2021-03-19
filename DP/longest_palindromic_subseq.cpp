#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN = 1e3;
int dp[mxN][mxN];
int main() {
    string cad; cin >> cad;
    int n = cad.length();
    for(int i =0; i<n;i++) dp[i][i] = 1;
    for(int i = 1; i < n; i++){
        int fil = 0;
        for( int j = i; j < n; j++){
            if( cad[fil] != cad[j]){
                dp[fil][j] = max( dp[fil][j-1] , dp[fil+1][j] );
            }else{ //ambas si son iguales
                dp[fil][j] = dp[fil+1][j-1] + 2;
            }
            fil++; // incrementacmos la fila
        }
    }
    // la solucion es dp[0][n-1]; en la parte superior derecha
    for(int i =0; i<n;i++){
        for(int j= 0; j<n;j++) cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}