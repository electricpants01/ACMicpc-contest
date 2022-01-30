
#include <stdio.h>
#include <stdlib.h>

#define in32(x) scanf("%d", &x)
#define in64(x) scanf("%lld", &x)
#define out32(x) printf("%d\n", x)
#define out64(x) printf("%lld\n", x)

typedef long long int lli;

#define MOD 1000000007


int suits, max;
lli ** memo;
lli * fact, * fact_i, * invs;


lli ways(int, int);

int main() {
    int piles;
    in32(max);
    in32(suits);
    in32(piles);

    // Create the memo table
    memo = calloc(piles + 1, sizeof(lli *));
    for (int i = 0; i <= piles; i++) {
        memo[i] = calloc(max + 1, sizeof(lli));
        for (int j = 0; j <= max; j++) {
            memo[i][j] = -1;
        }
    }

    int num_cards = suits * max;
    invs = calloc(num_cards + 1, sizeof(lli));
    fact = calloc(num_cards + 1, sizeof(lli));
    fact_i = calloc(num_cards + 1, sizeof(lli));
    fact[0] = fact_i[0] = invs[1] = fact[1] = fact_i[1] = 1;
    for (int i = 2; i <= num_cards; i++) {
        invs[i] = MOD - ((MOD / i) * invs[(MOD % i)]) % MOD;
        if (invs[i] == MOD) invs[i] = 0;
        fact[i] = fact[i-1] * i;
        fact[i] %= MOD;
        fact_i[i] = fact_i[i-1] * invs[i];
        fact_i[i] %= MOD;
    }


    lli ans = 0;
    for (int i = 1; i <= piles; i++){
        ans += ways(i, max);
    }
    ans %= MOD;

    // Find ways to permute one card type
    lli small_fact = fact[suits];
    
    // Use multiplication rule to permute all card types
    // could be done faster using mod expo
    for (int i = 0; i < max; i++) {
        ans *= small_fact;
        ans %= MOD;
    }
    out64(ans);

    for (int i = 0; i <= piles; i++)
        free(memo[i]);
    free(memo);
    free(invs);
    free(fact);
    free(fact_i);


    return 0;
}

lli choose(int n, int k) {
    return (((fact[n] * fact_i[k]) % MOD) * fact_i[n - k]) % MOD;
}

lli ways(int piles, int last) {
    if (last < piles) return 0;
    if (piles == 1) return choose(max * suits - 1, last * suits - 1);
    if (memo[piles][last] != -1) return memo[piles][last];
    
    // Initialize with 0 ways
    memo[piles][last]=0;

    for (int i = 1; i < last; i++) {
        // find ways to do smaller piles
        lli partial = ways(piles - 1, i);

        // Fix unfixed cards that need to go before the current (i-th card)
        partial *= choose((max + 1 - i) * suits - 1, (last - i) * suits - 1);
        partial %= MOD;

        // Update answer
        memo[piles][last] += partial;
    }
    memo[piles][last] %= MOD;

    // return the answer
    return memo[piles][last];
}