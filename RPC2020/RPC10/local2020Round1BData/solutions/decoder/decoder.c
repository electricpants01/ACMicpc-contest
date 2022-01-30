
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MOD 1000000007

#define MAX_STRIP 100
#define MAX_MESSAGE 50

#define in32(x) scanf("%d", &x)
#define in64(x) scanf("%lld", &x)
#define out32(x) printf("%d\n", x)
#define out64(x) printf("%lld\n", x)
#define instr(x) scanf("%s", x)

typedef long long int lli;

void freeMat(lli ** mat, int n) {
    for (int i = 0; i < n; i++)
        free(mat[i]);
    free(mat);
}

void genBase(lli ** base, char * strip, int stripLen, char * message, int messageLen) {
    for (int i = 0; i <= messageLen; i++) {
        for (int j = 0; j <= messageLen; j++)
            base[i][j] = 0;
        base[i][i] = 1;
    }
    for (int i = 0; i < stripLen; i++) {
        for (int j = messageLen - 1; j >= 0; j--) {
            if (message[j] == strip[i]) {
                for (int k = 0; k < messageLen; k++) {
                    base[j + 1][k] += base[j][k];
                    if (base[j + 1][k] >= MOD)
                        base[j + 1][k] -= MOD;
                }
            }
        }
    }
}

lli ** copy(lli ** mat, int h, int w) {
    lli ** ret = calloc(h, sizeof(lli *));
    for (int i = 0; i < h; i++) {
        ret[i] = calloc(w, sizeof(lli));
        for (int j = 0; j < w; j++)
            ret[i][j] = mat[i][j];
    }
    return ret;
}

lli ** ident(int n) {
    lli ** ret = calloc(n, sizeof(lli *));
    for (int i = 0; i < n; i++) {
        ret[i] = calloc(n, sizeof(lli));
        for (int j = 0; j < n; j++)
            ret[i][j] = 0;
        ret[i][i] = 1;
    }
    return ret;
}

lli ** mult(lli ** a, lli ** b, int x, int y, int z) {
    lli ** ret = calloc(x, sizeof(lli *));
    for (int i = 0; i < x; i++) {
        ret[i] = calloc(z, sizeof(lli));
        for (int j = 0; j < z; j++) {
            ret[i][j] = 0;
            for (int k = 0; k < y; k++) {
                ret[i][j] += a[i][k] * b[k][j];
                ret[i][j] %= MOD;
            }
        }
    }
    return ret;
}

lli ** expo(lli ** mat, lli exp, int len) {
    if (exp == 0) return ident(len);
    if (exp == 1) return copy(mat, len, len);
    lli ** tmp = expo(mat, exp>>1, len);
    lli ** tmp2 = mult(tmp, tmp, len, len, len);
    freeMat(tmp, len);

    lli ** res = tmp2;
    if (exp&1) {
        res = mult(tmp2, mat, len, len, len);
        freeMat(tmp2, len);
    }

    return res;
}

int main() {
    int messageLen, stripLen;
    lli stripCount;
    char strip[MAX_STRIP + 1];
    instr(strip);
    stripLen = strlen(strip);
    in64(stripCount);
    char message[MAX_MESSAGE + 1];
    instr(message);
    messageLen = strlen(message);

    lli ** base = calloc(messageLen + 1, sizeof(lli *));
    for (int i = 0; i <= messageLen; i++)
        base[i] = calloc(messageLen + 1, sizeof(lli));

    genBase(base, strip, stripLen, message, messageLen);

    lli ** result = expo(base, stripCount, messageLen + 1);

    // cuz im lazy XD
    lli ans = result[0][messageLen] + result[messageLen][0];

    out64(ans);

    return 0;
}
