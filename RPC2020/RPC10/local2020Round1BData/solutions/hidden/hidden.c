
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define instr(x) scanf("%s", x)
#define out32(x) printf("%d\n", x)

#define MAX_STRING 310
#define MOD 1000000007

int main() {
    char w1[MAX_STRING];
    char w2[MAX_STRING];
    char w3[MAX_STRING];
    char phrase[MAX_STRING];
    instr(w1);
    instr(w2);
    instr(w3);
    instr(phrase);
    int a = strlen(w1);
    int b = strlen(w2);
    int c = strlen(w3);

    int *** memo = calloc(a + 1, sizeof(int **));
    for (int i = 0; i <= a; i++) {
        memo[i] = calloc(b + 1, sizeof(int *));
        for (int j = 0; j <= b; j++) {
            memo[i][j] = calloc(c + 1, sizeof(int));
            if (!i && !j)
                memo[0][0][0] = 1;
            for (int k = 0; k <= c; k++) {
                if (i && w1[i-1] == phrase[i + j + k - 1]) {
                    memo[i][j][k] += memo[i - 1][j][k];
                    memo[i][j][k] %= MOD;
                }
                if (j && w2[j-1] == phrase[i + j + k - 1]) {
                    memo[i][j][k] += memo[i][j - 1][k];
                    memo[i][j][k] %= MOD;
                }
                if (k && w3[k-1] == phrase[i + j + k - 1]) {
                    memo[i][j][k] += memo[i][j][k - 1];
                    memo[i][j][k] %= MOD;
                }
            }
        }
    }
    out32(memo[a][b][c]);

    return 0;
}