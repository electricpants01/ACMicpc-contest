
#include <stdio.h>
#include <stdlib.h>

#define in32(x) scanf("%d", &x)
#define in64(x) scanf("%lld", &x)
#define out32(x) printf("%d", (x))

typedef long long int lli;

int main() {
    lli index;
    int size;
    in32(size);
    in64(index);
    index--;
    if (size < 61 && (1ll<<(size - 1)) <= index) {
        out32(-1);
        printf("\n");
        return 0;
    }
    int i = size, st = 1, en = size;
    while (i--) {
        if (i < 62 && (index &(1ll<<(i - 1)))) {
            index ^= (1ll<<(i-1));
            out32(en--);
        } else {
            out32(st++);
        }
        printf((i==0)?"\n":" ");
    }
    return 0;
}
