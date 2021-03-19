#include <bits/stdc++.h>
// https://codeforces.com/contest/1165/problem/B
using namespace std;
#define ll long long

int main(){
    int n, x, y;
    string cad;
    cin >> n >> x >> y >> cad;
    int sol = 0;
    for(int i = n-x; i < n; i++ ){
        if( i == (n-y -1) ){
            if( cad[i] == '0' ) sol++;
        }else{
            if( cad[i] == '1') sol++;
        }
    }
    cout<<sol<<endl;
    return 0;
}