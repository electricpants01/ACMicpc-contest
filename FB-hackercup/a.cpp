#include <bits/stdc++.h>
using namespace std;

char arr[200][200];

int contar(char arr[][200], int a, int b, int fila){
    int cont = 0;
    for(int i = a; i < b; i++){
        if( arr[fila][i] == 'Y') cont++;
    }
    return cont;
}

int main() {
    int t ; cin >> t;
    int n ;
    vector<char> input;
    vector<char> out;
    int indice = 1;
    while(t--){
        cin >> n;
        input.clear(); out.clear();
        string in,o;
        cin >> in >> o;
        for(int i =0; i < n; i++) input.push_back( in[i] );
        for(int i =0; i < n; i++) out.push_back( o[i] );
        //
        for(int i =0; i<n; i++){
            int j = i;
            arr[i][j] = 'Y';
            // izquierda
            while( --j >= 0){
                if( abs( i - j) == 1){
                    if( out[i] == 'Y' && input[j] == 'Y') arr[i][j] = 'Y';
                    else arr[i][j] = 'N';
                }else{
                    if( out[i] == 'Y' && input[j] == 'Y' && out[j+1] == 'Y' && contar(arr,j+1,i,i) == abs(i-j)-1 ) arr[i][j] = 'Y';
                    else arr[i][j] = 'N';
                }
            }
            // derecha
            j  = i;
            while( ++j < n){
                if( abs(j-i) == 1 ){
                    if( out[i] == 'Y' && input[j] == 'Y' ) arr[i][j ]= 'Y';
                    else arr[i][j] = 'N';
                }else{
                    if( out[i] == 'Y' && input[j] == 'Y' && out[j-1] == 'Y' && contar(arr,i,j,i) == abs(j-i) ) arr[i][j] = 'Y';
                    else arr[i][j] = 'N';
                }
            }
        }
        // mostrar la mitad
        cout<<"Case #"<<indice<<": "<<endl;
        for(int i =0; i<n; i++){
            for(int j =0; j < n; j++) cout<<arr[i][j];
            cout<<endl;
        }
        indice++;
    }
    return 0;
}
