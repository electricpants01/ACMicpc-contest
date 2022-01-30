#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Nodo{
    int x,y;
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string cad; cin >> cad;
    int len = cad.length();
    int turn = 0;
    int scores[] = {0,0};
    int games[] = {0,0};
    bool finished =false;
    for(int i=0;i<len;i++){
        if( cad[i] == 'S'){
            scores[turn]++;
        }else if( cad[i] == 'R'){
            turn = 1 - turn;
            scores[turn]++;
        }else if( cad[i] == 'Q'){
            if(finished){
                if( games[0] > games[1]){
                    cout<<games[0]<<" (winner) - "<<games[1]<<endl;
                }else{
                    cout<<games[0]<<" - "<<games[1]<<" (winner)"<<endl;
                }
            }else{
                cout<<games[0]<<" ("<<scores[0]<<((turn == 0 ) ? "*" : "")<<") - "<<games[1]<<" ("<<scores[1]<<((turn == 1) ? "*" : "")<<")"<<endl;
            }
        }
        if( scores[0] >= 5 && (scores[0]-scores[1])>=2 || scores[0] == 10){
            games[0]++;
            scores[0] = 0; scores[1] = 0;
        }else if( scores[1] >= 5 && (scores[1]-scores[0])>=2 || scores[1] == 10){
            games[1]++;
            scores[0] = 0; scores[1] = 0;
        }
        if( games[0] == 2 ||games[1] == 2) finished = true;
    }
    return 0;
}0