/*
ID: christo86
TASK: gift1
LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN = 2e5;
const int MOD = 47;

int main(){
//ios::sync_with_stdio(0); cin.tie(0);
    ifstream in("gift1.in", ios::in);
    ofstream out("gift1.out",ios::out);
    int n,dinero,cant;
    in >> n;
    string names[n];
    map<string,int> mp;
    for(int i =0; i<n;i++) in >> names[i];
    string cad;
    while( in >> cad ){
        in >> dinero >> cant;
        if( cant != 0){
            int each = dinero / cant;
            for(int i =0; i<cant; i++){
                string temp;
                in >> temp;
                mp[temp] += each;
            }
            mp[cad] = mp[cad] - (each * cant);
        }
    }
    for( int i=0; i<n;i++){
        out <<names[i]<<" "<<mp[names[i]]<<endl;
    }
    return 0;
}