#include <bits/stdc++.h>

using namespace std;


int main(){

 set<string> vec;
 int d; 
 cin>>d;
 while(d--){
 string f;
 cin>>f;
 vec.insert(f);
} 
 int len = vec.size();
 for( set<int>::iterator it = vec.begin(); it != vec.end(); it++){
  cout<<*it<<" ";
 } 

 return 0;
}