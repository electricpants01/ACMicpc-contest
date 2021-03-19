#include <bits/stdc++.h>



using namespace std;

void mostrar(vector<pair<int,int> >vec){
 int len = vec.size();
 for(auto x : vec){
  cout<<x.first<<" "<<x.second<<endl;
 }
 cout<<endl;
}

int main(){
 
 vector<pair<int,int> > vec;
 cout<<"numero de pares : ";
 int n;
 cin>>n;
 for(int i = 0 ; i < n ; i++){
  int a,b;
  cin>>a;
  cin>>b;
  vec.push_back(make_pair(a,b));
 } 
 mostrar(vec);
 return 0;
}