/*
ID: roperoe1
LANG: C++
TASK: ride
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int solve(string cad){
    int len = cad.length();
    ll ans = 1;
    for(int i =0; i<len;i++){
        ans = (ans * (cad[i]-'A'+1)) % 47;
    }
    return (ans % 47);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ifstream in("ride.in",ios::in);
    ofstream  out("ride.out",ios::out);
    string a,b;
    in >> a >> b;
    int c = solve(a);
    int d = solve(b);
    //cout<<"r: "<<c<<endl;
    //cout<<"d: "<<d<<endl;
    if( c == d ) out <<"GO\n";
    else out <<"STAY\n";
    return 0;
}
