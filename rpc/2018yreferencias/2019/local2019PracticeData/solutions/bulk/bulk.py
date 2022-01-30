#!/bin/env python

import sys

line = sys.stdin.readline()
[c, p] = [int(x) for x in line.split(' ')]

total = p
for i in range(1, c):
    total += p-2

print(total)
