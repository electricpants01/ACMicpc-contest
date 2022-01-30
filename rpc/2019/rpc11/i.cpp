#include <bits/stdc++.h>

using namespace std;

long long int sumPri1(vector<int> vec){
 long long int r = 0 ;
 int len = vec.size();
 for( int i = 0 ; i < len -1 ; i++){
  r += vec[i] * vec[i];
 }
 return r;
}

int main(){

 int n,d;
 vector<int> vec;
 cin>>n;
 while(n--){
  cin>>d;
  vec.push_back(d);
 }
 int len = vec.size();
 long long int pri1 =  sumPri1(vec);
 long long int pri11 = vec[len -1];
 int i = len -2;
 long long int pri2 = pri1 - (vec[i]* vec[i]);
 long long int pri22 = pri11 + vec[i];
 while ( ( pri2 * pri22 ) >= (pri1 * pri11)){
  i--;
  pri1  =  pri2;
  pri11 =  pri22;
  pri2  =  pri1 - ( vec[i] * vec[i] );
  pri22 =  pri11 + vec[i];  
 }
 long long int r = pri1 * pri11;
 cout<<r<<endl;
 return 0;
 }