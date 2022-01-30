#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MOD = 1e9+7;
const int maxN = 1e6+1;
int dp[maxN];


int main(){
 int n; cin >> n;
 // novice < 40
 // intermediate 40 < 70
 // advanced 70 < 90
 // expert >= 90
 if( n < 40 ) cout<<40-n<<endl;
 else if(n >= 40 && n < 70) cout<<70-n<<endl;
 else if( n >= 70 && n < 90) cout<<90-n<<endl;
 else cout<<"expert"<<endl;
 return 0;
}