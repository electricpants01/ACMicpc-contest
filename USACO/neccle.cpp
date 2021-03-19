/*
ID: christo86
TASK: beads
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
//ios::sync_with_stdio(0); cin.tie(0);
    ifstream in("beads.in", ios::in);
    ofstream out("beads.out", ios::out);
    int n; cin >> n;
    string cad;
    cin >> cad;
    cout << cad<<endl;
    int maxB = 0, maxR = 0;
    for(int i=0;i< cad.length();i++){ // RED
        int cont  =0;
        if( cad[i] == 'r' || cad[i] == 'w'){
            while(cad[i] == 'r' || cad[i] == 'w'){
                cont++;
                i++;
            }
            i--;
            maxR = max(maxR, cont);
        }
    }
    for(int i=0;i< cad.length();i++){ // BLUE
        int cont  =0;
        if( cad[i] == 'b' || cad[i] == 'w'){
            while(cad[i] == 'b' || cad[i] == 'w'){
                cont++;
                i++;
            }
            i--;
            maxB = max(maxB, cont);
        }
    }
    cout<<maxR<<endl;
    cout<<maxB<<endl;
    return 0;
}