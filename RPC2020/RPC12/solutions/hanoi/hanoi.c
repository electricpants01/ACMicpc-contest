
#include <stdio.h>
#include <stdlib.h>

#define in32(x) scanf("%d", &x)
#define out32(x) printf("%d\n", x)

int * stk, * tmp, * used;

void move(int sPeg, int ePeg, int sDisk, int eDisk) {
    int lastLocation = 0;
    for (int i = sDisk; i < eDisk; i++) {
        int location = lastLocation;
        while (used[location] || ePeg == location)
            location++;
        printf("%d %d\n", sPeg + 1, location + 1);
        tmp[i-sDisk] = location;
        lastLocation = 0;
        used[location] = 1;
        lastLocation = location;
    }
    printf("%d %d\n", sPeg + 1, ePeg + 1);
    for (int i = eDisk - 1; i >= sDisk; i--) {
        int location = tmp[i-sDisk];
        printf("%d %d\n", location + 1, ePeg + 1);
        tmp[i-sDisk] = location;
        used[location] = 0;
    }
}

int main() {
    int n, e, s;
    in32(n);
    in32(s);
    in32(e);
    s--;
    e--;

    out32(((n-1)*(n-1)<<1)-1);

    used = calloc(n, sizeof(int));
    stk = calloc(n, sizeof(int));
    tmp = calloc(n, sizeof(int));
    used[s] = n + 1;
    int lastDisk = 0;
    int lastIndex = 0;
    for (int i = n - 1; i >= 1; i--){
        int index = lastIndex;
        if (i == 1) {
            index = e;
        } else {
            while (used[index] || index == e) { 
                index++;
            }
        }
        move(s, index, lastDisk + 1, lastDisk + i);
        lastDisk += i;
        used[index] = i;
        lastIndex = index;
    }
    used[e] = used[s] = 0;
    for (int i = 2; i <= n - 1; i++){
        int index = 0;
        while (used[index] != i) index++;
        move(index, e, lastDisk  - i, lastDisk - 1);
        lastDisk -= i;
        used[index] = 0;
    }

    free(used);
    free(stk);
    free(tmp);
    return 0;
}