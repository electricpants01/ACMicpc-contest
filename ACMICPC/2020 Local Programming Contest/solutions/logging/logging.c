
#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

#define in32(x) scanf("%d", &x)
#define out64(x) printf("%lld\n", x);

typedef long long int lli;
typedef struct AL AL;

struct AL {
    int size, cap, * arr;
};


void logCase(int);
void emptyCase(int);
void brute(int);
void cleanAll();

AL * createAL() {
    AL * ret = calloc(1, sizeof(AL));
    ret->size = 0;
    ret->arr = calloc(ret->cap = 2, sizeof(int));
    return ret;
}

void addAL(AL * list, int v) {
    if (list->cap == list->size) list->arr = realloc(list->arr, (list->cap *= 2) * sizeof(int));
    list->arr[list->size++] = v;
}

lli getInv(lli val) {
    if (val == 1) return 1;
    return (MOD - ((MOD / val) * getInv(MOD % val)) % MOD);
}

int N;
AL ** adj;
int *  types, * q, * par;
lli * dp0, * dp1, * dp2;

int main() {
    int a, b;
    in32(N);

    // Create the trees structure
    adj = calloc(N, sizeof(AL *));
    for (int i = 0; i < N; i++)
        adj[i] = createAL();

    // Read in the tree
    for (int i = 0; i < N - 1; i++) {
        in32(a);
        in32(b);
        a--;
        b--;
        addAL(adj[a], b);
        addAL(adj[b], a);
    }

    // Read in the types
    types = calloc(N, sizeof(int));
    int logs, curLog;
    in32(logs);
    while (logs-->0) {
        in32(curLog);
        types[curLog-1] = 1;
    }

    // values for the tree BFS
    q = calloc(N, sizeof(int));
    par = calloc(N, sizeof(int));
    int fptr = 0, bptr = 0;
    par[0] = -1;
    q[bptr++] = 0;

    // BFS through the tree
    while (fptr < bptr) {
        int cur = q[fptr++];
        for (int i = 0; i < adj[cur]->size; i++) {
            int ch = adj[cur]->arr[i];
            if (ch != par[cur]) {
                par[ch] = cur;
                q[bptr++] = ch;
            }
        }
    }

    // Do the DP (reverse order on the visisted order)
    dp0 = calloc(N, sizeof(lli)); // give below / no log
    dp1 = calloc(N, sizeof(lli)); // give above / can be red
    dp2 = calloc(N, sizeof(lli)); // ---------- / must be red
    for (int i = N - 1; i >= 0; i--) {
        brute(q[i]);
    }
#ifdef DEBUG
    for (int i = 0; i < N; i++)
        printf("%d ", par[i]);
    printf("\n");
    for (int i = 0; i < N; i++)
        printf("%lld ", dp0[i]);
    printf("\n");
    for (int i = 0; i < N; i++)
        printf("%lld ", dp1[i]);
    printf("\n");
    for (int i = 0; i < N; i++)
        printf("%lld ", dp2[i]);
    printf("\n");
#endif
    lli ans = 0;
    if (types[0]) {
        ans = dp0[0];
    } else {
        ans = dp0[0] + dp2[0];
        ans %= MOD;
    }

    out64(ans);
    cleanAll();

    return 0;
}

void logCase(int loc) {
    // Check if we must be red
    for (int i = 0; i < adj[loc]->size; i++) {
        int ch = adj[loc]->arr[i];
        if (ch == par[loc]) continue;
        if (types[ch] && dp0[ch] == 0) return;
    }
    
    // Check the number of nodes below us that must be red
    int numMustRed = 0;
    for (int i = 0; i < adj[loc]->size; i++) {
        int ch = adj[loc]->arr[i];
        if (ch == par[loc]) continue;
        if (!types[ch] && !dp0[ch]) 
            numMustRed++;
    }

    if (numMustRed > 1) return;
    dp0[loc] = 0; // below red (ways we choose 1 red child)
    dp1[loc] = 1; // above red (ways we choose no red children)
    lli tmp = 1;
    for (int i = 0; i < adj[loc]->size; i++) {
        int ch = adj[loc]->arr[i];
        if (ch == par[loc]) continue;
        if (!types[ch])
            dp1[loc] *= (dp0[ch]);
        else
            dp1[loc] *= (dp0[ch]);
        dp1[loc] %= MOD;
    }

    if (numMustRed) { // red child is forced
        dp0[loc] = 1;
        for (int i = 0; i < adj[loc]->size; i++) {
            int ch = adj[loc]->arr[i];
            if (ch == par[loc]) continue;
            if (!types[ch] && dp0[ch])
                dp0[loc] *= (dp0[ch]);
            else if (types[ch])
                dp0[loc] *= (dp0[ch]);
            else
                dp0[loc] *= (dp2[ch]);
            dp0[loc] %= MOD;
        }
    } else { // any red non-log
        dp0[loc] = 0;
        for (int i = 0; i < adj[loc]->size; i++) {
            int ch = adj[loc]->arr[i];
            if (ch == par[loc]) continue;
            if (!types[ch]){
                lli inv = getInv(dp0[ch]);
                lli tmp = inv * dp1[loc];
                tmp %= MOD;
                dp0[loc] += tmp * (dp1[ch] + dp2[ch]);
            }
            dp0[loc] %= MOD;
        }
    }
}

void emptyCase(int loc) {
    // Check possibilities
    int mustRed = 0;
    int mustNotRed = 0;
    int blackChildren = 0;
    dp0[loc] = 1;
    dp1[loc] = 1;

    for (int i = 0; i < adj[loc]->size; i++) {
        int ch = adj[loc]->arr[i];
        if (ch == par[loc]) continue;
        if (types[ch]) {
            blackChildren++;
            dp0[loc] *= dp0[ch];
            dp1[loc] *= dp1[ch];
        } else {
            dp0[loc] *= (dp0[ch] + dp2[ch]);
            dp1[loc] *= (dp0[ch] + dp2[ch]);
        }
        dp0[loc] %= MOD;
        dp1[loc] %= MOD;
    }

    if (blackChildren) {
        dp2[loc] = dp1[loc];
        dp1[loc] = 0;
    }
}

void brute(int loc){

    if (types[loc]) { 
        logCase(loc);
    } else { 
        emptyCase(loc);
    }
}

void cleanAll() {
    free(dp0);
    free(dp1);
    free(dp2);
    free(q);
    free(types);
    free(par);
    for (int i = 0; i < N; i++) {
        free(adj[i]->arr);
        free(adj[i]);
    }
    free(adj);
}