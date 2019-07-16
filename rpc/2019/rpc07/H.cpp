#include <bits/stdc++.h>


using namespace std;


int main(){
 
 double slice,p1,p2,radio;
 cin>>slice;
 cin>>p1;
 cin>>radio;
 cin>>p2;
 double area = (M_PI * radio* radio)/p2;
 if( area > slice/p1 ) cout<<"Whole pizza"<<"\n";
 else cout<<"Slice of pizza"<<"\n";
 return 0;
}