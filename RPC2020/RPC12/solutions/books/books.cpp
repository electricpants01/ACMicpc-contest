#include <algorithm>
#include <cstdio>
#include <limits>
#include <unordered_map>

using std::max;
using std::min;
using std::numeric_limits;
using std::unordered_map;

const long HIGH_SCORE = numeric_limits<long>::max();

#define MAXBOOKS 1000

struct book {
    long w, h;
};

static int n;
static book books[MAXBOOKS+1];

unordered_map<int, long> memo;

// compute the best solution for packing the books [l..n] into
// exactly 'k' boxes.
//
long best(int l, int k)
{
    int key = l * 1001 + k;
    auto it = memo.find(key);
    if (it != memo.end()) {
        return it->second;
    }

    long w = books[l].w;
    long h = books[l].h;

    // quick out: one box
    if (k == 1) {
        while (++l <= n) {
            w += books[l].w;
            h = max(h, books[l].h);
        }

        return memo[key] = w*h;
    }

    long score = HIGH_SCORE;
    int split = l+1;

    // we have at least two boxes. try all possible splits.
    //
    for (int i = l+1; i <= n-(k-2); i++) {
        // w,h are the dimension of the box up to, but not including i 
        long cost = w * h + best(i, k-1);
        score = std::min(score, cost);
        // update the first box
        w += books[i].w;
        h = max(h, books[i].h);
    }
    
    return memo[key] = score;
}

int main()
{
    int i, k;

    scanf("%d %d", &n, &k);
    for (i = 1; i <= n; i++) {
        scanf("%ld %ld", &books[i].w, &books[i].h); 
    }

    printf("%ld\n", best(1, k));
}
