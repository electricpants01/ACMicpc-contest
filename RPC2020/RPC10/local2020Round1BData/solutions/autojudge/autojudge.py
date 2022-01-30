# This is Python3 but I don't remember if we are supposed to omit the hashbang
#!/usr/bin/env python3
from __future__ import print_function
import sys

def eprint(*args, **kwargs):
    print("DEBUG: ", *args, file=sys.stderr, **kwargs)

# The first two lines of input are the problem filename (which is a
# stem, really, with no extension) and the full submitted filename.
probfilename = input()
subfilename = input()

# Since the submitted file must have a language extension, it must
# also contain a dot separator.
if not "." in subfilename:
    print("Compile Error")
    exit(0)

# We want to check the base or step of the submitted filename
# separately from checking its extension
subfilenameparts = subfilename.split(".")
if len(subfilenameparts) != 2:
    print("Compile Error")
    exit(0)

subfilenamebase = subfilenameparts[0];
subfilenameext = subfilenameparts[-1];

if subfilenamebase != probfilename:
    print("Compile Error")
    exit(0)

# The extenstion must be exactly one of the permitted ones.
if not subfilenameext in set(['c', 'cpp', 'java', 'py']):
    print("Compile Error")
    exit(0)

# No compile errors, so go back to reading the next input line.
retcode, duration, elapsed = map(int,input().split())

# A non-zero return code is a run-time error.
if retcode:
    print("Run-Time Error")
    exit(0)

# Elapsed time greater than the allotted run duration?
if elapsed > duration:
    print("Time Limit Exceeded")
    exit(0)

# Looks like the program ran to completion in time, so now we can look
# at the output. First read all the output for a correct program.
ncorrectlines = int(input())

# Read the correct lines into a string array
correct = []
for i in range(0, ncorrectlines):
    correct.append(input())

# Check the number of output lines from the submission. If it does
# not match, then the outputs cannot possibly match.
nsubmitlines = int(input())
if nsubmitlines is not ncorrectlines:
    print("Wrong Answer")
    exit(0)

# Read each submission output line and check against the corresponding
# correct output line
for i in range(0, ncorrectlines):
    submit = input()
    if submit != correct[i]:
        print("Wrong Answer")
        exit(0)

# If we reach here, the outputs matched completely
print("Correct")

