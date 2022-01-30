#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int mxN = 1e3;
int dp[mxN][mxN];


int main() {
    int n; cin >> n;
    int sum1 =0;
    int sum2 =0;
    int temp1 = 0;
    int temp2 = 0;
    for(int i=0; i<n;i++){
        int a,b,c; cin >> a >> b >> c;
        sum1 += b;
        sum2 += c;
        if(  b > c){
            temp1+= a;
        }else if( c > b){
            temp2+= a;
        }
    }
    if( sum1 > sum2 && temp1 > temp2){
        cout<<"1"<<endl;
    }else if( sum2 > sum1 && temp2 > temp1){
        cout<<"2"<<endl;
    }else{
        cout<<"0"<<endl;
    }
    return 0;
}