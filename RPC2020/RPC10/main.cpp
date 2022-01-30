#include <bits/stdc++.h>
#define len(x) int((x).size())

using namespace std;

void solution() {
    int b, n;
    cin >> b >> n;

    vector<int> base(b+2);
    for(int i = 0; i < n; ++i) {
        int h, v, col;
        cin >> h >> v >> col;
        for(int i = col; i < col+h; ++i) {
            base[i] += v;
        }
    }
    int ans = 0;
    for(int i = 0; i < len(base); ++i) {
        ans = max(ans, base[i]);
    }
    cout << ans << endl;

}

int main(){
solution();
return 0;
}