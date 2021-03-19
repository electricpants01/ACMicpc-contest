#include <bits/stdc++.h>
//https://www.jukijudge.com/
using namespace std;
#define ll long long


void addPrincipio( string &cad, char c){
    cad = c + cad;
}

void addUltimo( string &cad, char c){
    cad += c;
}

void delPrincipio( string &cad){
    cad.erase(0,1);
}

void delUltimo( string &cad){
    cad.erase(cad.length()-1);
}

void invertir( string &cad){
    reverse(cad.begin(),cad.end());
}

int main() {
    string cad; cin >> cad;
    int t; cin >> t;
    bool ban = false;
    while(t--){
        int d; cin >> d;
        if( d == 1){
            ban = !ban;
        }else if( d == 2){
            int k; char c;
            cin >> k >> c;
            if( ban){
                if( k == 1 ) k = 2;
                else if( k == 2) k = 1;
            }
            if(  k == 1 ){
                addPrincipio(cad, c);
            }else if( k == 2){
                addUltimo(cad, c);
            }
        }else if( d == 3){
            int k; cin >> k;
            if( ban ){
                if( k == 1) k = 2;
                else if( k == 2 ) k =1;
            }
            if( k == 1){
                delPrincipio(cad);
            }else if(k == 2){
                delUltimo(cad);
            }
        }
    }
    if( ban ){
        invertir(cad);
    }
    cout<<cad<<endl;
    return 0;
}