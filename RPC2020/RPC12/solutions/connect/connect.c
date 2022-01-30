
#include <stdio.h>
#include <stdlib.h>

#define in32(x) scanf("%d", &x)

typedef long long int lli;

int * p, * r, * size;

lli gcd(lli a, lli b) {
    return (b == 0 ) ? a : gcd(b, a % b);
}

int find(int x) {
    return ( x == p[x] ) ? x : (p[x] = find(p[x]));
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
    int n, q;
    in32(n);
    in32(q);

    lli total = n;
    lli segs = n;

    p = calloc(n, sizeof(int));
    r = calloc(n, sizeof(int));
    size = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        p[i] = i;
        size[i] = 1;
    }

    while (q--) {
        int type;
        in32(type);
        if (type == 1) {
            int a, b;
            lli aa, bb;
            in32(a);
            in32(b);
            a = find(a);
            b = find(b);
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

    free(p);
    free(r);
    free(size);

    return 0;
}