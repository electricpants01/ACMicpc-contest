// Arup Guha
// 9/18/2020
// Alternate Solution to 2020 UCF Locals Final Round Problem: Boxing Books

#include <stdio.h>

int main(void) {

    int n,k;
    scanf("%d%d", &n, &k);

    // Read in the dimensions.
    long long width[1000];
    long long height[1000];
    for (int i=0; i<n; i++)
        scanf("%lld%lld", &width[i], &height[i]);

    // Do for one box.
    long long dp[1000];
    long long h = 0, w = 0;
    for (int i=0; i<n; i++) {
        h = height[i] > h ? height[i] : h;
        w += width[i];
        dp[i] = h*w;
    }

    // Now store for i boxes, based on previous.
    for (int i=2; i<=k; i++) {

		long long tmp[1000];

        // What I am trying to maximize.
        for (int j=i-1; j<n; j++) {

            // This is if I make a box to store the last book.
            tmp[j] = width[j]*height[j] + dp[j-1];

            // Dimensions of last box.
            h = height[j];
            w = width[j];

            // Extend last box as far back as possible.
            for (int prev=j-2; prev>=i-2; prev--) {

                // Update this last box and the answer.
                h = height[prev+1] > h ? height[prev+1] : h;
                w += width[prev+1];
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
