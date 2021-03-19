#include <bits/stdc++.h>
using namespace std;
#define ll long long
// Codeforces ROUND 12
/*La version facil C1 Erricht-Tac-Toe
 *la solucion esta en obtener un patron de diagonales y poner la frecuencias de 'X' en un arreglo de longitud 3
 *la diagonal con el menor valor sera la menor cantidad de cambios para hacer del juego un empate ( o sea que no haiga ganador )
 *debemos cambiar todos los indices (i+j)%3 por el caracter 'O'
 */

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string arr[n];
        int temp[] = {0,0,0};
        for(int i=0; i<n;i++) cin >> arr[i];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if( arr[i][j] == 'X'){
                    temp[(i+j)%3]++;
                }
            }
        }
        int mn = int(min_element(temp, temp+3) - temp); //el indice con el menor valor del arreglo
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if( arr[i][j] == 'X'){
                    if( (i+j)%3 == mn ) arr[i][j] = 'O';
                }
            }
        }
        for(int i=0;i<n;i++) cout<<arr[i]<<endl;
    }
    return 0;
}
