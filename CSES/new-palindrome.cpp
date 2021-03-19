#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    string cad; cin >> cad;
    int n = cad.length();
    map<char,int> mp ;
    for(int i =0; i<n; i++) mp[ cad[i] ]++;
    string sol = "";
    string impar = "";
    for( auto x : mp){
        if( x.second % 2 == 0 ) sol = sol + string( x.second / 2, x.first );
        else impar = impar + string(x.second , x.first);
    }
    string tmp = sol;
    reverse( tmp.begin(), tmp.end());
    sol = sol + impar + tmp;
    string sol2 = sol;
    reverse(sol.begin(), sol.end());
    if( sol2 == sol ) cout<<sol2<<endl;
    else cout<<"NO SOLUTION"<<endl;
    return 0;
}