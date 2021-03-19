#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
ios::sync_with_stdio(0); cin.tie(0);
cout << setprecision(12)<<fixed;
int t; cin >> t;
while (t--){
    int n; cin >> n;
    for(int i = 0; i<n;i++){
        if( i == 0) cout<<9;
        else cout<<(7+i)%10;
    }
    cout<<endl;
}
return 0;
}
