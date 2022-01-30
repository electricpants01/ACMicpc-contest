#!/usr/bin/env python

# Jim Geist
# 8/27/2019
# Solution to 2019 UCF Local Contest Problem: Divide
#

import sys

# read all the numbers
data = [int(x) for x in ' '.join(sys.stdin.readlines()).split()]

# get the 'n' and 'd' parameters
n = data[0]
d = data[1]
data = data[2:n+2]

# compute the total problems solved
total_solved = sum(data)

# compute the award for each problem
award = d / total_solved

# write out each student's award
for solved in data:
    print(award * solved)
