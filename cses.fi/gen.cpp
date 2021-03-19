#include <bits/stdc++.h>

using namespace std;

vector<int> v,subset;
int n;

void sol(int k){
 if( k == 3){
  if( subset.empty() ) cout<<"vacio"<<endl;
  else{
   for(int i = 0 ; i < subset.size() ; i++) cout<<subset[i]<<" ";  // bug en la linea
   cout<<endl;
  }  
 }else{
  sol(k+1);
  subset.push_back(v[k]);
  sol(k+1);
  subset.pop_back();
 }
}
int main(){
v.push_back(1);
v.push_back(2);
v.push_back(3);
sol(0);
return 0;
}