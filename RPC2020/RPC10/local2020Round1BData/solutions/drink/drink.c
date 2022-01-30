
#include <stdlib.h>
#include <stdio.h> // for scanfs and printfs

// A short hand for 64 bit integers
typedef long long int lli;
typedef struct vec3 vec3;

struct vec3 {
    lli x, y, z;
}; 

// Macro for reading in integers and printing doubles
#define in64(x) scanf("%lld", &x)
#define out64f(x) printf("%.07lf\n", x)

// Min, max, and abs macros
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ABS(a)   (((a)>0)?(a):(-(a)))

// Cross product
void cross(vec3 * res, vec3 a, vec3 b) { 
    res->x = (a.y * b.z) - (b.y * a.z);
    res->y = (a.z * b.x) - (b.z * a.x);
    res->z = (a.x * b.y) - (b.x * a.y);
}

int between(vec3 mid, vec3 a, vec3 b) {
    if (a.x * b.z > b.x * a.z) return between(mid, b, a);
    return (a.x * mid.z <= a.z * mid.x) && (b.x * mid.z >= b.z * mid.x);
}

int main() {
    vec3 line1_p1;
    vec3 line1_p2;
    vec3 line2_p1;
    vec3 line2_p2;
    
    // Read line 1
    in64(line1_p1.x);
    in64(line1_p1.y);
    line1_p1.z = 1;
    in64(line1_p2.x);
    in64(line1_p2.y);
    line1_p2.z = 1;

    // Read line 2
    in64(line2_p1.x);
    in64(line2_p1.y);
    line2_p1.z = 1;
    in64(line2_p2.x);
    in64(line2_p2.y);
    line2_p2.z = 1;

    // Dual line point property is used to find the line going through 2 points
    // Find a*x + b*y + c*1 = 0 that works for both points using cross product
    vec3 line1;
    cross(&line1, line1_p1, line1_p2);
    vec3 line2;
    cross(&line2, line2_p1, line2_p2);

    // Cross the two lines to find the intersection again using Dual line
    // point properties
    vec3 intersection;
    cross(&intersection, line1, line2);

    // Check if intersection is outside either line segment
    if (!between(intersection, line1_p1, line1_p2) ||
            !between(intersection, line2_p1, line2_p2)) {
        out64f(0.0);
        return 0;
    }

    // Find the height
    lli minY = MIN(MAX(line1_p1.y, line1_p2.y), MAX(line2_p1.y, line2_p2.y));
    lli hNumerator = minY * intersection.z - 1 * intersection.y;
    lli hDenominator = 1 * intersection.z;

    // Find the x intersection locations on both lines
    // Make a horizontal line that is at the top of the water level
    vec3 hline_p1, hline_p2, hline, start, end;
    hline_p1.x = 0;
    hline_p1.y = minY;
    hline_p1.z = 1;
    hline_p2.x = 1;
    hline_p2.y = minY;
    hline_p2.z = 1;

    // Get the dual line using the cross product
    cross(&hline, hline_p1, hline_p2);

    // Find the two points
    cross(&start, hline, line1);
    cross(&end, hline, line2);

    // figure out the distance between the two points (start and end)
    lli bNumerator = start.x * end.z - start.z * end.x;
    lli bDenominator = start.z * end.z;
    bNumerator = ABS(bNumerator);
    bDenominator = ABS(bDenominator);

    // Computer the answer as a fraction
    lli ansNum = bNumerator * hNumerator;
    lli ansDen = bDenominator * hDenominator * 2;
    double ans = ansNum;
    ans /= ansDen;
    out64f(ans);

    // End the program
    return 0;
}