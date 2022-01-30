#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n; cin >> n;
    set<string> s;
    for(int i =0; i<n;i++){
        string cad; cin >> cad;
        s.insert(cad);
    }
    cout<<s.size()<<endl;
    return 0;
}