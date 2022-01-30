
#include <stdio.h>
#include <stdlib.h>

#define EPS 1e-9


#define ABS(x) (((x) < 0) ? -(x) : (x))
#define MAX(x,y) (((x) < (y)) ? (y) : (x))
#define in32(x) scanf("%d", &x)
#define inf64(x) scanf("%lf", &x)
#define outf64(x) printf("%lf\n", x)

int eq(double, double);

void print(int i, int max) {
    while (max--) {
        printf("%d", i&1);
        i>>=1;
    }
    printf("\n");
}

int main() {
    int n, m;
    double val;
    inf64(val);
    in32(n);
    in32(m);

    int * st = calloc(m, sizeof(int));
    int * en = calloc(m, sizeof(int));
    int * base = calloc(m, sizeof(int));
    int * scale = calloc(m, sizeof(int));
    

    for (int i = 0; i < m; i++) {
        in32(st[i]);
        in32(en[i]);
        in32(base[i]);
        in32(scale[i]);
        st[i]--;
        en[i]--;
    }

    double ans = 0;

    for (int i = 0; i < (1<<m); i++) {
        int count = 0;
        for (int j = 0; j < m; j++)
            if (i&(1<<j)) count++;
        if (count != n - 1) continue;
        int * vis = calloc(n, sizeof(int));
        vis[0] = 1;
        for (int j = 0; j < n; j++) 
            for (int k = 0; k < m; k++) 
                if (vis[en[k]] && (i&(1<<k)))
                    vis[st[k]] = 1;
        int good = 1;
        for (int j = 0; j < n && good; j++)
            good = vis[j];
        if (!good) continue;
        double lo = ans;
        double hi = val;
        //printf("Here %d\n", i);
        while (!eq(hi, lo)) {
            double mid = (hi + lo) / 2;
            double spend = 0;
            for (int j = 0; j < m; j++) {
                if ((1<<j)&i) {
                    spend += base[j] + scale[j] * mid;
                }
            }
            if (mid + spend <= val) {
                ans = mid;
                lo = mid;
                // printf("\n");
                // for (int k = 0; k < m; k++) 
                //     if ((i&(1<<k)))
                //         printf("%d %d\n", st[k], en[k]);

            } else {
                hi = mid;
            }
        }
    }
    int a2 = (int)ans;
    //printf("%d\n", (int)ans);
    //printf("%d\n", (int)val);
    outf64(ans);

    free(st);
    free(en);
    free(base);
    free(scale);

    return 0;
}

int eq(double a, double b) {
    double diff = ABS(a - b);
    if (diff < EPS)
        return 1;
    double max = MAX(ABS(a), ABS(b));
    return (max * EPS > diff); 
}