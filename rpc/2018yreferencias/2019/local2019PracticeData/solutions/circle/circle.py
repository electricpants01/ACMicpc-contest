import math
import sys

# Create a coordinate system with (0,0) at the center of the square. You find that the coordinate
# of the top right corner is half of this factor times the radius. To build the coordinate system,
# notice that (0,0) is the center of the diamond with side 2r, so the coordinate of the middle top
# center is (0, r(sqrt(2))). From there, draw out the equilateral triangle formed by the centers of
# the three top right circles, to notice that there's a 15 degree pitch up to get to the top right
# center circle. Finally, from there, move up and to the right by r.

factor = (2 * math.cos(15.0 / 180 * math.pi) + 1) * 2

line = sys.stdin.readline()

r = float(line.strip())
print("%.5f" % (factor*factor*r*r))
