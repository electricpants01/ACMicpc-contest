#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxN = 2e5;
int n;
int sol[maxN];
bool is_computed[maxN];
int coins[] = {1,3,4};

int main() {
    int count[maxN];
    count[0] = 1;
    int coins[] = {1,3,4};
    int n = 3;
    for( int i = 1; i <= 5; i++){ // 5 es el indice que buscamos el valor
        for(int j = 0; j < n; j++){ //recorremos las monedas disponibles
            if( i - coins[j] >= 0){ // si es mayor a cero, sumamos los valores anteriores
                count[i] += count[ i - coins[j] ];
            }
        }
    }
    cout<<count[5]<<endl;
    return 0;
}