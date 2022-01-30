#include <bits/stdc++.h>
using namespace std;

int main(){

int bedHeight,bedWidth,altura;
cin >> bedHeight >> bedWidth >> altura;
int x,y,a;
cin >> x >> y >> a;
double anglerad = (a)*acos(-1)/180;
double feetX = altura*cos(anglerad) + x;
double feetY = altura*sin(anglerad) + y;
if( feetX >= 0 && feetX <= bedWidth && feetY >= 0 && feetY < bedHeight ) cout<<"YES\n";
else cout<<"NO\n";
return 0;
}
