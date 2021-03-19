#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MX = 1e5;
int dp[MX];


int main() {
    string cad;
    int d; cout<<"Introduzca la cadena a enciptar : ";
    cin >> cad;
    cout<<"Introduzca el valor numerico: ";
    cin >> d;
    int len = cad.length();
    for(int i =0; i<len; i++){
        if( cad[i] >= 'A' && cad[i] <= 'Z'){
            cad[i] += d;
            if( cad[i] > 'Z') cad[i] -= 26;
        }
    }
    cout<<"Cadena encriptada"<<endl;
    cout<<cad<<endl;
    return 0;
}