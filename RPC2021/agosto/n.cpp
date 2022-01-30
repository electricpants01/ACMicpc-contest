#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MOD = 1e9+7;
const int maxN = 1e6+1;
int dp[maxN];

int main(){
    map<char,int> total;
    map<char,int> curr;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i =0; i<n;i++){
            char temp; cin >> temp;
            curr[temp]++;
            total[temp]++;
        }
        cout<<"A:"<<curr['A']<<" B:"<<curr['B']<<" C:"<<curr['C']<<" D:"<<curr['D']<<" E:"<<curr['E']<<" F:"<<curr['F']<<endl;
        curr.clear();
    }
    cout<<"TOTAL: A:"<<total['A']<<" B:"<<total['B']<<" C:"<<total['C']<<" D:"<<total['D']<<" E:"<<total['E']<<" F:"<<total['F']<<endl;
    return 0;
}