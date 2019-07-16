#include <iostream>
#include <string>
using namespace std;
class A {
public:
int x;
};
class B : public A {
public:
B() { x=1;}
B(int x) {this->x = x;}
};
int main () {
B c1;
B c2(10);
cout << c1.x<<endl;
cout << c2.x<<endl;
return 0;
}