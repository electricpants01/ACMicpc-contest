// Arup Guha
// 8/15/2019
// C++ Solution to 2019 UCF Locals Problem: Fitting on the Bed

#include <iostream>
#include <math.h>

// Different than a normal epsilon, but gives us plenty of tolerance as the data spec allows.
#define EPS 0.001

using namespace std;

int main() {

    // Get bed and Anya sizes.
    int bedLength, bedWidth, anyaHeight;
    cin >> bedLength >> bedWidth >> anyaHeight;

    // Get Anya's location and orientation.
    int x, y, angle;
    cin >> x >> y >> angle;
    double angleRad = angle*acos(-1)/180;

    // This is where Anya's feet are.
    double feetX = x + anyaHeight*cos(angleRad);
    double feetY = y + anyaHeight*sin(angleRad);

    // Since we're dealing with a rectangle, we can just check her feet.
    if (feetX > -EPS && feetX < bedWidth+EPS && feetY > -EPS && feetY < bedLength+EPS)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
