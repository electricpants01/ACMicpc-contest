
#include <stdio.h>
#include <stdlib.h>

typedef long long int lli;
typedef long double doub;

#define MAX 100000
#define TRUE (1==1)
#define oo 1100000000

int n;
lli w;
lli hs[MAX + 4];
lli xs[MAX + 4];

#define EPS 1e-8

doub comp();
void flip();
doub turn(int, int);
doub comp2(int, doub, doub);
doub compHeight(int, doub);
int    eq(doub, doub);

int main()
{
    int i;
    
    // Read in input
    scanf("%d %lld", &n, &w);
    for (i = 0; i < n; i++)
    {
        scanf("%lld %lld", &xs[i + 2], &hs[i + 2]);
    }
    n += 4;
    hs[0] = 0;
    hs[1] = 0;
    hs[n-2] = 0;
    hs[n-1] = 0;

    xs[0] = -oo;
    xs[1] = xs[2];
    xs[n-2] = xs[n-3];
    xs[n-1] = oo;


    // Compute a possible max
    doub max = comp();

    // Flip and recompute the max
    flip();
    doub max2 = comp();

    // Update if the other answer is better
    if (max < max2)
    {
        max = max2;
    }

    // Print the Answer
    printf("%0.010Lf\n", max);

    // Return a zero
    return 0;
}


// Computes the max area trying all possible starting traps
doub comp()
{
    doub ret;
    doub cur;
    doub tAns;
    int bptr;
    int i;

    ret = 0.0;
    cur = 0.0;
    bptr = 1;

    for (i = 1; i < n; i++)
    {
        // Loop until we cover a maximal amount of Traps
        while (bptr + 1 < n && xs[bptr + 1] - xs[i] <= w)
        {
            // Add area of Trap
            cur += comp2(bptr, xs[bptr], xs[bptr + 1]);
            
            // Update pointer
            bptr++;
        }
        
        // Try to stretch the view across one extra trapazoid
        tAns = cur + turn(i-1,bptr);
        if (tAns > ret)
            ret = tAns;

        // Remove the front trapazoid
        cur -= comp2(i, xs[i], xs[i+1]);
       
        // Figure out a possible answer
        tAns = cur + turn(i,bptr); 

        // Check if the possible answer is better
        if (tAns > ret)
        {
            ret = tAns;
        }

        // probably not necessary
        /*
        tAns = turn(i-1, i);
        if (tAns > ret)
        {
            ret = tAns;
        }
        */
    }

    // Return the found answer
    return ret / w;
}


// Turnary search for the ends within two given traps (by index)
//    index 1   s
//    index 2   e
doub turn(int s, int e)
{
    doub a1, a2, mid1, mid2;
    doub hi, lo;
    
    // Trap completely within one Trap case
    if (s == e)
    {
        doub a1 = comp2(s, xs[s], xs[s] + w);
        doub a2 = comp2(s, xs[s + 1] - w, xs[s + 1]);
        if (a1 < a2)
        {
            a1 = a2;
        }
        return a1 + comp2(s, xs[s], xs[s+1]);
    }

    mid1 = 0;
    hi = xs[e + 1] - xs[s] - w;
    if (hi + xs[s] > xs[s + 1])
        hi = xs[s + 1] - xs[s];
    lo = 0;
    if (lo < xs[e] - w - xs[s])
        lo = xs[e] - w - xs[s];
    a1 = comp2(s, xs[s] + lo, xs[s+1]) +
        comp2(e, xs[e], xs[s] + w + lo);

    while (!eq(hi, lo))
    {
        if (hi < lo)
            return 0;
        mid1 = (hi * 7 + lo * 8) / 15;
        mid2 = (hi * 8 + lo * 7) / 15;

        a1 = comp2(s, xs[s] + mid1, xs[s+1]) + 
            comp2(e, xs[e], xs[s] + mid1 + w);
        a2 = comp2(s, xs[s] + mid2, xs[s+1]) + 
            comp2(e, xs[e], xs[s] + mid2 + w);
        if (a1 > a2)
        {
            hi = mid2;
        }
        else
        {
            lo = mid1;
        }
    }

    return a1;
}


// Compute the height of a Trap
//    @ trap index    ind
//    w/ starting x   s 
//    w/ ending x     e
doub comp2(int ind, doub s, doub e)
{
    doub hSt = compHeight(ind, s);
    doub hEn = compHeight(ind, e);
    return ((e - s) * (doub) (hEn + hSt)) / 2;
}


// Computes the height of the mountain range
//     @ trap index    ind
//     w/ x position   pos
doub compHeight(int ind, doub pos)
{
    if (eq(xs[ind+1], xs[ind])){
        return hs[ind+1];
    }

    doub rate = (hs[ind + 1] - hs[ind]) / (doub) (xs[ind + 1] - xs[ind]);
    return hs[ind] + rate * (pos - xs[ind]);
}


// Flip all the values in the x direction
// Maintain the sortedness by negating x's
void flip()
{
    int i, j;
    for (i = 0, j = n - 1; i < j; i++, j--)
    {
        // Swap front and back values
        hs[i] ^= hs[j];
        hs[j] ^= hs[i];
        hs[i] ^= hs[j];
        xs[i] ^= xs[j];
        xs[j] ^= xs[i];
        xs[i] ^= xs[j];
    }

    // Invert the xs
    for (i = 0; i < n; i++)
    {
        xs[i] = -xs[i];
    }
}


// Relative and absolute value checker
int eq(doub a, doub b)
{
    doub dif = a - b;
    if (dif < 0)
        dif = -dif;

    // Absolute error check
    if (dif < EPS)
        return TRUE;

    // Get the maximum absolute value
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    if (a < b)
        a = b;
    
    // Relative error check
    return (a * EPS > dif);
}

