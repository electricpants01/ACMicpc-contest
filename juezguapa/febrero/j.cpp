#include <bits/stdc++.h>
using namespace std;
#define mod 11092019

int main(){
string cad;
int r = 1;
cin>>cad;
int len = cad.length();
cout<<"len es : "<<len<<endl;
for(int i = 1 ; i <= len ; i++){
 r = (r*i) % mod;  
}
cout<<r<<endl;
return 0;
}