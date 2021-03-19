#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct P{
    int x,y;
    void read(){
        cin >> x >> y;
    }
    P operator -(const P& b){
        return P{x - b.x, y - b.y};
    }
    void operator -=(const P& b){
        x -= b.x;
        y -= b.y;
    }
    long long operator *(const P& b){
     return (long long ) x * b.y - (long long)y * b.x;
    }
};

int main(){
ios::sync_with_stdio(0); cin.tie(0);
cout << setprecision(12)<<fixed;
int t; cin >> t;
while(t--){
    P p1, p2, p3;
    p1.read();
    p2.read();
    p3.read();
    p2 -= p1;
    p3 -= p1;
    //x2 * y3 - y2 * x3 < 0 -> first point is more to the left
    long long ans = p2 * p3;
    if( ans < 0){
        // P2 on the left from P3
        cout<<"RIGHT\n";
    }
    else if( ans > 0){
        cout<<"LEFT\n";
    }
    else cout<<"TOUCH\n";
}
return 0;
}
