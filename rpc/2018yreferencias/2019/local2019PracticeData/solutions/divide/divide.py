#!/usr/bin/env python

# Jim Geist
# 8/15/2019
# Solution to 2019 UCF Practice Local Contest Problem: Divide
#

import sys

def main():
    data = [int(s) for s in sys.stdin.read().split()]
    t = data[0]
    s = data[1]
    data = data[2:]

    # DP: key is track #, value is best # button presses to get there so far   
    # initial condition: we start at track 't' because it takes zero pushes
    # to get to track 0 
    memo = {t: 0}

    # for each choice set, compute the best possible song based on the
    # previous set
    for i in range(0, s):
        nchoices = data[0]
        choices = data[1:1+nchoices]
        data = data[1+nchoices:]
        
        nextMemo = {}
        for dest in choices:
            best = None
            for src in memo.keys():
                sofar = memo[src]
                src = (src + 1) % t
                # best strategy might be forward or backward button
                fwd = abs(dest - src)
                bwd = t - fwd 
                presses = sofar + min(fwd, bwd)
                if best == None or presses < best:
                    best = presses
            nextMemo[dest] = best
        memo = nextMemo

    print(min(memo.values()))

main()
