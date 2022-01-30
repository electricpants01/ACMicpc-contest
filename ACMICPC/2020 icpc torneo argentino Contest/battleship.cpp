#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Nodo{
    int d,l,r,c;
};

int main(){
//ios::sync_with_stdio(0); cin.tie(0);
    cout<<setprecision(12)<<fixed;
    bool m[11][11];
    for(int i =0; i<11;i++){
        for(int j =0;j<11;j++) m[i][j] = false;
    }
    int n; cin >> n;
    int dx =0,dy = 0;
    for(int i =0; i<n;i++){
        int d,l,r,c; cin >> d >> l >> r >> c;
        if(d == 0){ // horizontal
            for(int j =c; j<=c+l-1; j++){
                if( r < 1 || j < 1 || i > 10 || j > 10 || m[r][j]){
                    cout<<"N"<<endl;
                    return 0; // fin del programa
                }
                m[r][j] = true;
            }
        }else if( d == 1 ){ // vertical
            for(int j = r; j <= r+l-1; j++){
                if( c < 1 || c > 10 || j < 1 || j > 10 || m[j][c]){
                    cout<<"N"<<endl;
                    return 0; // end of the program
                }
                m[j][c] = true;
            }
        }
    }
    cout<<"Y"<<endl;
    return 0;
}