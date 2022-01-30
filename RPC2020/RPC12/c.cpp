#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int mxN = 1e3;
int dp[mxN][mxN];


int main() {
    int minu,seg;
    char colon;
    scanf("%2d %1c %2d",&minu, &colon, &seg);
    int donald_time = (60*minu) + seg;
    int total = (3600* minu) + (60*seg);
    int final = total - donald_time; //manejar todo en segundos, para hacer mas secillo el calculo
    int extra_hour = final / 3600;
    final %= 3600;
    int extra_minute = final / 60;
    int extra_seconds = final % 60;
    printf("%02d:%02d:%02d\n",extra_hour,extra_minute,extra_seconds);
    return 0;
}