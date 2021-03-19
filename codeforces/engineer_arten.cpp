#include <bits/stdc++.h>
//https://codeforces.com/contest/1438/problem/C
using namespace std;
#define ll long long
typedef long long int lli;
const int mxN = 2e5;

int main() {
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        int arr[n][m];
        for(int i =0; i<n;i++){
            for(int j =0; j<m;j++) cin >> arr[i][j];
        }
        //solucion
        for(int i=0; i<n;i++){
            for(int j =0; j<m;j++){
                if( i % 2 == 1){ //si la fila es impar
                    if( j % 2 ==0){
                        if( arr[i][j] % 2 != 0) arr[i][j]++;
                    }else{
                        if( arr[i][j] % 2 == 0) arr[i][j]++;
                    }
                }else{ // si la fila es par
                    if(j % 2 == 0){
                        if( arr[i][j] % 2 ==0) arr[i][j]++;
                    }else{
                        if( arr[i][j] % 2 !=0) arr[i][j]++;
                    }
                }
            }
        }
        //mostrar
        for(int i=0; i<n;i++){
            for(int j =0; j<m;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}