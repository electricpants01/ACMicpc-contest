#include <bits/stdc++.h>

using namespace std;
#define ll long long int
const int MOD = 1e9 + 7;
const int maxN = 1e6 + 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string cad; cin >> cad;
    int len = cad.size();
    char temp[] = {'h','e','l','o'};
    int t = cad.find_first_of('h');
    if( t != string::npos){
        int pos = 0;
        for (int i = t; i < len;) {
            int cont = 0;
//            if(cad[i] != temp[pos]) break;
            if( cad[i] != temp[pos]){
                i++; continue;
            }
            while (cad[i] == temp[pos]){i++, cont++;}
            if(temp[pos] == 'l' && cont <2) break;
            pos++;
        }
        if(pos == 4) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }else cout <<"NO"<<endl;
    return 0;
}