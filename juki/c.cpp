#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    string cad; cin >> cad;
    int len = cad.length();
    string nuevo = "";
    for(int i =0; i<len; i++){
        if( cad[i] == 'R'){
            string ans = "";
            string temp = "";
            if( nuevo.length() >= 3){
                temp = nuevo.substr(nuevo.length()-3);
            }
            if( temp == "QQQ") ans = "Cold Snap";
            else if( temp == "QQW" || temp == "WQQ" || temp == "QWQ") ans = "Ghost Walk";
            else if( temp == "WWQ" || temp == "WQW" || temp == "QWW" ) ans = "Tornado";
            else if( temp == "WWW" ) ans = "EMP";
            else if( temp == "WWE" || temp == "WEW" || temp == "EWW" ) ans = "Alacrity";
            else if( temp == "EEW" || temp == "EWE" || temp == "WEE") ans = "Chaos Meteor";
            else if( temp == "EEE" ) ans = "Sunstrike";
            else if( temp == "EEQ" || temp == "EQE" || temp == "QEE" ) ans = "Forge Spirit";
            else if( temp == "QQE" || temp == "QEQ" || temp == "EQQ") ans = "Ice Wall";
            else if( temp == "QWE" || temp == "WEQ" || temp == "EQW" || temp == "WQE" || temp == "QEW" || temp == "EWQ") ans = "Deafening Blast";
            if( ans == "") cout<<"None"<<endl;
            else cout<<ans<<endl;
        }else {
            nuevo += cad[i];
        }
    }
    return 0;
}