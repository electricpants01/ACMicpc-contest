#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxN = 2e6;
ll dp[40];

int main() {;
    dp[0] = 0; dp[1] = 1; dp[2] = 1;
    for(int i=3; i<=30; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    string fibos = "";
    for(int i =1; i<=30;i++){
        stringstream  ss;
        ss << dp[i];
        string s;
        ss >> s;
        fibos += s;
    }// se han calculado los primeros 30 numeros fibonacci
    int n = fibos.length();
    string a,b;
    while( cin >> a >> b ){
        bool ans = false;
        int lena = a.length();
        int lenb = b.length();
        int found = fibos.find_first_of(a);
        while( found != string::npos){
            if( lena == 1 ){
                if( lenb == 1){
                    if( fibos[found+1] == b[0] ){
                        ans = true;
                        break;
                    }
                }else if( lenb == 2 ){
                    if( fibos[found+1] == b[0] && fibos[found+2] == b[1]){
                        ans = true;
                        break;
                    }
                }
            }else if( lena == 2){
                if( lenb == 1){
                    if( fibos[found+2] == b[0] ){
                        ans = true;
                        break;
                    }
                }else if( lenb == 2 ){
                    if( fibos[found+2] == b[0] && fibos[found+3] == b[1]){
                        ans = true;
                        break;
                    }
                }
            }
            found = fibos.find_first_of(a,found+1);
        }
        if( ans ) cout<<"SI"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}