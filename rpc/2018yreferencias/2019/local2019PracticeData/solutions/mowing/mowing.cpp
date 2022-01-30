// 
// See
// http://usaco.org/current/data/sol_mowing_platinum_feb19.html
// for a great derivation of the solution
//
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define MAXN 300001
#define INF 1000000000000000000LL

int N, L;
int x[MAXN], y[MAXN];
int xid[MAXN];
int lis[MAXN];
long long dp[MAXN];
long long dpPlus[MAXN];

vector<int> levels[MAXN];       //lists of points in each LIS level set

bool cmpx(int a,int b)  //assume all points have distinct x-coordinate (and y-coordinate)
{
        return x[a] < x[b];
}

void computeLIS()
{
        levels[0].push_back(xid[0]);
        lis[xid[0]] = 0;
        int mx = 0;
        for(int i=1;i<N;i++)
        {
                int cur = xid[i];
                int low = -1;
                int high = mx;
                while(low != high)
                {
                        int mid = (low+high+1)/2;
                        if(y[levels[mid].back()] < y[cur]) low = mid;
                        else high = mid-1;
                }
                levels[low+1].push_back(cur);
                mx = max(mx, low+1);
                lis[cur] = low+1;
        }
}

long long cost(int i,int j)
{
        return dp[i] + x[i]*((long long)y[i]) - x[i]*((long long)y[j]) - y[i]*((long long)x[j]) + x[j]*((long long)y[j]);
}

int findLocOvertake(int l,int i,int j) // x[i] < x[j]; when will i overtake j on level l
{
        int low = 0;
        int high = levels[l].size();
        while(low != high)
        {
                int mid = (low+high)/2;
                if(cost(i, levels[l][mid]) < cost(j, levels[l][mid])) high = mid;
                else low = mid+1;
        }
        return low;
}

int firstDom[MAXN];
int lastDom[MAXN];

int findFirst(int l,int i)      //for i in level l-1, first point in level l dominating i; -1 if none
{
        int low = 0;
        int high = levels[l].size()-1;
        while(low != high)
        {
                int mid = (low + high)/2;
                if(x[levels[l][mid]] > x[i]) high = mid;
                else low = mid+1;
        }
        if(x[levels[l][low]] > x[i] && y[levels[l][low]] > y[i])
                return low;
        return -1;
}

int findLast(int l,int i) //for i in level l-1, last point in level l dominating i; -1 if none
{
        int low = 0;
        int high = levels[l].size()-1;
        while(low != high)
        {
                int mid = (low + high + 1)/2;
                if(y[levels[l][mid]] > y[i]) low = mid;
                else high = mid-1;
        }
        if(x[levels[l][low]] > x[i] && y[levels[l][low]] > y[i])
                return low;
        return -1;
}

int que[MAXN];
int overtake[MAXN];
vector<int> level;

void solveStartingRegion(int l, int iStart, int iEnd, int qStart, int qEnd) //intervals all start in [qStart, qEnd] and end at qEnd or later
{
        int len = 0;
        int i = iStart;
        for(int j=qStart;j<=qEnd;j++)
        {
                int q = levels[l+1][j];
                while(i <= iEnd && firstDom[i] <= j)
                {
                        while(len >= 2 && overtake[len-2] <= findLocOvertake(l+1, que[len-1], level[i]))
                                len--;
                        que[len] = level[i];
                        if(len >= 1)
                                overtake[len-1] = findLocOvertake(l+1, que[len-1], level[i]);
                        len++;
                        i++;
                }
                while(len >= 2 && overtake[len-2] <= j)
                        len--;
                dp[q] = min(dp[q], cost(que[len-1], q));
        }
}

void solveEndingRegion(int l, int iStart, int iEnd, int qStart, int qEnd)       //intervals all start at qStart or before, and end in [qStart, qEnd]
{
        int len = 0;
        int i = iEnd;
        for(int j=qEnd;j>=qStart;j--)
        {
                int q = levels[l+1][j];
                while(i >= iStart && lastDom[i] >= j)
                {
                        while(len >= 2 && overtake[len-2] >= findLocOvertake(l+1, level[i], que[len-1]))
                                len--;
                        que[len] = level[i];
                        if(len >= 1)
                                overtake[len-1] = findLocOvertake(l+1, level[i], que[len-1]);
                        len++;
                        i--;
                }
                while(len >= 2 && overtake[len-2] > j)
                        len--;
                dp[q] = min(dp[q], cost(que[len-1], q));
        }
}

int main()
{
        cin >> N >> L;
        for(int i=0;i<N;i++)
                cin >> x[i] >> y[i];
        x[N] = y[N] = L;
        N++;
        for(int i=0;i<N;i++)
                dp[i] = INF, xid[i] = i;
        
        sort(xid,xid+N,cmpx);
        
        computeLIS();

        for(int i=0;i<levels[0].size();i++)
        {
                int cur = levels[0][i];
                dp[cur] = x[cur]*((long long)y[cur]);
        }
        for(int l=0;levels[l+1].size()>0;l++)
        {
                level.clear();
                for(int i=0;i<levels[l].size();i++)
                {
                        int cur = levels[l][i];
                        int fd = findFirst(l+1, cur);
                        int ld = findLast(l+1, cur);
                        if(fd != -1)    //must eliminate points in levels[l] not dominated by any points in levels[l+1]
                        {
                                firstDom[level.size()] = fd;
                                lastDom[level.size()] = ld;
                                level.push_back(levels[l][i]);
                        }
                }
                for(int i=0;i<level.size();)
                {
                        int iEnd = i;
                        while(iEnd + 1 < level.size() && firstDom[iEnd + 1] <= lastDom[i])
                                iEnd++;
                        solveStartingRegion(l, i, iEnd, firstDom[i], lastDom[i]);
                        if(lastDom[iEnd] >= lastDom[i] + 1)
                                solveEndingRegion(l, i+1, iEnd, lastDom[i] + 1, lastDom[iEnd]);
                        i = iEnd + 1;
                }
        }
        cout << dp[N-1] << '\n';
}