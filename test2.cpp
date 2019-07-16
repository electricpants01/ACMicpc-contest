#include <bits/stdc++.h>

using namespace std;


int main(){
 int vec[] = {1,2,5,10,20,100,200,500};
 int i = sizeof(vec)/sizeof(int) -1 ;
 int d;
 cin>>d;
 while( d != 0){
  if( vec[i] <= d ){
   d -= vec[i];
   cout<<vec[i]<<" ";
  }else i--;
 }
// cout<<i<<endl;
 return 0;
}