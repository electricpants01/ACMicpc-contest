#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool esCuadrado(ll n){
    int ans = sqrt(n);
    if( ans * ans == n) return true;
    return false;
}


int main(){
ios::sync_with_stdio(0); cin.tie(0);
string a;
unsigned long long int b;
while(cin >> a >> b  ){
    if( a == "0" && b == 0) break;
    if( b == 0) {
        cout<<a<<endl;
    }else if( b % 2 == 0){
        b /= 2;
        if( b > 1){
            cout<<a<<endl;
        }else{
            if( a[0] == '-' ){
                cout<<a.substr(1,a.length())<<endl;
            }else{
                cout<<"-"<<a<<endl;
            }
        }
    }else{
        if( b == 1) cout<<a<<"i"<<endl;
        else cout<<"-"<<a<<"i"<<endl;
    }
}
return 0;
}
