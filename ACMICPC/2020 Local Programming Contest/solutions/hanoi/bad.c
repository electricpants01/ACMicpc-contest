#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int LLI;
#define MAX 100000000

#define TRUE              (1==1)
#define FALSE             (!TRUE)
#define fo3(i,a,b)        for(i=((int)a);i<=((int)b);i++)
#define of3(i,a,b)        for(i=((int)a);i>=((int)b);i--)
#define in1(n)            scanf("%d",&(n))
#define LL1(n)            scanf("%I64d",&(n))
#define in2(n,m)          scanf("%d%d",&(n),&(m))
#define pri(n)            printf("%d\n",n)
#define prs(n)            printf("%s\n",n)
#define prL(n)            printf("%I64d\n",n)
#define strin(n)          scanf("%s",n)
#define newint(n)         (int*)calloc((n),sizeof(int))
#define arrint(ret,n,i)   fo3(i,1,n) in1(ret[i-1])
#define newLLI(n)         (LLI*)calloc((n),sizeof(LLI))
#define arrLLI(ret,n,i)   fo3(i,1,n) LL1(ret[i-1])

void fastWrite(FILE * ofp, int x) {
    int i = 12;
    char buff[i];
    buff[i] = 0;
    int neg = 0;
    if (x < 0){
        x = -x;
        neg = 1;
    }
    if (x == 0)
        buff[--i] = '0';
    else while (x != 0) {
        buff[--i] = (x % 10) + '0';
        x /= 10;
    }
    if (neg)
        buff[--i] = '-';
    fwrite(buff + i, sizeof(char), (12 - i), ofp);
}

void fastSpace(FILE * ofp){
    fwrite(" ", sizeof(char), 1, ofp);
}
void fastNewLine(FILE * ofp) {
    fwrite("\n", sizeof(char), 1, ofp);
}
void fastA(FILE * ofp) {
    fwrite("AAAA", sizeof(char), 4, ofp);
}


int main(void) {
    for (int i = 0; i < MAX; i++)
        fastA(stdout);
    return 0;
} 