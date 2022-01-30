#include <cstdio>
#include <cmath>

const double PI = 3.14159265358979;

int main()
{
    double xc, yc, rad, lower, upper;

    scanf("%lf %lf %lf %lf %lf", &xc, &yc, &rad, &lower, &upper);

    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int flt;
        double xa, ya, head, alt, speed, descent;
        scanf("%d %lf %lf %lf %lf %lf %lf", &flt, &xa, &ya, &head, &alt, &speed, &descent);

        head *= PI / 180.0;

        // vector heading of the plane in the x-y plane
        //
        double dx = cos(head);
        double dy = sin(head);

        // we have the parametric equation of a ray
        // x = xa + t*dx, y = ya + t*dy giving the position of the aircraft
        // plugging this into a cross section of the cylinder in the x-y plane
        // (a circle with equation (x-xc)^2 + (y-yc)^2 = r^2) gives a quadratic
        // equation.
        //
        double xac = xa - xc;
        double yac = ya - yc;
        double b = 2 * (xac * dx + yac * dy);
        double c = (xa-xc) * (xa-xc) + (ya-yc) * (ya-yc) - rad*rad;
        double disc = b*b - 4*c;

        bool entered = false, exited = false;
        double tenter = -2, texit = -2;
        double aenter, aexit;
        
        if (disc > 0) {
            double t0 = (-b - sqrt(disc)) / 2;
            double t1 = (-b + sqrt(disc)) / 2;
            
            double theta = asin(descent / speed);
            double l0 = t0 / cos(theta);
            double l1 = t1 / cos(theta);

            t0 = l0 / speed;
            t1 = l1 / speed;
            aenter = alt - t0 * descent;
            aexit = alt - t1 * descent;

            if (aenter >= lower && aenter <= upper && t0 >= 0) {
                entered = true;
                tenter = t0;
            } 
            if (aexit >= lower && aexit <= upper && t1 >= 0) {
                exited = true;
                texit = t1;
            }
        }


        if (alt > upper) {
            double z = alt - upper;
            double theta = acos(descent / speed);
            double l = z * tan(theta);
            double x = xa + l * dx;
            double y = ya + l * dy;
            double xxc = x - xc;
            double yyc = y - yc;

            if (xxc * xxc + yyc * yyc < rad * rad + 1e-6) {
                double t = sqrt(l*dx*l*dx + l*dy*l*dy + z*z) / speed;
                if (t >= -1e-6 && (!entered || t < tenter)) {
                    entered = true;
                    tenter = t;
                    aenter = upper;
                }
            }
        }

        if (alt > lower) {
            double z = alt - lower;
            double theta = acos(descent / speed);
            double l = z * tan(theta);
            double x = xa + l * dx;
            double y = ya + l * dy;
            double xxc = x - xc;
            double yyc = y - yc;

            if (xxc * xxc + yyc * yyc < rad * rad + 1e-6) {
                double t = sqrt(l*dx*l*dx + l*dy*l*dy + z*z) / speed;
                if (t >= -1e-6 && (!exited || t < texit)) {
                    exited = true;
                    texit = t;
                    aexit = lower;
                }
            }
        }

        if (entered) {
            printf("Incoming! Flight %d enters at %.2lf and exits at %.2lf.\n", flt, tenter, texit);
        } else {
            printf("Flight %d is safe.\n", flt);
        }
    }
}
    
