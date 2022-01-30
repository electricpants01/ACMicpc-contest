#include <bits/stdc++.h>


using namespace std;


int main(){

 long long int r,w,h,d;
 cin>>w;
 cin>>h;
 cin>>d;
 w = w - 2 * d;
 h = h - 2 * d;
 if(w < 0 || h < 0 ) r = 0;
 else r = w * h;
 cout<<r<<endl;
 return 0;
}