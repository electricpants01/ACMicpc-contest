#include<bits/stdc++.h>

#define ll long long int
using namespace std;
const int mxN = 1e5;
int dp[mxN];

int main() {
    int n; cin >> n;
    vector<int> a(n),b(n);
    for(int i=0; i<n;i++)
        cin >> a[i];
    for(int i=0; i<n;i++)
        cin >> b[i];
    map<pair<int,int>,int> mp;
    int ans = 0;
    for(int i=0; i<n;i++){
        if( a[i] == 0){
            if( b[i] == 0) ans++;
        }else{
            int d = __gcd(abs(a[i]),abs(b[i]));
            a[i] /= d;
            b[i] /= d;
            if( a[i] < 0){
                a[i] *= -1;
                b[i] *= -1;
            }
            mp[{a[i],-b[i]}]++;
        }
    }
    int most_freq = 0;
    for( pair<pair<int,int>,int> p : mp){
        most_freq = max( most_freq, p.second );
    }
    cout<<most_freq + ans<<endl;
    return 0;
}
