#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<string>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define INF 1<<30
#define MOD 1000000007
#define ll long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define pi acos(-1.0)
using namespace std;

// hill numbers https://www.juezguapa.com/concursos/a-series-of-fortunate-events-3/problemas/enunciado/fall-hill-numbers

const int MAXN = 100;
ll dp[MAXN][10][5];
int digit[MAXN];
char s[MAXN];
int ok(char s[])
{
    int len = strlen(s);
    int flag = 0;
    for(int i = 1; i < len; i++){
        if(s[i] > s[i-1] && flag){
            return 0;
        }
        else if(s[i] < s[i-1] && !flag){
            flag = 1;
        }
    }
    return 1;
}
ll dfs(int len,int w,int ismax,int pa)
{
    if(len == 0)return 1;
    if(!ismax && dp[len][pa][w]){
        return dp[len][pa][w];
    }
    ll ans = 0;
    ll fans = 0;
    int maxv = ismax ? digit[len] : 9;
    for(int i = 0; i <= maxv; i++){
        if(w == 1){
            if(i >= pa){
                ans += dfs(len-1,1,ismax && i == maxv,i);
            }
            else {
                ans += dfs(len-1,3,ismax && i == maxv,i);
            }
        }
        else if(w == 2){
            if(i > pa)continue;
            else {
                ans += dfs(len-1,2,ismax && i == maxv,i);
            }
        }
        else if(w == 3) {
            if(i > pa)continue;
            else {
                ans += dfs(len-1,3,ismax && i == maxv,i);
            }
        }
    }
    if(!ismax)dp[len][pa][w] = ans;
    return ans;
}
void solve()
{
    if(!ok(s)){
        printf("-1\n");
        return ;
    }
    int len = 0;
    memset(dp,0,sizeof(dp));
    for(int i = strlen(s) - 1; i >= 0; i--){
        digit[++len] = s[i] - '0';
    }
    printf("%lld\n",dfs(len,1,1,-1) - 1);
}

int main()
{
    scanf("%s",s);
    solve();
    return 0;
}
