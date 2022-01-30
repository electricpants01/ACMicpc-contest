#!/bin/env python

import sys

line = sys.stdin.readline()
[m, g, f] = [int(x) for x in line.split(' ')]

count = 0

for i in range(1, m):
    if i % f == 0 or i % g == 0:
        count += 1

print(count)
