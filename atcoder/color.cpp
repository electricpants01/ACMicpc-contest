#include <bits/stdc++.h>

//https://atcoder.jp/contests/abc124/tasks/abc124_c

using namespace std;


int main(){

 string cad;
 cin>>cad;
 int len = cad.length();
 bool ban;
 int sum = 0;
 ( cad[0] == '1' ) ? ban = true : ban = false;
 for(int i = 1 ; i < len ; i++){
  if(ban){
   if(cad[i] != '0') sum++;
    ban = false;
  }else{
   if(cad[i] != '1') sum++;
   ban = true;
  }
 }
 cout<<sum<<endl;
 return 0;
}