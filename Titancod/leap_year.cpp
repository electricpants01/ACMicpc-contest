#include <bits/stdc++.h>
using namespace std;
#define ll long long

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

bool checkLeapYear(int y){
    if( y % 400 == 0) return true;
    else if( y % 100 == 0 ) return false;
    else if( y % 4 == 0 ) return true;
    return false;
}

int main() {
    int months[] = { 31,28,31,30,31,30,31,31,30,31,30,31};
    int t;cin >> t;
    while(t--){
        int d,m,a; cin >> d >> m >> a;
        int denominador, numerador = 0;
        if( checkLeapYear(a) ){
            denominador = 366;
        }else{
            denominador = 365;
        }
        for(int i =0; i<(m-1);i++){
            numerador += months[i];
            if( i == 1 && checkLeapYear(a) ) numerador++;
        }
        numerador += d;
        int div = gcd(numerador,denominador);
        if( div > 1){
            numerador /= div;
            denominador /= div;
        }
        if( numerador == 1 && denominador == 1 ){
            cout<<"1"<<endl;
        }else{
            cout<<numerador<<"/"<<denominador<<endl;
        }
    }
    return 0;
}