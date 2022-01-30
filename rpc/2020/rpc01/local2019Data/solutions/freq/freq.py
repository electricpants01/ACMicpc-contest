#!/usr/bin/env python

# Jim Geist
# 8/27/2019
# Solution to 2019 UCF Local Contest Problem: Freq
#

import sys

# read the line
line = sys.stdin.readline().strip()

alpha = 'abcdefghijklmnopqrstuvwxyz'

# convert line to indices
line = [alpha.find(x) for x in line]

# count the letter occurances
counts = len(alpha) * [0]
for ch in line:
    counts[ch] += 1

output = ''
while True:
    max = 0
    maxIndex = -1

    # look through the counts array for the highest value. note that
    # we only move to a new max if there's an increase. since the array
    # indexes are alphabetical, this means we get the alphabetic sorting
    # of equal counted letters for free.
    #
    for i in range(0, len(counts)):
        if counts[i] > max:
            max = counts[i]
            maxIndex = i

    # if all the counts are zero, we're done.
    #
    if max == 0:
        break

    # save some repeated letters.
    #
    for i in range(0, counts[maxIndex]):
        output += alpha[maxIndex]

    # remove the count we just consumed
    #
    counts[maxIndex] = 0

print(output)

