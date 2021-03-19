#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){

 ll n; cin >> n;
 bool ban = false;
 if( n % 4 == 0) ban = true;
 if( n % 100 == 0) ban = false;
 if( n % 400 == 0) ban = true;
 if(ban){
    cout<<"SI\n";
 }else{
     cout<<"NO\n"<<endl;
 }
 return 0;
}
