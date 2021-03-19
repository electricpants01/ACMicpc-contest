#include <bits/stdc++.h>
using namespace std;


int main(){
    string cad; cin>> cad;
    int maxx = 1; int i =0;
    while( i < cad.length()){
        int j = i; int cont = 0;
        while( j < cad.length() &&  cad[i] == cad[j]) cont++,j++;
        i = j;
        maxx = ( cont > maxx ) ? cont : maxx;
    }
    cout<<maxx<<endl;
    return 0;
}