#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cout << setprecision(12)<<fixed;
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int arr[n];
        set<double> s;
        for(int i =0; i<n;i++){
            cin >> arr[i];
        }
        for(int i =0; i<n-1;i++){
            for(int j=i+1; j<n;j++){
                double t = (double)(arr[j]-arr[i])/2;
                if( t > 0 ) s.insert(t);
            }
        }
        cout<<s.size()<<endl;
    }
    return 0;
}
