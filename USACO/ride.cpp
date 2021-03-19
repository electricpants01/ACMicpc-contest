/*
ID: christo86
TASK: ride
LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN = 2e5;
const int MOD = 47;

int solve(string cad){
    int ans = 1;
    for(int i =0; i<cad.length();i++){
        ans += (cad[0]-'A' +1);
    }
    return (ans % MOD);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ifstream in("ride.in",ios::in);
    ofstream  out("ride.out",ios::out);
    string a, b;
    in >> a >> b;
    int c = solve(a);
    int d = solve(b);
    if( c == d ) out<<"GO"<<endl;
    else out<<"STAY"<<endl;
    in.close(); out.close();
    return 0;
}