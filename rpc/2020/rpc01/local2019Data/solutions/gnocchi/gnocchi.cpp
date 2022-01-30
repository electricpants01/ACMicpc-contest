// Arup Guha
// 9/9/2019
// Alternate Solution to 2019 UCF Locals Problem: Give-a-Gnocci

#include <iostream>
#include <stdlib.h>

using namespace std;

// This is quite a bit more than necessary...
const int MAX = 2000000;

int* sieve(int limit);

int main(void) {

    // Get the real primes first.
    int* primes = sieve(MAX-1);

    // Input for the case.
    int n, k;
    cin >> n >> k;

    // Run a bad prime sieve, stopping at n, no optimization.
    int* gnoccilist = sieve(n);

    // Loop through both arrays, counting fake primes.
    int fakePrimes = 0, res = -1;
    for (int i=0; i<MAX; i++) {

        // This is a fake prime, for this problem.
        if (gnoccilist[i] && !primes[i])
            fakePrimes++;

        // We found the kth one.
        if (fakePrimes == k) {
            res = i;
            break;
        }
    }

    // Ta da!!!
    cout << res << endl;

    // Free stuff.
    free(gnoccilist);
    free(primes);
    return 0;
}

// Returns the prime sieve array that sets all values to 1 which have
// no prime factors <= limit.
int* sieve(int limit) {
    int* primes = new int[MAX];
        primes[0] = primes[1] = 0;
        for (int i=2; i<MAX; i++) primes[i] = 1;
        for (int i=2; i<=limit; i++)
            for (int j=2*i; j<MAX; j+=i)
                primes[j] = 0;
    return primes;
}
