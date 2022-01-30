#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323

#define EPS 9e-3

#define TRUE (1==1)
#define FALSE (!TRUE)

int eq(double, double);


int main()
{
    int length;
    int width;
    int height;
    // Read in the length and width of the bed
    scanf("%d %d", &length, &width);
    
    // Read in Anya's height
    scanf("%d", &height);
    
    int x;
    int y;
    int angle;
    
    // Read in the position of Anya's head
    scanf("%d %d", &x, &y);
    
    // Read in Anya's angle
    scanf("%d", &angle);
    
    // Find the change in position of Anya's feet
    double dx = cos(angle * PI / 180) * height;
    double dy = sin(angle * PI / 180) * height;
    
    double feetx = dx + x;
    double feety = dy + y;
    
    if ((feetx > width && !eq(feetx, width)) || 
       (feety > length && !eq (feety, length)) ||
       (feetx < 0 && !eq(feetx, 0)) ||
       (feety < 0 && !eq(feety, 0)))
    {
        
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
    }

    return 0;    
}

int eq(double a, double b)
{
    double dif = a - b;
    if (dif < 0)
        dif = -dif;
    if (dif < EPS)
        return TRUE;

    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    if (a < b)
        a = b;
    return (dif < a * EPS);
}

