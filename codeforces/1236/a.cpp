#include <bits/stdc++.h>

using namespace std;


int main(){
 vector<int> vec;
 int d; 
 int t;
 cin>>t;
 while(t--){
  int cont = 0;
  for(int i = 1 ; i<=3 ; i++){
   cin>>d;
   vec.push_back(d);
  }
//  cout<<"len del vec "<<vec.size();
  for(int i = 1 ; i >= 0 ; i--){
   while(vec[i] >= 1 && vec[i+1] >= 2){
    cont += 3;
    vec[i] = vec[i] -1;
    vec[i+1] = vec[i+1] - 2;   
   }
  }
  cout<<cont<<endl;
  vec.clear();
 }

 return 0;
}
