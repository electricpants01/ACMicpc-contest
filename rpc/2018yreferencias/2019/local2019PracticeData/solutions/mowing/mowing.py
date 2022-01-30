#!/usr/bin/env python

# Jim Geist
# 8/7/2019
# Solution to 2019 UCF Practice Local Contest Problem: Mowing
#
# Based on
# http://usaco.org/current/data/sol_mowing_platinum_feb19.html
#

import sys

INFINITY = 1000000000000000000

def computeLIS():
    levels[0].append(xid[0])
    lis[xid[0]] = 0
    mx = 0

    for i in range(1, N):
        cur = xid[i]
        low = -1
        high = mx
        while low != high:
            mid = (low + high + 1) // 2
            if y[levels[mid][-1]] < y[cur]:
                low = mid
            else:
                high = mid - 1

        levels[low + 1].append(cur)
        mx = max(mx, low + 1)
        lis[cur] = low + 1

def cost(i, j):
    return dp[i] + x[i] * y[i] - x[i] * y[j] - x[j] * y[i] + x[j] * y[j]

def find_loc_overtake(l, i, j):   # x[i] < x[j]; when will i overtake j on level l
    low = 0
    high = len(levels[l])

    while low != high:
        mid = (low + high) // 2
        if cost(i, levels[l][mid]) < cost(j, levels[l][mid]):
            high = mid
        else:
            low = mid + 1

    return low


# for i in level l-1, first point in level l dominating i; -1 if none
def find_first(l, i):
    low = 0
    high = len(levels[l]) - 1

    while low != high:
        mid = (low + high) // 2
        if x[levels[l][mid]] > x[i]:
            high = mid
        else:
            low = mid + 1

    if x[levels[l][low]] > x[i] and y[levels[l][low]] > y[i]:
        return low

    return -1

# for i in level l-1, last point in level l dominating i; -1 if none
def find_last(l, i):
    low = 0
    high = len(levels[l]) - 1

    while low != high:
        mid = (low + high + 1) // 2
        if y[levels[l][mid]] > y[i]:
            low = mid
        else:
            high = mid - 1

    if x[levels[l][low]] > x[i] and y[levels[l][low]] > y[i]:
        return low

    return -1

# intervals all start in [qStart, qEnd] and end at qEnd or later
def solve_starting_region(l, istart, iend, qstart, qend):
    length = 0
    i = istart
    for j in range(qstart, qend+1):
        q = levels[l+1][j]

        while i <= iend and firstdom[i] <= j:
            while length >= 2 and overtake[length - 2] <= find_loc_overtake(l + 1, que[length - 1], level[i]):
                length -= 1
            que[length] = level[i]
            if length >= 1:
                overtake[length-1] = find_loc_overtake(l + 1, que[length - 1], level[i])
            length += 1
            i += 1

        while length >= 2 and overtake[length - 2] <= j:
            length -= 1

        dp[q] = min(dp[q], cost(que[length - 1], q))

# intervals all start at qStart or before, and end in [qStart, qEnd]
def solve_ending_region(l, istart, iend, qstart, qend):
    length = 0
    i = iend
    for j in range(qend, qstart-1, -1):
        q = levels[l+1][j]

        while i >= istart and lastdom[i] >= j:
            while length >= 2 and overtake[length - 2] >= find_loc_overtake(l + 1, level[i], que[length - 1]):
                length -= 1
            que[length] = level[i]
            if length >= 1:
                overtake[length - 1] = find_loc_overtake(l + 1, level[i], que[length - 1])
            length += 1
            i -= 1

        while length >= 2 and overtake[length - 2] > j:
            length -= 1

        dp[q] = min(dp[q], cost(que[length - 1], q))

def main():
    global L, N, x, y
    global xid
    global dp
    global lis
    global levels
    global level
    global firstdom, lastdom
    global que
    global overtake

    data = [int(s) for s in sys.stdin.read().split()]
    N = data[0]
    L = data[1]

    data = data[2:]
    x = [data[2*i] for i in range(0, N)] + [L]
    y = [data[2*i+1] for i in range(0, N)] + [L]

    N += 1

    xid = list(zip(range(0, len(x)), x))
    xid.sort(key=lambda x:x[1])
    xid = [x[0] for x in xid]

    dp = N * [INFINITY]
    lis = N * [0]
    firstdom = N * [0]
    lastdom = N * [0]
    que = N * [0]
    overtake = N * [0]
    levels = []
    for i in range(0, N):
        levels += [[]]

    computeLIS()

    for i in range(0, len(levels[0])):
        cur = levels[0][i]
        dp[cur] = x[cur] * y[cur]

    l = 0
    while len(levels[l+1]) > 0:
        level = []
        for i in range(0, len(levels[l])):
            cur = levels[l][i]
            fd = find_first(l + 1, cur)
            ld = find_last(l + 1, cur)
            if fd != -1:  # must eliminate points in levels[l] not dominated by any points in levels[l+1]
                firstdom[len(level)] = fd
                lastdom[len(level)] = ld
                level.append(levels[l][i])

        i = 0
        while i < len(level):
            iend = i
            while iend + 1 < len(level) and firstdom[iend + 1] <= lastdom[i]:
                iend += 1

            solve_starting_region(l, i, iend, firstdom[i], lastdom[i])
            if lastdom[iend] >= lastdom[i] + 1:
                solve_ending_region(l, i + 1, iend, lastdom[i] + 1, lastdom[iend])

            i = iend + 1


        l += 1

    print(dp[N-1])

main()



