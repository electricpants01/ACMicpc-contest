#include <bits/stdc++.h>
using namespace std;

void multiply(long long int F[2][2], long long int M[2][2]);
void power(long long int F[2][2], long long int n);
const long long int MOD = 1e9+7;

long long int fib(long long int n)
{
    long long int F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    power(F, n - 1);

    return F[0][0];
}

void power(long long int F[2][2], long long int n)
{
    if(n == 0 || n == 1)
        return;
    long long int M[2][2] = {{1, 1}, {1, 0}};

    power(F, n / 2);
    multiply(F, F);

    if (n % 2 != 0)
        multiply(F, M);
}

void multiply(long long int F[2][2], long long int M[2][2])
{
    long long int x = ((F[0][0] * M[0][0])%MOD + (F[0][1] * M[1][0])%MOD)%MOD;
    long long int y = ((F[0][0] * M[0][1])%MOD + (F[0][1] * M[1][1])%MOD)%MOD;
    long long int z = ((F[1][0] * M[0][0])%MOD + (F[1][1] * M[1][0])%MOD)%MOD;
    long long int w = ((F[1][0] * M[0][1])%MOD + (F[1][1] * M[1][1])%MOD)%MOD;

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

int main()
{
    long long int n; cin >> n;
    cout<<fib(n);
    return 0;
}