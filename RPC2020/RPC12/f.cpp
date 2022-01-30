#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef long long int lli;
const int mxN = 2e5;

int main() {
    int n,k;
    scanf("%d%d", &n, &k);

    // Read in the dimensions.
    long long ancho[1000];
    long long alto[1000];
    for (int i=0; i<n; i++)
        scanf("%lld%lld", &ancho[i], &alto[i]);

    // Do for one box.
    long long dp[1000];
    long long h = 0, w = 0;
    for (int i=0; i<n; i++) {
        h = alto[i] > h ? alto[i] : h;
        w += ancho[i];
        dp[i] = h*w;
    }

    // Now store for i boxes, based on previous.
    for (int i=2; i<=k; i++) {

        long long tmp[1000];

        // What I am trying to maximize.
        for (int j=i-1; j<n; j++) {

            // This is if I make a box to store the last book.
            tmp[j] = ancho[j]*alto[j] + dp[j-1];

            // Dimensions of last box.
            h = alto[j];
            w = ancho[j];

            // Extend last box as far back as possible.
            for (int prev=j-2; prev>=i-2; prev--) {

                // Update this last box and the answer.
                h = alto[prev+1] > h ? alto[prev+1] : h;
                w += ancho[prev+1];
                long long ans = h*w + dp[prev];

                // Update if this box makes a better answer.
                tmp[j] = ans < tmp[j] ? ans : tmp[j];
            }
        }

        // Update for next round.
        for (int i=0; i<n; i++) dp[i] = tmp[i];
    }

    // Ta da!
    printf("%lld\n", dp[n-1]);
    return 0;
}