#include <bits/stdc++.h>

using namespace std;
#define ll long long
typedef long long int lli;
const int mxN = 2e5;
int p[mxN],r[mxN],size[mxN];

lli gcd(lli a, lli b) {
    return (b == 0 ) ? a : gcd(b, a % b);
}

int encontrar(int x) {
    return ( x == p[x] ) ? x : (p[x] = encontrar(p[x]));
}

void merge(int a, int b) {
    if (r[a] < r[b]) {
        p[a] = b;
        size[b] += size[a];
        return;
    }
    p[b] = a;
    size[a] += size[b];
    if (r[a] == r[b])
        r[a]++;
}

int main() {
    int n, q; cin >> n >> q;
    lli total = n;
    lli segs = n;

    for (int i = 0; i < n; i++) {
        p[i] = i;
        size[i] = 1;
    }

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int a, b;
            lli aa, bb;
            cin >> a >> b;
            a = encontrar(a);
            b = encontrar(b);
            if (a != b) {
                aa = size[a];
                bb = size[b];
                total -= aa * aa + bb * bb;
                total += (aa + bb) * (aa + bb);
                segs--;
                merge(a, b);
            }
        } else {
            lli g = gcd(total, segs);
            printf("%lld/%lld\n", total / g, segs / g);
        }
    }


    return 0;
}