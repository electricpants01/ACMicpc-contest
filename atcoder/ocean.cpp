#include <bits/stdc++.h>
//https://atcoder.jp/contests/abc124/tasks/abc124_b
using namespace std;

int main(){

 int n,a ;
 vector<int> vec;
 cin>>n;
 for(int i = 0 ; i < n ; i++){
 cin>>a;
 vec.push_back(a);
 }
 int sum = 0 ;
 int may ; 
 (vec[0] > vec[1]) ? may = vec[0] : may = vec[1];
 for(int i = 1 ; i < n ; i++){
 if(may <= vec[i]){
  sum++;
  may = vec[i];
  }  
 }
 cout<<sum+1<<endl; 
 return 0; 
 }