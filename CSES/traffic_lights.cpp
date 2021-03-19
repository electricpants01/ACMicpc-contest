#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxN = 2e5;
int x,n,p[maxN];

void mostrar(map<int,int> mp);

int main() {
    set<int> s;
    map<int,int> mp;
    cin >> x >> n;
    s.insert(0);
    s.insert(x);
    mp[x] = 1;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        auto it = s.lower_bound(p[i]);
        int r = *it;
        --it;
        int l = *it;
        --mp[r - l]; //porque????
        if (!mp[r - l])
            mp.erase(r - l);
        s.insert(p[i]);
        ++mp[r - p[i]];
        ++mp[p[i] - l];
        cout << (--mp.end())->first << endl;
    }
    return 0;
}