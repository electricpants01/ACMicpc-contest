#include <bits/stdc++.h>

using namespace std;

int main(){

int g = 4;
int a,b,x;
while(cin>> a >> b >> x ){
int diff = b-a +1; // b es el max y a es el min
double r = round(double(diff)/double(x));
cout<<r<<endl;
}
return 0;
}